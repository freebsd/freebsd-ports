--- gensio.cpp.orig	2014-01-19 19:50:35 UTC
+++ gensio.cpp
@@ -494,7 +494,7 @@ Filter::PipeE::PipeE(GenBuffer::Writable
 
  #if HAVE_PTS_POPEN
   if (!tmpsname) {
-    if (NULLP==(p=popen(redir_cmd(), "w"CFG_PTS_POPEN_B))) Error::sev(Error::EERROR) << "Filter::PipeE" << ": popen() failed: " << (SimBuffer::B().appendDumpC(redir_cmd)) << (Error*)0;
+    if (NULLP==(p=popen(redir_cmd(), "w" CFG_PTS_POPEN_B))) Error::sev(Error::EERROR) << "Filter::PipeE" << ": popen() failed: " << (SimBuffer::B().appendDumpC(redir_cmd)) << (Error*)0;
     signal(SIGPIPE, SIG_IGN); /* Don't abort process with SIGPIPE signals if child cannot read our data */
   } else {
  #else
@@ -622,7 +622,7 @@ slen_t Filter::PipeD::vi_read(char *tobu
   if (state==0) { /* Read the whole stream from `in', write it to `tmpsname' */
    #if HAVE_PTS_POPEN
     if (!tmpsname) {
-      if (NULLP==(p=popen(redir_cmd(), "w"CFG_PTS_POPEN_B))) Error::sev(Error::EERROR) << "Filter::PipeD" << ": popen() failed: " << (SimBuffer::B().appendDumpC(redir_cmd)) << (Error*)0;
+      if (NULLP==(p=popen(redir_cmd(), "w" CFG_PTS_POPEN_B))) Error::sev(Error::EERROR) << "Filter::PipeD" << ": popen() failed: " << (SimBuffer::B().appendDumpC(redir_cmd)) << (Error*)0;
       signal(SIGPIPE, SIG_IGN); /* Don't abort process with SIGPIPE signals if child cannot read our data */
       vi_precopy();
       in.vi_read(0,0);
@@ -731,11 +731,7 @@ slen_t Filter::FlatD::vi_read(char *to_b
 /* --- */
 
 
-#if HAVE_lstat_in_sys_stat
-#  define PTS_lstat lstat
-#else
 #  define PTS_lstat stat
-#endif
 
 /** @param fname must start with '/' (dir separator)
  * @return true if file successfully created
