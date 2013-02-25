$NetBSD: patch-src_tclhash.h,v 1.1 2012/11/16 00:35:28 joerg Exp $

--- src/tclhash.h.orig	2012-11-15 10:32:27.000000000 +0000
+++ src/tclhash.h
@@ -75,7 +75,7 @@ typedef struct tcl_bind_list_b {
 
 #ifndef MAKING_MODS
 
-inline void garbage_collect_tclhash(void);
+void garbage_collect_tclhash(void);
 
 void init_bind(void);
 void kill_bind(void);
