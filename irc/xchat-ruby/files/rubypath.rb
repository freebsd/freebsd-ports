#!/usr/local/bin/ruby
require "rbconfig"
if RbConfig::CONFIG[ 'rubyhdrdir' ].nil?
  puts RbConfig::CONFIG['archdir']
else
  print RbConfig::CONFIG['rubyhdrdir']
  print " -I" 
  print RbConfig::CONFIG['rubyhdrdir']
  print "/" 
  puts RbConfig::CONFIG['sitearch']
end
# eof
