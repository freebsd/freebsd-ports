--- src/cpp/core/r_util/RSessionContext.cpp.orig	2017-11-16 21:40:37 UTC
+++ src/cpp/core/r_util/RSessionContext.cpp
@@ -138,8 +138,8 @@ bool isSharedPath(const std::string& pro
       // not shared if we're in any of the groups that own the directory
       // (note that this checks supplementary group IDs only, so the check
       // against the primary group ID above is still required)
-      if (::group_member(st.st_gid))
-         return false;
+//      if (::group_member(st.st_gid))
+//         return false;
 #endif 
 
       // if we got this far, we likely have access due to project sharing
