--- app/src/cli.c.orig	2023-11-30 22:01:51 UTC
+++ app/src/cli.c
@@ -2154,7 +2154,7 @@ parse_args_with_getopt(struct scrcpy_cli_args *args, i
                     return false;
                 }
                 break;
-            case OPT_ORIENTATION:
+            case OPT_ORIENTATION: {
                 enum sc_orientation orientation;
                 if (!parse_orientation(optarg, &orientation)) {
                     return false;
@@ -2162,6 +2162,7 @@ parse_args_with_getopt(struct scrcpy_cli_args *args, i
                 opts->display_orientation = orientation;
                 opts->record_orientation = orientation;
                 break;
+            }
             case OPT_RENDER_DRIVER:
                 opts->render_driver = optarg;
                 break;
