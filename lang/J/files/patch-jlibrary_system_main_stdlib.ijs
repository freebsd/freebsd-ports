--- jlibrary/system/main/stdlib.ijs.orig	2018-02-22 18:45:28 UTC
+++ jlibrary/system/main/stdlib.ijs
@@ -35,6 +35,7 @@ if. notdef 'UNAME' do.
   end.
 end.
 'libc.so.6 setlocale > x i *c'&(15!:0)^:(UNAME-:'Linux') 1;,'C'
+'libc.so.7 setlocale > x i *c'&(15!:0)^:(UNAME-:'FreeBSD') 1;,'C'
 if. notdef 'IFRASPI' do.
   if. UNAME -: 'Linux' do.
     cpu=. 2!:0 'cat /proc/cpuinfo'
@@ -97,6 +98,7 @@ if. (<'home') -.@e. {."1 SystemFolders d
   elseif. 'Android'-:UNAME do. t=. '/sdcard'
   elseif. 'Darwin'-:UNAME do. t=. (0-:t){::'';~t=. 2!:5'HOME'
   elseif. 'Linux'-:UNAME do. t=. (0-:t){::'';~t=. 2!:5'HOME'
+  elseif. 'FreeBSD'-:UNAME do. t=. (0-:t){::'';~t=. 2!:5'HOME'
   elseif. do. t=. ''
   end.
   if. (''-:t)+.((,'/')-:t)+.('/root'-:t)+.('/usr/'-:5{.t) do.
@@ -111,6 +113,7 @@ if. (<'temp') -.@e. {."1 SystemFolders d
   elseif. 'Android'-:UNAME do. t=. '/sdcard'
   elseif. 'Darwin'-:UNAME do. 1!:5 ::] <t=. '/tmp/',":2!:6''
   elseif. 'Linux'-:UNAME do. 1!:5 ::] <t=. '/tmp/',":2!:6''
+  elseif. 'FreeBSD'-:UNAME do. 1!:5 ::] <t=. '/tmp/',":2!:6''
   elseif. do. t=. ''
   end.
   SystemFolders=: SystemFolders, 'temp';t
@@ -123,14 +126,14 @@ end.
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
@@ -1344,7 +1347,7 @@ require 'pacman'
 x do_install_jpacman_ y
 )
 getqtbin=: 3 : 0
-if. (<UNAME) -.@e. 'Linux';'Darwin';'Win' do. return. end.
+if. (<UNAME) -.@e. 'Linux';'Darwin';'Win';'FreeBSD' do. return. end.
 if. IFQT do.
   smoutput 'must run from jconsole' return.
 end.
