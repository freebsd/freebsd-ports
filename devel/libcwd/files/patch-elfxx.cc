Index: elfxx.cc
===================================================================
--- elfxx.cc	(revision 1343)
+++ elfxx.cc	(working copy)
@@ -1382,13 +1382,13 @@
 #if __BYTE_ORDER == __LITTLE_ENDIAN
       ELFDATA2LSB
 #elif __BYTE_ORDER == __BIG_ENDIAN
-      ELFDATAMSB
+      ELFDATA2MSB
 #else
       ELFDATANONE
 #endif
 #else // !__BYTE_ORDER
 #ifdef WORDS_BIGENDIAN
-      ELFDATAMSB
+      ELFDATA2MSB
 #else
       ELFDATA2LSB
 #endif
