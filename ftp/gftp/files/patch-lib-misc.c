Fix segmentation fault, when gftpui_run_chdir is called with directory=0x0,
and then calls gftp_expand_path (src=0x0), 
the NULL string was cloned using g_strdup, which returns NULL if 
its only argument is NULL, then this returned string was unreferenced.

 lib/misc.c |    2 ++
 1 files changed, 2 insertions(+), 0 deletions(-)

--- lib/misc.c.orig	2022-02-15 06:31:19 UTC
+++ lib/misc.c
@@ -145,6 +145,8 @@ char * gftp_expand_path (gftp_request * request, const
        tempchar;
   struct passwd *pw;
 
+  g_return_val_if_fail(src != NULL, NULL);
+
   pw = NULL;
   str = g_strdup (src);
 
