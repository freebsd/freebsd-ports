--- gstrfuncs.c.orig	2001-02-27 07:00:22.000000000 +0100
+++ gstrfuncs.c	2004-03-01 13:19:49.531603760 +0100
@@ -867,8 +867,8 @@ g_printf_string_upper_bound (const gchar
                   /* beware of positional parameters
                    */
                 case '$':
-                  g_warning (G_GNUC_PRETTY_FUNCTION
-                             "(): unable to handle positional parameters (%%n$)");
+                  g_warning ("%s: unable to handle positional parameters (%%n$)",
+                             G_GNUC_PRETTY_FUNCTION);
                   len += 1024; /* try adding some safety padding */
                   break;
 
@@ -1034,8 +1034,8 @@ g_printf_string_upper_bound (const gchar
                   /*          n   .   dddddddddddddddddddddddd   E   +-  eeee */
                   conv_len += 1 + 1 + MAX (24, spec.precision) + 1 + 1 + 4;
                   if (spec.mod_extra_long)
-                    g_warning (G_GNUC_PRETTY_FUNCTION
-                               "(): unable to handle long double, collecting double only");
+                    g_warning ("%s: unable to handle long double, collecting double only",
+                               G_GNUC_PRETTY_FUNCTION);
 #ifdef HAVE_LONG_DOUBLE
 #error need to implement special handling for long double
 #endif
@@ -1077,8 +1077,8 @@ g_printf_string_upper_bound (const gchar
                   conv_done = TRUE;
                   if (spec.mod_long)
                     {
-                      g_warning (G_GNUC_PRETTY_FUNCTION
-                                 "(): unable to handle wide char strings");
+                      g_warning ("%s: unable to handle wide char strings",
+                                 G_GNUC_PRETTY_FUNCTION);
                       len += 1024; /* try adding some safety padding */
                     }
                   break;
@@ -1108,8 +1108,8 @@ g_printf_string_upper_bound (const gchar
                   conv_len += format - spec_start;
                   break;
                 default:
-                  g_warning (G_GNUC_PRETTY_FUNCTION
-                             "(): unable to handle `%c' while parsing format",
+                  g_warning ("%s: unable to handle `%c' while parsing format",
+                             G_GNUC_PRETTY_FUNCTION,
                              c);
                   break;
                 }
