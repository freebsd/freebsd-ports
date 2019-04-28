--- jlibrary/system/main/regex.ijs.orig	2019-01-06 11:11:14 UTC
+++ jlibrary/system/main/regex.ijs
@@ -179,6 +179,7 @@ select. UNAME
 case. 'Win' do. t=. 'jpcre2.dll'
 case. 'Darwin' do. t=. 'libjpcre2.dylib'
 case. 'Linux' do. t=. 'libjpcre2.so'
+case. 'FreeBSD' do. t=. 'libjpcre2.so'
 case. 'Android' do. t=. 'libjpcre2.so'
 end.
 
@@ -191,6 +192,8 @@ NB. fall back one more time
 if. ('Android'-:UNAME) *. 0 = 1!:4 :: 0: <f do.
   f=. (({.~i:&'/')LIBFILE),'/',t
 elseif. ('Linux'-:UNAME) *. (IFUNIX>'/'e.LIBFILE) *. 0 = 1!:4 :: 0: <f do.
+  f=. 'libpcre2-8.so.0'
+elseif. ('FreeBSD'-:UNAME) *. (IFUNIX>'/'e.LIBFILE) *. 0 = 1!:4 :: 0: <f do.
   f=. 'libpcre2-8.so.0'
 elseif. 0 = 1!:4 :: 0: <f do.
   f=. t
