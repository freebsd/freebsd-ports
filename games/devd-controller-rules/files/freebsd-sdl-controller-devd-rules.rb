#!/usr/bin/env ruby
# encoding: UTF-8

# MIT License
#
# Copyright (c) 2025 shkhln
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

MIN_EXPECTED_ENTRIES = 555
PRINT_NOTES          = true

VID_NOPELIST = [
  0,
  1,
  0x0e00, # no idea who's that
  0x0fff, # Aopen, Inc.; no known gamepads
  0x11ff, # no idea who's that
  0x162e, # ditto
  0x16d0, # MCS, whatever that means
  0x1a34, # ACRUX, ungoogleable
  0x20ab, # no idea who's that
  0x25b1, # ditto
  0x2f24, # ditto
  0x7545, # ditto
  0x8380, # ditto
  0x8888, # ditto
  0xd2d2  # ditto
]

if !File.exist?('usb_ids.h')
  system('fetch https://raw.githubusercontent.com/libsdl-org/SDL/refs/heads/main/src/joystick/usb_ids.h')
end

if !File.exist?('controller_list.h')
  system('fetch https://raw.githubusercontent.com/libsdl-org/SDL/refs/heads/main/src/joystick/controller_list.h')
end

controllers = []

controller_list_header = File.read('controller_list.h')
controller_list_header.scan(/MAKE_CONTROLLER_ID\(\s*0x([0-9a-f]+),\s*0x([0-9a-f]+)\s*\).*?(?:\/\/(.*)|)$/) do
  controllers << {vid: $1.to_i(16), pid: $2.to_i(16), note: ($3 ? $3.strip : nil)}
end

vids_by_name = {}
pids_by_name = {}

usb_ids_header = File.read('usb_ids.h')
usb_ids_header.scan(/#define USB_VENDOR_([0-9A-Z_]+)\s+0x([0-9a-f]+)/) do
  vids_by_name[$1] = $2.to_i(16)
end
usb_ids_header.scan(/#define USB_PRODUCT_([0-9A-Z_]+)\s+0x([0-9a-f]+)/) do
  pids_by_name[$1] = $2.to_i(16)
end

vids_by_name['BDA']      = vids_by_name['POWERA']
vids_by_name['EVORETRO'] = vids_by_name['DRAGONRISE']
vids_by_name['VICTRIX']  = vids_by_name['PDP']
vids_by_name['XBOX']     = vids_by_name['MICROSOFT']

for vendor in vids_by_name.keys
  pids_by_name.keys.find_all{|product| product.start_with?(vendor)}.each do |product|
    controllers << {vid: vids_by_name[vendor], pid: pids_by_name[product], note: product.delete_prefix(vendor).delete_prefix('_')}
    pids_by_name.delete(product)
  end
end

if !pids_by_name.empty?
  STDERR.puts "#{pids_by_name.size} product ids from usb_ids.h were not assigned to a vendor:"
  STDERR.puts "#{pids_by_name.keys.join(', ')}"
  STDERR.puts
end

# let's get rid of duplicates after merging entries from controller_list.h with usb_ids.h
controllers.uniq!{|controller| [controller[:vid], controller[:pid]]}

# garbage in, garbage out
controllers.delete_if{|controller| VID_NOPELIST.include?(controller[:vid])}

raise "Found #{controllers.size} controllers, expected at least #{MIN_EXPECTED_ENTRIES}" if controllers.size < MIN_EXPECTED_ENTRIES

def ids_to_regex(ids, width = 4)
  raise if !(ids.any?{|id| id.is_a?(String) && id.size == width && id =~ /[0-9a-f]+/})

  if width > 1
    alternatives = ids.group_by{|id| id[0]}.map{|first_digit, ids| first_digit + ids_to_regex(ids.map{|id| id[1..-1]}, width - 1)}
    if alternatives.size == 1
      alternatives[0]
    else
      "(#{alternatives.join('|')})"
    end
  else
    if ids.size == 1
      ids[0]
    else
      "[#{regex_char_class(ids)}]"
    end
  end
end

def regex_char_class(letters)
  out = ''
  range_start = nil
  letters = letters.sort.uniq
  letters.each_cons(2) do |a, b|
    if a.ord + 1 == b.ord
      range_start = a if !range_start
    else
      if range_start
        if a.ord - range_start.ord > 2
          out += "#{range_start}-#{a}"
        else
          out += (range_start..a).to_a.join
        end
        range_start = nil
      else
        out += a
      end
    end
  end
  if range_start
    if letters[-1].ord - range_start.ord > 2
      out += "#{range_start}-#{letters[-1]}"
    else
      out += (range_start..letters[-1]).to_a.join
    end
  else
    out += letters[-1]
  end
  out
end

vendors_by_id = vids_by_name.invert.merge({
  0x03eb => 'Atmel Corp.',
  0x05b8 => 'SYSGRATION', # doesn't look like a gamepad vendor
  0x056e => 'Elecom Co., Ltd',
  0x0810 => 'Personal Communication Systems, Inc.',
  0x0925 => 'Lakeview Research',
  0x0d62 => 'Darfon Electronics Corp.', # ?
  0x0e8f => 'GreenAsia Inc.',
  0x0f30 => 'Jess Technology Co., Ltd',
  0x1038 => 'SteelSeries ApS',
  0x11c0 => 'Betop', # ?
  0x11c9 => 'Nacon',
  0x12ab => 'Honey Bee Electronic International Ltd.',
  0x1345 => 'Sino Lite Technology Corp',
  0x1430 => 'RedOctane',
  0x15e4 => 'Numark', # doesn't look like a gamepad vendor
  0x1689 => 'Razer USA, Ltd',
  0x1bad => 'Harmonix Music Systems, Inc.',
  0x2516 => 'Cooler Master Co., Ltd.', # what might that be?
  0x25f0 => 'ShanWan' # who?
})

puts '# This config file, including most comments below this one,'
puts '# was generated by https://gist.github.com/shkhln/b39c2f3d609e57d47b7026da2a925aef'
puts '# from SDL\'s source code available at https://github.com/libsdl-org/SDL'
puts '# under the terms of Zlib license.'
puts
puts controllers
  .sort_by {|controller| [controller[:vid], controller[:pid]]}
  .group_by{|controller| controller[:vid]}
  .map     {|vid, group|
    [
      ("# #{vendors_by_id[vid] || '???'}" if PRINT_NOTES),
      (group.map{|controller| '# %#06x %s' % [controller[:pid], controller[:note]]}.join("\n") if PRINT_NOTES),
      <<~RULE
      notify 100 {
        match  "system"    "USB";
        match  "subsystem" "INTERFACE";
        match  "type"      "ATTACH";
        match  "vendor"    "#{'%#06x' % vid}";
        match  "product"   "0x#{ids_to_regex(group.map{|controller| '%04x' % controller[:pid]})}";
        action "chgrp games /dev/$cdev && chmod g+rw /dev/$cdev";
      };
      RULE
    ].compact.join("\n")
  }
  .join("\n")
