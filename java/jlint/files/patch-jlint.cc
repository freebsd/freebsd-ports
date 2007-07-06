--- jlint.cc.orig	2007-07-06 08:26:42.000000000 +0000
+++ jlint.cc	2007-07-06 08:29:08.000000000 +0000
@@ -151,7 +151,7 @@
     if (compound_message != NULL
         && ((loop_id != 0 
              && ((code != msg_loop && code != msg_sync_loop)
-                 || (int)parameter[2] != loop_id))
+                 || (long)parameter[2] != loop_id))
             || (loop_id == 0 && code != msg_wait_path)))
       {
         if (!message_node::find(compound_message)) { 
@@ -226,7 +226,7 @@
                            name.as_asciz()); 
             break;
           case 'd': // integer
-            dst += sprintf(dst, "%d", (int)parameter[index]);  
+            dst += sprintf(dst, "%d", (long)parameter[index]);  
             break;
           default:
             assert(false/*bad message parameter format*/);
@@ -262,7 +262,7 @@
               compound_message = strdup(his_buf);
               first = last = new message_node(msg_buf);
               if (code != msg_wait) { 
-                loop_id = (int)parameter[2];
+                loop_id = (long)parameter[2];
               }
             } else if (!message_node::find(his_buf)) { 
               fprintf(stdout, "%s\n", msg_buf);
