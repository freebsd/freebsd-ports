--- parse_option.c.orig	Sat Sep 30 21:06:27 2000
+++ parse_option.c	Thu Jul 25 06:46:57 2002
@@ -30,6 +30,8 @@
 int backmx_flag = 0;
 /* Flag set by '--static' (Added by Patrick D.) */
 int static_flag = 0;
+int dynamic_flag = 0;
+int custom_flag = 0;
 /* Vars for other options */
 char *ip_address;
 char *host_id;
@@ -51,6 +53,8 @@
     {"version", 0, &ver_flag, 1},
     /* Added by Patrick D. */
     {"static", 0, &static_flag, 1},
+    {"dynamic", 0, &dynamic_flag, 1},
+    {"custom", 0, &custom_flag, 1},
     /* These options don't set a flag.
        We distinguish them by their indices. */
     {"ip", 1, 0, 0},
@@ -98,6 +102,10 @@
     }
   }
 
+  if (static_flag+dynamic_flag+custom_flag > 1) {
+    fprintf(stderr, "ddup: --static, --dynamic and --custom options are mutually exclusive.\n");
+    help_flag = 1;
+  }
   if (help_flag) {
     usage();
   }
