--- ext/extconf.rb.orig	2023-01-25 18:49:19 UTC
+++ ext/extconf.rb
@@ -26,7 +26,7 @@ else
   $ARCH_FLAGS = RbConfig::CONFIG['CFLAGS'].scan( /(-arch )(\S+)/ ).map{|x,y| x + y + ' ' }.join('')
 
 
-  $CFLAGS = "-fsigned-char -g -O2 -Wall -Werror " + $ARCH_FLAGS
+  $CFLAGS = "-fdeclspec -fsigned-char -g -O2 -Wall -Werror " + $ARCH_FLAGS
 
   have_func("strlcpy", "string.h")
 
