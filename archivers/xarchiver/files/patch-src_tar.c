--- src/tar.c.orig	2016-03-09 15:25:48 UTC
+++ src/tar.c
@@ -330,7 +330,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -349,7 +349,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -368,7 +368,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -387,7 +387,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -406,7 +406,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -425,7 +425,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
