From 4d9b7c01d68f64a93a25ff49504bbeca664adbc5 Mon Sep 17 00:00:00 2001
From: Frantisek Sumsal <frantisek@sumsal.cz>
Date: Wed, 29 Oct 2025 13:31:11 +0100
Subject: [PATCH] suppression: avoid using sscanf()'s %m specifier

As it's not available in BSD libc.

Addresses: #153
--- src/suppression.c.orig	2024-01-29 15:03:13 UTC
+++ src/suppression.c
@@ -100,25 +100,31 @@ int df_suppression_load(GList **suppressions, const ch
         df_verbose("Found suppressions for bus: '%s'\n", service_name);
 
         while ((n = getline(&line, &len, f)) > 0) {
+                g_auto(GStrv) tokens = NULL;
                 g_autoptr(char) suppression = NULL, description = NULL;
                 g_autoptr(suppression_item_t) item = NULL;
+                int token_count;
                 char *p;
 
+                /* Strip leading and trailing whitespaces and check if the line is empty after the stripping -
+                 * if so, skip it */
+                g_strstrip(line);
+                if (line[0] == '\0')
+                        continue;
+
+                /* Beginning of the next section, stop here */
                 if (line[0] == '[')
                         break;
 
-                /* The line contains only whitespace, skip it */
-                if (strspn(line, " \t\r\n") == (size_t) n)
-                        continue;
-
-                /* Drop the newline character for nices error messages */
-                if (line[n - 1] == '\n')
-                        line[n - 1] = 0;
-
-                /* The suppression description is optional, so let's accept such
-                 * lines as well */
-                if (sscanf(line, "%ms %m[^\n]", &suppression, &description) < 1)
+                /* Split the line into either '<suppression> <description>' or just '<suppression>' */
+                tokens = g_strsplit_set(line, " \t\r\n", 2);
+                token_count = g_strv_length(tokens);
+                if (token_count < 1)
                         return df_fail_ret(-1, "Failed to parse line '%s'\n", line);
+
+                suppression = g_strdup(tokens[0]);
+                if (token_count > 1)
+                        description = g_strdup(g_strstrip(tokens[1]));
 
                 item = calloc(sizeof(*item), 1);
                 if (!item)
