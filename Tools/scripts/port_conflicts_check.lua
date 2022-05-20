#!/usr/libexec/flua

--[[
SPDX-License-Identifier: BSD-2-Clause-FreeBSD

Copyright (c) 2022 Stefan Esser <se@FreeBSD.org>

Generate a list of existing and required CONFLICTS_INSTALL lines
for all ports (limited to ports for which official packages are
provided).

This script depends on the ports-mgmt/pkg-provides port for the list
of files installed by all pre-built packages for the architecture
the script is run on.

The script generates a list of ports by running "pkg provides ." and
a mapping from package base name to origin via "pkg rquery '%n %o'".

The existing CONFLICTS and CONFLICTS_INSTALL definitions are fetched
by "make -C $origin -V CONFLICTS -V CONFLICTS_INSTALL". This list is
only representative for the options configured for each port (i.e.
if non-default options have been selected and registered, these may
lead to a non-default list of conflicts).

The script detects files used by more than one port, than lists by
origin the existing definition and the list of package base names
that have been detected to cause install conflicts followed by the
list of duplicate files separated by a hash character "#".

This script uses the "hidden" LUA interpreter in the FreeBSD base
systems and does not need any port except "pkg-provides" to be run.

The run-time on my system checking the ~32000 packages available
for -CURRENT on amd64 is less than 250 seconds.

Example output:

# Port:  games/sol
# Files: bin/sol
# <      aisleriot gnome-games
# >      aisleriot
portedit merge -ie 'CONFLICTS_INSTALL=aisleriot # bin/sol' /usr/ports/games/sol

The output is per port (for all flavors of the port, if applicable),
gives examples of conflicting files (mostly to understand whether
different versions of a port could co-exist), the current CONFLICTS
and CONFLICTS_INSTALL entries merged, and a suggested new entry.
This information is followed by a portedit command line that should
do the right thing for simple cases, but the result should always
be checked before the resulting Makefile is committed.
--]]

require "lfs"

-------------------------------------------------------------------
local file_pattern = "."
local database = "/var/db/pkg/provides/provides.db"

