--- extconf.rb.org	Fri Sep  2 20:18:20 2005
+++ extconf.rb	Fri Sep  2 20:38:41 2005
@@ -9,6 +9,6 @@
 err "Yaz ZOOM header not available" unless have_header("yaz/zoom.h")
 
 $CFLAGS << " #{`yaz-config --cflags`} "
-$LDFLAGS << " #{`yaz-config --libs`} "
+$LDFLAGS << " #{`yaz-config --libs`}".chomp
 
 create_makefile("zoom", "src")
