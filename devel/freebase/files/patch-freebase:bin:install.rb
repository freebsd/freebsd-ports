--- bin/install.rb.orig	Mon Mar 24 07:10:57 2003
+++ bin/install.rb	Mon Feb 21 18:38:00 2005
@@ -1,21 +1,40 @@
 require 'rbconfig'
 require 'find'
 require 'ftools'
+require 'getoptlong'
+
+def usage( exit_code = 1 )
+	printf "Usage: #{ARGV[0]} [--path <PATH>]\n"
+	exit( exit_code )
+end
 
 Dir.chdir ".." if Dir.pwd =~ /bin.?$/
 
+opts = GetoptLong.new( ["--prefix", "-p", GetoptLong::REQUIRED_ARGUMENT ] )
+$my_prefix = nil
+opts.each { |opt, arg|
+	case opt
+	when "--prefix"
+		$my_prefix = arg
+	else
+		usage()
+	end
+}
+
+def prefixize( str )
+	$my_prefix ?
+		str.gsub( Regexp::compile( "^#{Regexp::escape($prefix)}" ), $my_prefix ) :
+		str
+end
+
 include Config
 
-$srcdir = CONFIG["srcdir"]
+$prefix = CONFIG["prefix"]
+$srcdir = prefixize( CONFIG["srcdir"] )
 $version = CONFIG["MAJOR"]+"."+CONFIG["MINOR"]
-$libdir = File.join(CONFIG["libdir"], "ruby", $version)
-$archdir = File.join($libdir, CONFIG["arch"])
-$site_libdir = $:.find {|x| x =~ /site_ruby$/}
-if !$site_libdir
-  $site_libdir = File.join($libdir, "site_ruby")
-elsif $site_libdir !~ Regexp.quote($version)
-  $site_libdir = File.join($site_libdir, $version)
-end
+$libdir = prefixize( CONFIG["rubylibdir"] )
+$archdir = prefixize( CONFIG["archdir"] )
+$site_libdir = prefixize( CONFIG["sitelibdir"] )
 
 def install_rb(srcdir = nil)
   libdir = "lib"
