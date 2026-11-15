--- remoting/base/passwd_utils.h.orig	2026-10-19 21:50:55 UTC
+++ remoting/base/passwd_utils.h
@@ -23,7 +23,7 @@ struct PasswdUserInfo {
   uid_t uid;
   gid_t gid;
   base::FilePath home_dir;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::vector<gid_t> supplementary_gids;
 #endif
 };
