--- jlibrary/system/main/stdlib.ijs.orig	2016-11-25 19:04:24 UTC
+++ jlibrary/system/main/stdlib.ijs
@@ -93,6 +93,7 @@ if. (<'home') -.@e. {."1 SystemFolders d
   elseif. 'Android'-:UNAME do. t=. '/sdcard'
   elseif. 'Darwin'-:UNAME do. t=. (0-:t){::'';~t=. 2!:5'HOME'
   elseif. 'Linux'-:UNAME do. t=. (0-:t){::'';~t=. 2!:5'HOME'
+  elseif. 'FreeBSD'-:UNAME do. t=. (0-:t){::'';~t=. 2!:5'HOME'
   elseif. do. t=. ''
   end.
   if. (''-:t)+.((,'/')-:t)+.('/root'-:t)+.('/usr/'-:5{.t) do.
@@ -107,6 +108,7 @@ if. (<'temp') -.@e. {."1 SystemFolders d
   elseif. 'Android'-:UNAME do. t=. '/sdcard'
   elseif. 'Darwin'-:UNAME do. 1!:5 ::] <t=. '/tmp/',":2!:6''
   elseif. 'Linux'-:UNAME do. 1!:5 ::] <t=. '/tmp/',":2!:6''
+  elseif. 'FreeBSD'-:UNAME do. 1!:5 ::] <t=. '/tmp/',":2!:6''
   elseif. do. t=. ''
   end.
   SystemFolders=: SystemFolders, 'temp';t
@@ -119,14 +121,14 @@ end.
 18!:4 <'z'
 18!:4 <'z'
 UNXLIB=: ([: <;._1 ' ',]);._2 (0 : 0)
-libc.so.6 libc.so libc.dylib libc.dylib
-libz.so.1 libz.so libz.dylib libz.dylib
-libsqlite3.so.0 libsqlite.so libsqlite3.dylib libsqlite3.dylib
-libxml2.so.2 libxml2.so libxml2.dylib libxml2.dylib
+libc.so.6 libc.so libc.so.7 libc.dylib libc.dylib
+libz.so.1 libz.so libc.so.7 libz.dylib libz.dylib
+libsqlite3.so.0 libsqlite.so libsqlite3.so.0 libsqlite3.dylib libsqlite3.dylib
+libxml2.so.2 libxml2.so libxml2.so.2 libxml2.dylib libxml2.dylib
 )
 unxlib=: 3 : 0
 r=. (;: 'c z sqlite3') i. <,y
-c=. IFIOS + (;: 'Linux Android Darwin') i. <UNAME_z_
+c=. IFIOS + (;: 'Linux Android FreeBSD Darwin') i. <UNAME_z_
 (<r,c) {:: UNXLIB_z_
 )
 18!:4 <'z'
@@ -1337,7 +1339,7 @@ require 'pacman'
 do_install_jpacman_ y
 )
 getqtbin=: 3 : 0
-if. (<UNAME) -.@e. 'Linux';'Darwin';'Win' do. return. end.
+if. (<UNAME) -.@e. 'Linux';'Darwin';'Win';'FreeBSD' do. return. end.
 if. IFQT do.
   smoutput 'must run from jconsole' return.
 end.