-------------------------------------------------------------------
local function table_sorted_keys(t)
   local result = {}
   for k, _ in pairs(t) do
      result[#result + 1] = k
   end
   table.sort(result)
   return result
end

-------------------------------------------------------------------
local function table_sort_uniq(t)
   local result = {}
   if t then
      local last
      table.sort(t)
      for _, entry in ipairs(t) do
         if entry ~= last then
            last = entry
            result[#result + 1] = entry
         end
      end
   end
   return result
end

-------------------------------------------------------------------
local function fnmatch(name, pattern)
   local function fnsubst(s)
      s = string.gsub(s, "%%", "%%%%")
      s = string.gsub(s, "%+", "%%+")
      s = string.gsub(s, "%-", "%%-")
      s = string.gsub(s, "%.", "%%.")
      s = string.gsub(s, "%?", ".")
      s = string.gsub(s, "%*", ".*")
      return s
   end
   local rexpr = ""
   local left, middle, right
   while true do
      left, middle, right = string.match(pattern, "([^[]*)(%[[^]]+%])(.*)")
      if not left then
         break
      end
      rexpr = rexpr .. fnsubst(left) .. middle
      pattern = right
   end
   rexpr = "^" .. rexpr .. fnsubst(pattern) .. "$"
   return string.find(name, rexpr)
end

-------------------------------------------------------------------
local function fetch_pkgs_origins()
   local pkgs = {}
   local pipe = io.popen("pkg rquery '%n %o'")
   for line in pipe:lines() do
      local pkgbase, origin = string.match(line, "(%S+) (%S+)")
      pkgs[origin] = pkgbase
   end
   pipe:close()
   pipe = io.popen("pkg rquery '%n %o %At %Av'")
   for line in pipe:lines() do
      local pkgbase, origin, tag, value = string.match(line, "(%S+) (%S+) (%S+) (%S+)")
      if tag == "flavor" then
         pkgs[origin] = nil
         pkgs[origin .. "@" .. value] = pkgbase
      end
   end
   pipe:close()
   return pkgs
end

-------------------------------------------------------------------
local BAD_FILE_PATTERN = {
   "^[^/]+$",
   "^lib/python[%d%.]+/site%-packages/examples/[^/]+$",
   "^lib/python[%d%.]+/site%-packages/samples/[^/]+$",
   "^lib/python[%d%.]+/site%-packages/test/[^/]+$",
   "^lib/python[%d%.]+/site%-packages/test_app/[^/]+$",
   "^lib/python[%d%.]+/site%-packages/tests/[^/]+$",
   "^lib/python[%d%.]+/site%-packages/tests/unit/[^/]+$",
}

local BAD_FILE_PKGS = {}

local function check_bad_file(pkgbase, file)
   for _, pattern in ipairs(BAD_FILE_PATTERN) do
      if string.match(file, pattern) then
         BAD_FILE_PKGS[pkgbase] = BAD_FILE_PKGS[pkgbase] or {}
         table.insert(BAD_FILE_PKGS[pkgbase], file)
         break
      end
   end
end

-------------------------------------------------------------------
local function read_files(pattern)
   local files_table = {}
   local pipe = io.popen("locate -d " .. database .. " " .. pattern)
   if pipe then
      for line in pipe:lines() do
         local pkgbase, file = string.match(line, "([^*]+)%*([^*]+)")
         if file:sub(1, 11) == "/usr/local/" then
            file = file:sub(12)
         end
         check_bad_file(pkgbase, file)
         local t = files_table[file] or {}
         t[#t + 1] = pkgbase
         files_table[file] = t
      end
      pipe:close()
   end
   return files_table
end

-------------------------------------------------------------------
local DUPLICATE_FILE = {}

local function fetch_pkg_pairs(pattern)
   local pkg_pairs = {}
   for file, pkgbases in pairs(read_files(pattern)) do
      if #pkgbases >= 2 then
         DUPLICATE_FILE[file] = true
         for i = 1, #pkgbases -1 do
            local pkg_i = pkgbases[i]
            for j = i + 1, #pkgbases do
               local pkg_j = pkgbases[j]
               if pkg_i ~= pkg_j then
                  local p1 = pkg_pairs[pkg_i] or {}
                  local p2 = p1[pkg_j] or {}
                  p2[#p2 + 1] = file
                  p1[pkg_j] = p2
                  pkg_pairs[pkg_i] = p1
               end
            end
         end
      end
   end
   return pkg_pairs
end

-------------------------------------------------------------------
local function conflicts_delta(old, new)
   local old_seen = {}
   local changed
   for i = 1, #new do
      local matched
      for j = 1, #old do
         if new[i] == old[j] or fnmatch(new[i], old[j]) then
            new[i] = old[j]
            old_seen[j] = true
            matched = true
            break
         end
      end
      changed = changed or not matched
   end
   if not changed then
      for j = 1, #old do
         if not old_seen[j] then
            changed = true
            break
         end
      end
   end
   if changed then
      return table_sort_uniq(new)
   end
end

-------------------------------------------------------------------
local function fetch_port_conflicts(origin)
   local dir, flavor = origin:match("([^@]+)@?(.*)")
   if flavor ~= "" then
      flavor = " FLAVOR=" .. flavor
   end
   local seen = {}
   local portdir = "/usr/ports/" .. dir
   local pipe = io.popen("make -C "  .. portdir .. flavor .. " -V CONFLICTS -V CONFLICTS_INSTALL 2>/dev/null")
   for line in pipe:lines() do
      for word in line:gmatch("(%S+)%s?") do
         seen[word] = true
      end
   end
   pipe:close()
   return table_sorted_keys(seen)
end

-------------------------------------------------------------------
local function conflicting_pkgs(conflicting)
   local pkgs = {}
   for origin, pkgbase in pairs(fetch_pkgs_origins()) do
      if conflicting[pkgbase] then
         pkgs[origin] = pkgbase
      end
   end
   return pkgs
end

-------------------------------------------------------------------
local function collect_conflicts(pkg_pairs)
   local pkgs = {}
   for pkg_i, p1 in pairs(pkg_pairs) do
      for pkg_j, _ in pairs(p1) do
         pkgs[pkg_i] = pkgs[pkg_i] or {}
         table.insert(pkgs[pkg_i], pkg_j)
         pkgs[pkg_j] = pkgs[pkg_j] or {}
         table.insert(pkgs[pkg_j], pkg_i)
      end
   end
   return pkgs
end

-------------------------------------------------------------------
local function split_origins(origin_list)
   local port_list = {}
   local flavors = {}
   local last_port
   for _, origin in ipairs(origin_list) do
      local port, flavor = string.match(origin, "([^@]+)@?(.*)")
      if port ~= last_port then
         port_list[#port_list + 1] = port
         if flavor ~= "" then
            flavors[port] = {flavor}
         end
      else
         table.insert(flavors[port], flavor)
      end
      last_port = port
   end
   return port_list, flavors
end

-------------------------------------------------------------------
local PKG_PAIR_FILES = fetch_pkg_pairs(file_pattern)
local CONFLICT_PKGS = collect_conflicts(PKG_PAIR_FILES)
local PKGBASE = conflicting_pkgs(CONFLICT_PKGS)
local ORIGIN_LIST = table_sorted_keys(PKGBASE)
local PORT_LIST, FLAVORS = split_origins(ORIGIN_LIST)

local function conflicting_files(pkg_i, pkgs)
   local files = {}
   local all_files = {}
   local f
   local p1 = PKG_PAIR_FILES[pkg_i]
   if p1 then
      for _, pkg_j in ipairs(pkgs) do
         f = p1[pkg_j]
         if f then
            table.sort(f)
            files[#files + 1] = f[1]
            table.move(f, 1, #f, #all_files + 1, all_files)
         end
      end
   end
   for _, pkg_j in ipairs(pkgs) do
      p1 = PKG_PAIR_FILES[pkg_j]
      f = p1 and p1[pkg_i]
      if f then
         table.sort(f)
         files[#files + 1] = f[1]
         table.move(f, 1, #f, #all_files + 1, all_files)
      end
   end
   return table_sort_uniq(files), table_sort_uniq(all_files)
end

---------------------------------------------------------------------
local version_pattern = {
   "^lib/python%d%.%d/",
   "^share/py3%d%d%?-",
   "^share/%a+/py3%d%d%?-",
   "^lib/lua/%d%.%d/",
   "^share/lua/%d%.%d/",
   "^lib/perl5/[%d%.]+/",
   "^lib/perl5/site_perl/mach/[%d%.]+/",
   "^lib/ruby/gems/%d%.%d/",
   "^lib/ruby/site_ruby/%d%.%d/",
}

local function generalize_patterns(pkgs, files)
   local function match_any(str, pattern_array)
      for _, pattern in ipairs(pattern_array) do
         if string.match(str, pattern) then
            return true
         end
      end
      return false
   end
   local function unversioned_files()
      for i = 1, #files do
         if not match_any(files[i], version_pattern) then
            return true
         end
      end
      return false
   end
   local function pkg_wildcards(from, ...)
      local to_list = {...}
      local result = {}
      for i = 1, #pkgs do
         local orig_pkg = pkgs[i]
         for _, to in ipairs(to_list) do
            result[string.gsub(orig_pkg, from, to)] = true
         end
      end
      pkgs = table_sorted_keys(result)
   end
   local pkg_pfx_php = "php[0-9][0-9]-"
   local pkg_sfx_php = "-php[0-9][0-9]"
   local pkg_pfx_python2
   local pkg_sfx_python2
   local pkg_pfx_python3
   local pkg_sfx_python3
   local pkg_pfx_lua
   local pkg_pfx_ruby
   pkgs = table_sort_uniq(pkgs)
   if unversioned_files() then
      pkg_pfx_python2 = "py3[0-9]-" -- e.g. py39-
      pkg_sfx_python2 = "-py3[0-9]"
      pkg_pfx_python3 = "py3[0-9][0-9]-" -- e.g. py311-
      pkg_sfx_python3 = "-py3[0-9][0-9]"
      pkg_pfx_lua = "lua[0-9][0-9]-"
      pkg_pfx_ruby = "ruby[0-9][0-9]-"
   else
      pkg_pfx_python2 = "${PYTHON_PKGNAMEPREFIX}"
      pkg_sfx_python2 = "${PYTHON_PKGNAMESUFFIX}"
      pkg_pfx_python3 = nil
      pkg_sfx_python3 = nil
      pkg_pfx_lua = "${LUA_PKGNAMEPREFIX}"
      pkg_pfx_ruby = "${RUBY_PKGNAMEPREFIX}"
   end
   pkg_wildcards("^php%d%d%-", pkg_pfx_php)
   pkg_wildcards("-php%d%d$", pkg_sfx_php)
   pkg_wildcards("^phpunit%d%-", "phpunit[0-9]-")
   pkg_wildcards("^py3%d%-", pkg_pfx_python2, pkg_pfx_python3)
   pkg_wildcards("-py3%d%$", pkg_sfx_python2, pkg_sfx_python3)
   pkg_wildcards("^py3%d%d%-", pkg_pfx_python2, pkg_pfx_python3)
   pkg_wildcards("-py3%d%d%$", pkg_sfx_python2, pkg_sfx_python3)
   pkg_wildcards("^lua%d%d%-", pkg_pfx_lua)
   pkg_wildcards("-emacs_[%a_]*", "-emacs_*")
   pkg_wildcards("^ghostscript%d%-", "ghostscript[0-9]-")
   pkg_wildcards("^bacula%d%-", "bacula[0-9]-")
   pkg_wildcards("^bacula%d%d%-", "bacula[0-9][0-9]-")
   pkg_wildcards("^bareos%d%-", "bareos[0-9]-")
   pkg_wildcards("^bareos%d%d%-", "bareos[0-9][0-9]-")
   pkg_wildcards("^moosefs%d%-", "moosefs[0-9]-")
   pkg_wildcards("^ruby%d+-", pkg_pfx_ruby)
   return table_sort_uniq(pkgs)
end

-------------------------------------------------------------------
for _, port in ipairs(PORT_LIST) do
   local function merge_table(t1, t2)
      table.move(t2, 1, #t2, #t1 + 1, t1)
   end
   local port_conflicts = {}
   local files = {}
   local msg_files = {}
   local conflict_pkgs = {}
   local function merge_data(origin)
      local pkgbase = PKGBASE[origin]
      if not BAD_FILE_PKGS[pkgbase] then
         local pkg_confl_file1, pkg_confl_files = conflicting_files(pkgbase, CONFLICT_PKGS[pkgbase])
         merge_table(msg_files, pkg_confl_file1) -- 1 file per flavor
         merge_table(files, pkg_confl_files) -- all conflicting files
         merge_table(conflict_pkgs, CONFLICT_PKGS[pkgbase])
         merge_table(port_conflicts, fetch_port_conflicts(origin))
      end
   end
   local flavors = FLAVORS[port]
   if flavors then
      for _, flavor in ipairs(flavors) do
         merge_data(port .. "@" .. flavor)
      end
   else
      merge_data(port)
   end
   files = table_sort_uniq(files)
   msg_files = table_sort_uniq(msg_files)
   conflict_pkgs = generalize_patterns(conflict_pkgs, files)
   if #port_conflicts then
      port_conflicts = table_sort_uniq(port_conflicts)
      conflict_pkgs = conflicts_delta(port_conflicts, conflict_pkgs)
   end
   if conflict_pkgs then
      local conflicts_string_cur = table.concat(port_conflicts, " ")
      local conflicts_string_new = table.concat(conflict_pkgs, " ")
      local file_list = table.concat(msg_files, " ")
      print("# Port:  " .. port)
      print("# Files: " .. file_list)
      if conflicts_string_cur ~= "" then
         print("# <      " .. conflicts_string_cur)
      end
      print("# >      " .. conflicts_string_new)
      print("portedit merge -ie 'CONFLICTS_INSTALL=" .. conflicts_string_new ..
            " # " .. file_list .. "' /usr/ports/" .. port)
      print()
   end
end

-------------------------------------------------------------------
local BAD_FILES_ORIGINS = {}

for _, origin in ipairs(ORIGIN_LIST) do
   local pkgbase = PKGBASE[origin]
   local files = BAD_FILE_PKGS[pkgbase]
   if files then
      for _, file in ipairs(files) do
         if DUPLICATE_FILE[file] then
            local port = string.match(origin, "([^@]+)@?")
            BAD_FILES_ORIGINS[port] = BAD_FILES_ORIGINS[origin] or {}
            table.insert(BAD_FILES_ORIGINS[port], file)
         end
      end
   end
end

-------------------------------------------------------------------
local bad_origins = table_sorted_keys(BAD_FILES_ORIGINS)

if #bad_origins > 0 then
   print ("# Ports with badly named files:")
   print ()
   for _, port in ipairs(bad_origins) do
      print ("# " .. port)
      local files = BAD_FILES_ORIGINS[port]
      table.sort(files)
      for _, file in ipairs(files) do
         print ("#", file)
      end
      print()
   end
end
