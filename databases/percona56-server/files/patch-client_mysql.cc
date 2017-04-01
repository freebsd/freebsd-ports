--- client/mysql.cc.orig	2016-09-30 11:41:40 UTC
+++ client/mysql.cc
@@ -2738,9 +2738,11 @@ static void initialize_readline (char *n
 #ifdef HAVE_LOCALE_H
   setlocale(LC_ALL,""); /* so as libedit use isprint */
 #endif
-  rl_attempted_completion_function= (CPPFunction*)&new_mysql_completion;
-  rl_completion_entry_function= &no_completion;
+  rl_attempted_completion_function= (rl_completion_func_t*)&new_mysql_completion;
+  rl_completion_entry_function= (rl_compentry_func_t*)&no_completion;
+  /*
   rl_add_defun("magic-space", (Function*)&fake_magic_space, -1);
+  */
 #else
   rl_attempted_completion_function= (CPPFunction*)&new_mysql_completion;
   rl_completion_entry_function= &no_completion;
@@ -2759,7 +2761,7 @@ static char **new_mysql_completion(const
                                    int end MY_ATTRIBUTE((unused)))
 {
   if (!status.batch && !quick)
-#if defined(USE_NEW_READLINE_INTERFACE)
+#if defined(USE_NEW_READLINE_INTERFACE) || defined(USE_LIBEDIT_INTERFACE)
     return rl_completion_matches(text, new_command_generator);
 #else
     return completion_matches((char *)text, (CPFunction *)new_command_generator);
