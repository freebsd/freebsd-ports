--- pgheader.h.orig	2012-09-20 11:50:03 UTC
+++ pgheader.h
@@ -10,8 +10,8 @@
 #define PGHEADER_BAD_HEADER 6
 
 
-const char * pgheader_version;
-const char * pgheader_magic;
+extern const char * pgheader_version;
+extern const char * pgheader_magic;
 
 /* This does some heuristic tests to make it reasonably sure we are dealing
    with a Polyglot book.
