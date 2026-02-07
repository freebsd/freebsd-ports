--- libexplain/buffer/utsname.c.orig
+++ libexplain/buffer/utsname.c
@@ -49,11 +49,13 @@
     explain_string_buffer_puts(sb, ", machine = ");
     explain_string_buffer_puts_quoted_n(sb,
         data->machine, sizeof(data->machine));
+#ifndef __FreeBSD__
 #ifdef _GNU_SOURCE
     explain_string_buffer_puts(sb, ", domainname = ");
     explain_string_buffer_puts_quoted_n(sb,
         data->domainname, sizeof(data->domainname));
 #endif
+#endif
     explain_string_buffer_puts(sb, " }");
 }
 
