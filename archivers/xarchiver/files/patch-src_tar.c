--- src/tar.c.orig	2016-07-19 21:54:07 UTC
+++ src/tar.c
@@ -334,7 +334,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -353,7 +353,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -372,7 +372,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -391,7 +391,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -410,7 +410,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -429,7 +429,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
