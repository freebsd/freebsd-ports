--- hphp/runtime/vm/debug/dwarf.cpp.orig	2013-07-21 17:25:47.751427347 +0200
+++ hphp/runtime/vm/debug/dwarf.cpp	2013-07-21 17:27:13.024430533 +0200
@@ -17,7 +17,7 @@
 
 #include <stdio.h>
 #include "debug.h"
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include "hphp/runtime/vm/debug/elfwriter.h"
 #endif
 #include "hphp/runtime/vm/debug/gdb-jit.h"
@@ -36,7 +36,7 @@
 int g_dwarfCallback(char *name, int size, Dwarf_Unsigned type,
             Dwarf_Unsigned flags, Dwarf_Unsigned link, Dwarf_Unsigned info,
             Dwarf_Unsigned *sect_name_index, Dwarf_Ptr handle, int *error) {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
   ElfWriter *e = reinterpret_cast<ElfWriter *>(handle);
   return e->dwarfCallback(name, size, type, flags, link, info);
 #else
@@ -221,7 +221,7 @@
     m_dwarfChunks[j] = nullptr;
   }
   m_dwarfChunks[i] = chunk;
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
   // register compacted chunk with gdb
   ElfWriter e = ElfWriter(chunk);
 #endif
@@ -291,7 +291,7 @@
     f->m_chunk = chunk;
   }
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
   if (f->m_chunk->m_functions.size() >= RuntimeOption::EvalGdbSyncChunks) {
     ElfWriter e = ElfWriter(f->m_chunk);
   }
@@ -306,7 +306,7 @@
   for (i = 0; i < m_dwarfChunks.size(); i++) {
     if (m_dwarfChunks[i] && !m_dwarfChunks[i]->isSynced()) {
       unregister_gdb_chunk(m_dwarfChunks[i]);
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
       ElfWriter e = ElfWriter(m_dwarfChunks[i]);
 #endif
     }
