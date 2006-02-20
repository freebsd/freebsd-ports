--- class/object.h	3 Nov 2004 06:57:51 -0000	1.1
+++ class/object.h	3 Nov 2004 07:25:35 -0000	1.2
@@ -136,5 +136,5 @@
 BOstream & operator<< (BOstream & out, const ObjectFile & of);
 BIstream & operator>> (BIstream & in, ObjectFile & of);
 
-#endif object_h
+#endif /* object_h */
 
