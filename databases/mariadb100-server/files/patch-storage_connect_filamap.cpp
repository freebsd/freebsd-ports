--- storage/connect/filamap.cpp.orig	2014-09-25 00:29:47.000000000 +0200
+++ storage/connect/filamap.cpp	2014-09-27 11:46:06.000000000 +0200
@@ -288,7 +288,7 @@
 /***********************************************************************/
 /*  Initialize Fpos and Mempos for indexed DELETE.                     */
 /***********************************************************************/
-int MAPFAM::InitDelete(PGLOBAL g, int fpos, int spos)
+int MAPFAM::InitDelete(PGLOBAL g, uintptr_t fpos, uintptr_t spos)
   {
   Fpos = Memory + fpos;
   Mempos = Memory + spos;
@@ -683,7 +683,7 @@
 /***********************************************************************/
 /*  Initialize CurBlk, CurNum, Mempos and Fpos for indexed DELETE.     */
 /***********************************************************************/
-int MPXFAM::InitDelete(PGLOBAL g, int fpos, int spos)
+int MPXFAM::InitDelete(PGLOBAL g, uintptr_t fpos, uintptr_t spos)
   {
   Fpos = Memory + Headlen + fpos * Lrecl;
   Mempos = Fpos + Lrecl;
