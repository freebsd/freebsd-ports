--- cpp.c.orig	2015-03-21 06:43:07 UTC
+++ cpp.c
@@ -65,8 +65,8 @@ int emit_dependencies = 0, emit_defines 
 FILE *emit_output;
 
 #ifdef STAND_ALONE
-static char *system_macros_def[] = { STD_MACROS, 0 };
-static char *system_assertions_def[] = { STD_ASSERT, 0 };
+static char *system_macros_def[] = { "/usr/include", 0 };
+static char *system_assertions_def[] = { "", 0 };
 #endif
 
 char *current_filename = 0, *current_long_filename = 0;
@@ -2371,7 +2371,7 @@ static int parse_opt(int argc, char *arg
 	char *filename = 0;
 	int with_std_incpath = 1;
 	int print_version = 0, print_defs = 0, print_asserts = 0;
-	int system_macros = 0, standard_assertions = 1;
+	int system_macros = 0, standard_assertions = 0;
 
 	init_lexer_state(ls);
 	ls->flags = DEFAULT_CPP_FLAGS;
