--- src/loop.c.orig	2024-12-20 21:57:21 UTC
+++ src/loop.c
@@ -19,7 +19,7 @@ static ssize_t loop_make_probe(u32 uid);
 #ifdef HAVE_LOOP
 static ssize_t loop_make_probe(u32 uid);
 
-void loop_send_probes()
+void loop_send_probes(void)
 {
    struct server *serv;
    struct randfd_list *rfds = NULL;
