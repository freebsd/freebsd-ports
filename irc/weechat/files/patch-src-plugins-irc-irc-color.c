From 9453e81baa7935db82a0b765a47cba772aba730d Mon Sep 17 00:00:00 2001
--- src/plugins/irc/irc-color.c
+++ src/plugins/irc/irc-color.c
@@ -62,13 +62,15 @@ char *irc_color_to_weechat[IRC_NUM_COLORS] =
 char *
 irc_color_decode (const char *string, int keep_colors)
 {
-    unsigned char *out, *ptr_string;
-    int out_length, length, out_pos;
-    char str_fg[3], str_bg[3], str_color[128], str_key[128];
+    unsigned char *out, *out2, *ptr_string;
+    int out_length, length, out_pos, length_to_add;
+    char str_fg[3], str_bg[3], str_color[128], str_key[128], str_to_add[128];
     const char *remapped_color;
     int fg, bg, bold, reverse, italic, underline, rc;
 
     out_length = (strlen (string) * 2) + 1;
+    if (out_length < 128)
+        out_length = 128;
     out = malloc (out_length);
     if (!out)
         return NULL;
@@ -80,20 +82,27 @@ irc_color_decode (const char *string, int keep_colors)
 
     ptr_string = (unsigned char *)string;
     out[0] = '\0';
+    out_pos = 0;
     while (ptr_string && ptr_string[0])
     {
+        str_to_add[0] = '\0';
         switch (ptr_string[0])
         {
             case IRC_COLOR_BOLD_CHAR:
                 if (keep_colors)
-                    strcat ((char *)out,
-                            weechat_color((bold) ? "-bold" : "bold"));
+                {
+                    snprintf (str_to_add, sizeof (str_to_add), "%s",
+                              weechat_color ((bold) ? "-bold" : "bold"));
+                }
                 bold ^= 1;
                 ptr_string++;
                 break;
             case IRC_COLOR_RESET_CHAR:
                 if (keep_colors)
-                    strcat ((char *)out, weechat_color("reset"));
+                {
+                    snprintf (str_to_add, sizeof (str_to_add), "%s",
+                              weechat_color ("reset"));
+                }
                 bold = 0;
                 reverse = 0;
                 italic = 0;
@@ -106,22 +115,28 @@ irc_color_decode (const char *string, int keep_colors)
             case IRC_COLOR_REVERSE_CHAR:
             case IRC_COLOR_REVERSE2_CHAR:
                 if (keep_colors)
-                    strcat ((char *)out,
-                            weechat_color((reverse) ? "-reverse" : "reverse"));
+                {
+                    snprintf (str_to_add, sizeof (str_to_add), "%s",
+                              weechat_color ((reverse) ? "-reverse" : "reverse"));
+                }
                 reverse ^= 1;
                 ptr_string++;
                 break;
             case IRC_COLOR_ITALIC_CHAR:
                 if (keep_colors)
-                    strcat ((char *)out,
-                            weechat_color((italic) ? "-italic" : "italic"));
+                {
+                    snprintf (str_to_add, sizeof (str_to_add), "%s",
+                              weechat_color ((italic) ? "-italic" : "italic"));
+                }
                 italic ^= 1;
                 ptr_string++;
                 break;
             case IRC_COLOR_UNDERLINE_CHAR:
                 if (keep_colors)
-                    strcat ((char *)out,
-                            weechat_color((underline) ? "-underline" : "underline"));
+                {
+                    snprintf (str_to_add, sizeof (str_to_add), "%s",
+                              weechat_color ((underline) ? "-underline" : "underline"));
+                }
                 underline ^= 1;
                 ptr_string++;
                 break;
@@ -194,22 +209,39 @@ irc_color_decode (const char *string, int keep_colors)
                                       (bg >= 0) ? "," : "",
                                       (bg >= 0) ? irc_color_to_weechat[bg] : "");
                         }
-                        strcat ((char *)out, weechat_color(str_color));
+                        snprintf (str_to_add, sizeof (str_to_add), "%s",
+                                  weechat_color (str_color));
                     }
                     else
-                        strcat ((char *)out, weechat_color("resetcolor"));
+                    {
+                        snprintf (str_to_add, sizeof (str_to_add), "%s",
+                                  weechat_color ("resetcolor"));
+                    }
                 }
                 break;
             default:
                 length = weechat_utf8_char_size ((char *)ptr_string);
                 if (length == 0)
                     length = 1;
-                out_pos = strlen ((char *)out);
-                memcpy (out + out_pos, ptr_string, length);
-                out[out_pos + length] = '\0';
+                memcpy (str_to_add, ptr_string, length);
+                str_to_add[length] = '\0';
                 ptr_string += length;
                 break;
         }
+        if (str_to_add[0])
+        {
+            length_to_add = strlen (str_to_add);
+            if (out_pos + length_to_add >= out_length)
+            {
+                out_length *= 2;
+                out2 = realloc (out, out_length);
+                if (!out2)
+                    return (char *)out;
+                out = out2;
+            }
+            memcpy (out + out_pos, str_to_add, length_to_add + 1);
+            out_pos += length_to_add;
+        }
     }
 
     return (char *)out;
