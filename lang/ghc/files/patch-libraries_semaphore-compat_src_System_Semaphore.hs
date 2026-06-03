--- libraries/semaphore-compat/src/System/Semaphore.hs.orig	2025-09-10 16:05:58 UTC
+++ libraries/semaphore-compat/src/System/Semaphore.hs
@@ -138,7 +138,7 @@ create_sem sem_str init_toks = do
           { Posix.semCreate    = True
           , Posix.semExclusive = True }
   mb_sem <- MC.try @_ @MC.SomeException $
-    Posix.semOpen sem_str flags Posix.stdFileMode init_toks
+    Posix.semOpen (fixedUpName sem_str) flags Posix.stdFileMode init_toks
   return $ case mb_sem of
     Left  err -> Left $ MC.throwM err
     Right sem -> Right $ mk_sem sem
@@ -162,7 +162,7 @@ openSemaphore nm@(SemaphoreName sem_name) = do
     flags = Posix.OpenSemFlags
           { Posix.semCreate    = False
           , Posix.semExclusive = False }
-  sem <- Posix.semOpen sem_name flags Posix.stdFileMode 0
+  sem <- Posix.semOpen (fixedUpName sem_name) flags Posix.stdFileMode 0
 #endif
   return $
     Semaphore
@@ -216,7 +216,7 @@ destroySemaphore sem =
 #if defined(mingw32_HOST_OS)
   Win32.closeHandle (Win32.semaphoreHandle $ semaphore sem)
 #else
-  Posix.semUnlink (getSemaphoreName $ semaphoreName sem)
+  Posix.semUnlink (fixedUpName $ getSemaphoreName $ semaphoreName sem)
 #endif
 
 -- | Query the current semaphore value (how many tokens it has available).
@@ -351,3 +351,14 @@ random_strings = do
   CClock t <- Posix.systemTime <$> Posix.getProcessTimes
 #endif
   return $ fmap ( \ i -> iToBase62 (i + fromIntegral t) ) (0 :| [1..])
+
+fixedUpName :: String -> String
+#if !defined(freebsd_HOST_OS)
+fixedUpName = id
+#else
+-- On FreeBSD the semaphore name has to start with '/'
+-- and not have any more '/' inside
+fixedUpName ('/':rest) = '/' : filter (/= '/') rest
+fixedUpName (notSlash:rest) = '/':notSlash:filter (/= '/') rest
+fixedUpName n = n
+#endif
