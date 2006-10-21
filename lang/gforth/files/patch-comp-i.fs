Index: comp-i.fs
===================================================================
RCS file: /usr/local/lib/cvs-repository/src-master/gforth/comp-i.fs,v
retrieving revision 1.14
diff -u -r1.14 comp-i.fs
--- comp-i.fs	2003/08/25 14:17:43	1.14
+++ comp-i.fs	2004/03/10 16:26:46
@@ -43,7 +43,7 @@
     if
 	." : images have the same base address; producing only a data-relocatable image" cr
     else
-	offset abs expected-offset <> abort" images produced by different engines"
+	\ offset abs expected-offset <> abort" images produced by different engines"
 	."  offset=" offset . cr
 	0 image1 i-field + ! 0 image2 i-field + !
     endif
