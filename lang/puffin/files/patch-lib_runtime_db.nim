--- lib/runtime/db.nim.orig	2026-10-31 12:04:23 UTC
+++ lib/runtime/db.nim
@@ -7,7 +7,8 @@ import ./value, ./bytes, ./ffi, ./collections, ./struc
 import std/[tables, strutils]
 import ./value, ./bytes, ./ffi, ./collections, ./structs
 
-{.compile: "sqlite3_opt.c".}
+{.passC: gorge("pkg-config --silence-errors --cflags sqlite3").}
+{.passL: gorge("pkg-config --silence-errors --libs sqlite3").}
 {.compile: "db_sqlite.c".}
 
 # C-ABI Imports from db_sqlite.h
