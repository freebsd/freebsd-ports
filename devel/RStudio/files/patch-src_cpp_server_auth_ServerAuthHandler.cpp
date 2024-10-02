- workaround for the std:bad_cast exception in the licensed user info retrievel code
- that isn't even used on FreeBSD
- see https://github.com/rstudio/rstudio/issues/12377
- resolution: the offending function's body is commented out for the time being

--- src/cpp/server/auth/ServerAuthHandler.cpp.orig	2023-08-28 18:24:18 UTC
+++ src/cpp/server/auth/ServerAuthHandler.cpp
@@ -383,6 +383,7 @@ Error getUserFromDatabase(const boost::shared_ptr<ICon
                           boost::posix_time::ptime* pLastSignin,
                           bool* pExists)
 {
+#if 0
    LOG_DEBUG_MESSAGE("Getting user from database: " + user.getUsername());
    
    *pLocked = true;
@@ -439,6 +440,10 @@ Error getUserFromDatabase(const boost::shared_ptr<ICon
    }
 
    *pExists = foundUser;
+#endif
+
+   *pExists = false;
+
    return Success();
 }
 
