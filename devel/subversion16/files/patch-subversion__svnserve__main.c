--- ./subversion/svnserve/main.c.orig	2013-09-02 21:08:27.000000000 +0200
+++ ./subversion/svnserve/main.c	2013-09-02 21:11:37.000000000 +0200
@@ -317,8 +317,10 @@
   const char *contents = apr_psprintf(pool, "%" APR_PID_T_FMT "\n",
                                              getpid());
 
+/* CVE-2013-4277 fix */
+  SVN_ERR(svn_io_remove_file(filename, pool));
   SVN_ERR(svn_io_file_open(&file, filename,
-                           APR_WRITE | APR_CREATE | APR_TRUNCATE,
+                           APR_WRITE | APR_CREATE | APR_EXCL,
                            APR_OS_DEFAULT, pool));
   SVN_ERR(svn_io_file_write_full(file, contents, strlen(contents), NULL,
                                  pool));
