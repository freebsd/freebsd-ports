#!/usr/bin/env ruby
# -*- ruby -*-
#
# Copyright (c) 2001-2004 Akinori MUSHA
#
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
# $FreeBSD$

RCS_ID = %q$Idaemons: /home/cvs/sunshar/sunshar.rb,v 1.13 2004/02/28 14:15:47 knu Exp $
RCS_REVISION = RCS_ID.split[2]
MYNAME = File.basename($0)

require 'parsearg'
require 'fileutils'
require 'shellwords'
require 'stringio'

begin
  require 'features/ruby18/dir'
rescue LoadError; end

$USAGE = 'usage'

$strip_level = 0
$force = false
$dryrun = false
$quiet = false
$dir = nil

def info(*s)
  puts(*s) unless $quiet
end

def usage
  print <<-EOF
#{MYNAME} rev.#{RCS_REVISION}

usage:  #{MYNAME} [-fnq] [-p level] [file]
        #{MYNAME} -h
  -d dir  chdir   -- chdir to dir before extracting files
  -f      force   -- allow overwriting, ignore errors
  -h      help    -- show this help
  -n      dry run -- show what would have been extracted
  -p N    strip   -- strip N levels from pathnames (cf. patch(1)\'s -p)
  -q      quiet   -- be quiet
  EOF
end

def main
  parseArgs(0, nil, 'fhnq', 'd:', 'p:')

  if $OPT_h
    usage
    exit 0
  end

  if $OPT_f
    $force = true
  end

  if $OPT_n
    $dryrun = true
  end

  if $OPT_q
    $quiet = true
  end

  $dir = $OPT_d || '.'

  if $OPT_p
    $strip_level = $OPT_p.to_i rescue -1

    if $strip_level < 0
      STDERR.puts "negative value ignored: #{$OPT_p}"
    end
  end

  nerrors = 0

  if ARGV.empty?
    info "extracting files from stdin into #{$dir}"

    begin
      Dir.chdir($dir) {
	unshar_stream(STDIN)
      }

      info "done."
    rescue => e
      STDERR.puts "error in extracting stdin: #{e.message}"
      nerrors += 1
    end
  else
    for file in ARGV
      info "extracting files from #{file} into #{$dir}"

      begin
	File.open(file) do |f|
	  Dir.chdir($dir) {
	    unshar_stream(f)
	  }
	end

	info "done."
      rescue => e
	STDERR.puts "error in extracting #{file}: #{e.message}"
	nerrors += 1
      end
    end
  end

  exit nerrors
end

def unshar_stream(io)
  e = nil

  while line = io.gets
    if /^(\s*)\# This is a shell archive/ =~ line
      indent = $1.length
      break
    end
  end

  if io.eof?
    raise "not a shell archive."
  end

  f = nil
  prefix = nil
  file = nil
  boundary = nil

  while line = io.gets
    line.slice!(0, indent)

    if f
      if line.strip == boundary
	f.close
	f = nil
	next
      end

      if line.sub!(/^#{Regexp.quote(prefix)}/, '')
	f.print line
      else
	raise "line #{io.lineno}: broken archive: #{line}"
      end

      next
    end

    case line
    when /^exit\s*$/
      break
    when /^echo\s+(.+)$/
      # info $1
    when /^mkdir\s+(?:-p\s+)?(.+)$/
      dir = nil

      Shellwords.shellwords($1).each do |word|
	if /^[^\-]/ =~ word
	  dir = word
	  break
	end
      end

      next if dir.nil?

      dir = strip_filename(dir.strip + '/')
      if dir.chomp('/').empty?
	next
      end

      begin
	FileUtils.mkdir_p(dir) unless $dryrun
	info "c - #{dir}"
      rescue => e
	info "c - #{dir} ... failed: #{e.message}"
	raise e
      end
    when /sed\s+(.+)>(.+)<<(.+)/
      prefix = Shellwords.shellwords($1).first
      file = Shellwords.shellwords($2).first
      boundary = Shellwords.shellwords($3).first

      next unless prefix && file && boundary

      if /s(.)\^(.*)\1\1/ =~ prefix
	prefix = $2
      else
	next
      end

      file = strip_filename(file)

      next if file.empty? || boundary.empty?

      overwrite = false

      if File.exist?(file)
	if $force
	  overwrite = true
	else
	  info "x - #{file} ... skipped"
	  next
	end
      end

      dir = File.dirname(file)

      if !File.directory?(dir + "/.")
	begin
	  FileUtils.mkdir_p(dir) unless $dryrun
	  info "d - #{dir}"
	rescue => e
	  info "d - #{dir} ... failed: #{e.message}"
	  raise e
	end
      end

      begin
        f = $dryrun ? StringIO.new : File.open(file, 'w')
	if overwrite
	  info "x - #{file} ... overwritten"
	else
	  info "x - #{file}"
	end
      rescue => e
	info "x - #{file} ... failed! (#{e.message})"

	if $force
	  f = nil
	  next
	else
	  raise e
	end
      end
    end
  end

  raise e if e
end

def strip_filename(file)
  sfile = file.gsub(%r"/{2,}", "/")

  if 0 < $strip_level
    sfile.sub!(%r"^([^/]*/){1,#{$strip_level}}", '')
  end

  case sfile
  when %r"^[~/]"
    raise "reference to absolute directory: #{file} (use -p N)"
  when %r"(^|/)\.\.(?:/|$)"
    raise "reference to parent directory: #{file} (use -p N)"
  end

  sfile
end

def signal_handler(sig)
  info "\nInterrupted."

  exit 255
end

if $0 == __FILE__
  for sig in [2, 3, 15]
    trap(sig) do
      signal_handler(sig)
    end
  end

  main
end
