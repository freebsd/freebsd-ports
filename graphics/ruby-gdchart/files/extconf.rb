require 'mkmf'

$CFLAGS << ' -DHAVE_JPEG'
dir_config('gd', '/usr/local')
dir_config('gdchart', '/usr/local')
have_library('z')
have_library('png')
have_library('jpeg')
have_library('gd')
have_library('gdchart')
create_makefile("GDChart")
