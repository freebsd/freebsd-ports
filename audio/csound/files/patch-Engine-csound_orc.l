--- Engine/csound_orc.l.old	2011-02-03 05:49:04.000000000 -0600
+++ Engine/csound_orc.l	2011-02-03 05:49:33.000000000 -0600
@@ -202,7 +202,7 @@
                   alt_stack[macro_stack_ptr++] = macros;
                   /* printf("Push %p macro stack; new body #%s#\n", macros, mm->body); */
                   /* printf("Push buffer %p -> ", YY_CURRENT_BUFFER); */
-                  yypush_buffer_state(YY_CURRENT_BUFFER);
+                  //yypush_buffer_state(YY_CURRENT_BUFFER);
                   yy_scan_string(mm->body);
                   /* printf("%p\n", YY_CURRENT_BUFFER); */
                  }
@@ -228,7 +228,7 @@
                   alt_stack[macro_stack_ptr++] = macros;
                   /* printf("Push %p macro stack\n", mm_save); */
                   /* printf("Push buffer %p -> ", YY_CURRENT_BUFFER); */
-                  yypush_buffer_state(YY_CURRENT_BUFFER);
+                  //yypush_buffer_state(YY_CURRENT_BUFFER);
                   yy_scan_string(mm->body);
                   /* printf("%p\n", YY_CURRENT_BUFFER); */
                 }
@@ -280,7 +280,7 @@
                   //include_stack[include_stack_ptr++] = YY_CURRENT_BUFFER;
                   alt_stack[macro_stack_ptr++] = mm_save;
                   /* printf("Push %p macro stack\n", mm_save); */
-                  yypush_buffer_state(YY_CURRENT_BUFFER);
+                  //yypush_buffer_state(YY_CURRENT_BUFFER);
                   yy_scan_string(mm->body);
                 }
 {MACRONAMEDA}   { printf("Macro with arguments call not written\n");}
@@ -307,7 +307,7 @@
 <<EOF>>         {
                   MACRO *x, *y=macros;
                   /* printf("Leaving buffer %p\n", YY_CURRENT_BUFFER); */
-                  yypop_buffer_state();
+                  //yypop_buffer_state();
                   if ( !YY_CURRENT_BUFFER ) yyterminate();
                   /* printf("End of input; popping to %p\n", YY_CURRENT_BUFFER); */
                   macros = alt_stack[--macro_stack_ptr];
@@ -388,7 +388,7 @@
       exit(1);
     }
     alt_stack[macro_stack_ptr++] = macros;
-    yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE ) );
+    //yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE ) );
 }
 
 static inline int isNameChar(int c, int pos)
