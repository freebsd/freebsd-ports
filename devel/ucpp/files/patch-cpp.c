--- cpp.c.orig	2008-10-01 21:15:41.000000000 +0400
+++ src/cpp.c	2011-03-17 21:08:15.000000000 +0300
@@ -65,8 +65,8 @@
 FILE *emit_output;
 
 #ifdef STAND_ALONE
-static char *system_macros_def[] = { STD_MACROS, 0 };
-static char *system_assertions_def[] = { STD_ASSERT, 0 };
+static char *system_macros_def[] = { "/usr/include", 0 };
+static char *system_assertions_def[] = { "", 0 };
 #endif
 
 char *current_filename = 0, *current_long_filename = 0;
@@ -2364,7 +2364,7 @@
 	char *filename = 0;
 	int with_std_incpath = 1;
 	int print_version = 0, print_defs = 0, print_asserts = 0;
-	int system_macros = 0, standard_assertions = 1;
+	int system_macros = 0, standard_assertions = 0;
 
 	init_lexer_state(ls);
 	ls->flags = DEFAULT_CPP_FLAGS;
