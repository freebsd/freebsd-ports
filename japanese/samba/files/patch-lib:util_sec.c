Index: lib/util_sec.c
===================================================================
RCS file: /project/cvs/samba22-ja/source/lib/util_sec.c,v
retrieving revision 1.4
diff -u -r1.4 util_sec.c
--- lib/util_sec.c	21 Nov 2002 12:53:49 -0000	1.4
+++ lib/util_sec.c	21 Jan 2004 01:31:37 -0000
@@ -283,6 +283,10 @@
 
 void restore_re_gid(void)
 {
+	uid_t uid = geteuid();
+
+	set_effective_uid(0);
+
 #if USE_SETRESUID
 	setresgid(saved_rgid, saved_egid, -1);
 #elif USE_SETREUID
@@ -298,6 +302,7 @@
 	set_effective_gid(saved_egid);
 #endif
 
+	set_effective_uid(uid);
 	assert_gid(saved_rgid, saved_egid);
 }
 
