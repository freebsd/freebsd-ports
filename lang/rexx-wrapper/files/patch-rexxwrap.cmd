--- rexxwrap.cmd.orig	2006-09-22 01:16:29.000000000 +0200
+++ rexxwrap.cmd	2011-11-29 13:21:17.000000000 +0100
@@ -84,7 +84,7 @@
 implib.unirexx = 'rxx'
 
 compiler.win32 = 'cygwin ming vc wcc borland lcc'
-compiler.unix = 'gcc cc c89 egcs xlc'
+compiler.unix = 'gcc clang cc c89 egcs xlc'
 compiler.qnx = 'cc'
 compiler.os2 = 'gcc emxos2 emxdos wcc'
 compiler.dos = 'djgpp'
@@ -718,6 +718,7 @@
          If _debug > 0 Then opt = '-g -DREXXWRAPPER_DEBUG='_debug
          Else opt = '-O'
          cc.gcc = 'gcc'
+         cc.clang='clang'
          cc.egcs = 'egcs'
          cc.cc = 'cc'
          cc.xlc = 'xlc'
