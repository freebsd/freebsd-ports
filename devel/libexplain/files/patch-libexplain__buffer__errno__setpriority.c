--- libexplain/buffer/errno/setpriority.c.orig
+++ libexplain/buffer/errno/setpriority.c
@@ -124,6 +124,7 @@
             /* FIXME: i18n */
             "the caller attempted to lower a process priority"
         );
+#ifdef RLIMIT_NICE
         if (explain_option_dialect_specific())
         {
             /*
@@ -141,6 +142,7 @@
                 explain_string_buffer_printf(sb, " (%d < %d)", prio, cur);
             }
         }
+#endif
         explain_buffer_dac_sys_nice(sb);
         break;
 
