--- src/mod/share.mod/share.c	2010-02-18 10:52:30.000000000 +0100
+++ src/mod/share.mod/share.c	2011-01-07 06:22:16.000000000 +0100
@@ -1122,7 +1122,7 @@
   int i, sock;
   FILE *f;
 
-  egg_snprintf(s, sizeof s, ".share.%s.%li.users", botnetnick, now);
+  egg_snprintf(s, sizeof s, "%s/.share.%s.%li.users", tempdir, botnetnick, now);
   if (!(b_status(idx) & STAT_SHARE)) {
     dprintf(idx, "s e You didn't ask; you just started sending.\n");
     dprintf(idx, "s e Ask before sending the userfile.\n");
@@ -1891,8 +1891,8 @@
   struct chanuserrec *ch;
   struct chanset_t *cst;
 
-  egg_snprintf(share_file, sizeof share_file, ".share.%s.%lu", dcc[idx].nick,
-               now);
+  egg_snprintf(share_file, sizeof share_file, "%s/.share.%s.%lu",
+		  tempdir, dcc[idx].nick, now);
   if (dcc[idx].u.bot->uff_flags & UFF_OVERRIDE) {
     debug1("NOTE: Sharing aggressively with %s, overriding its local bots.",
            dcc[idx].nick);
