--- jlibrary/system/main/regex.ijs.orig	2018-03-07 18:59:01 UTC
+++ jlibrary/system/main/regex.ijs
@@ -101,6 +101,7 @@ NB. rxdll is in bin or tools/regex
 select. UNAME
 case. 'Win' do. t=. 'jpcre.dll'
 case. 'Darwin' do. t=. 'libjpcre.dylib'
+case. 'FreeBSD' do. t=. 'libpcreposix.so' 
 fcase. 'Linux' do.
   if. 2 0-:('libpcreposix.so.3 dummyfunction n')&(15!:0) ::(15!:10) '' do.
     rxdll=: 'libpcreposix.so.3'
