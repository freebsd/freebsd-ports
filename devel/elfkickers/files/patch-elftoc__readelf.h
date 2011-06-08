--- ./elftoc/readelf.h.orig	2011-05-22 20:46:29.000000000 +0200
+++ ./elftoc/readelf.h	2011-06-08 12:16:37.000000000 +0200
@@ -7,6 +7,12 @@
 #ifndef	_readelf_h_
 #define	_readelf_h_
 
+#ifdef __FreeBSD__
+#define ELFCLASSNUM 3
+#define ELFDATANUM  3
+#define EV_NUM      2
+#endif
+
 /* Read all of the basic headers from the file image (namely the ELF
  * header, the program segment header table, and the section header
  * table). False is returned if the file could not be parsed as an ELF
