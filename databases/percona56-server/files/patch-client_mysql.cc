--- client/mysql.cc.orig	2017-05-09 08:31:39.000000000 +0200
+++ client/mysql.cc	2017-05-29 13:24:38.665722000 +0200
@@ -2784,9 +2784,11 @@
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
@@ -2805,7 +2807,7 @@
                                    int end MY_ATTRIBUTE((unused)))
 {
   if (!status.batch && !quick)
-#if defined(USE_NEW_XLINE_INTERFACE)
+#if defined(USE_NEW_READLINE_INTERFACE) || defined(USE_LIBEDIT_INTERFACE)
     return rl_completion_matches(text, new_command_generator);
 #else
     return completion_matches((char *)text, (CPFunction *)new_command_generator);
