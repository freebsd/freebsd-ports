--- src/tar.c.orig	2014-09-28 20:10:38 UTC
+++ src/tar.c
@@ -331,7 +331,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -350,7 +350,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -369,7 +369,7 @@ gboolean xa_tar_extract(XArchive *archiv
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
@@ -382,18 +382,18 @@ gboolean xa_tar_extract(XArchive *archiv
 		case XARCHIVETYPE_TAR_LZMA:
 		if (archive->full_path || multi_extract)
 		{
-			command = g_strconcat (tar, " --use-compress-program=lzma -xvf " , archive->escaped_path,
+			command = g_strconcat (tar, " --use-compress-program='lzma -d' -xvf " , archive->escaped_path,
 						#ifdef __FreeBSD__
 								archive->overwrite ? " " : " -k",
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
 		{
-			result = xa_extract_tar_without_directories ( "tar --use-compress-program=lzma -xvf ",archive,names->str);
+			result = xa_extract_tar_without_directories ( "tar --use-compress-program='lzma -d' -xvf ",archive,names->str);
 			command = NULL;
 		}
 		break;
@@ -401,18 +401,18 @@ gboolean xa_tar_extract(XArchive *archiv
 		case XARCHIVETYPE_TAR_LZOP:
 		if (archive->full_path || multi_extract)
 		{
-			command = g_strconcat (tar, " --use-compress-program=lzop -xvf " , archive->escaped_path,
+			command = g_strconcat (tar, " --use-compress-program='lzop -d' -xvf " , archive->escaped_path,
 						#ifdef __FreeBSD__
 								archive->overwrite ? " " : " -k",
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
 		{
-			result = xa_extract_tar_without_directories ( "tar --use-compress-program=lzop -xvf ",archive,names->str);
+			result = xa_extract_tar_without_directories ( "tar --use-compress-program='lzop -d' -xvf ",archive,names->str);
 			command = NULL;
 		}
 		break;
@@ -420,18 +420,18 @@ gboolean xa_tar_extract(XArchive *archiv
 		case XARCHIVETYPE_TAR_XZ:
 		if (archive->full_path || multi_extract)
 		{
-			command = g_strconcat (tar, " --use-compress-program=xz -xvf " , archive->escaped_path,
+			command = g_strconcat (tar, " --use-compress-program='xz -d' -xvf " , archive->escaped_path,
 						#ifdef __FreeBSD__
 								archive->overwrite ? " " : " -k",
 						#else
 								archive->overwrite ? " --overwrite" : " --keep-old-files",
 						#endif
-								archive->tar_touch ? " --touch" : "",
+								archive->tar_touch ? " -m" : "",
 								" -C ",archive->extraction_path," ",names->str,NULL);
 		}
 		else
 		{
-			result = xa_extract_tar_without_directories ( "tar --use-compress-program=xz -xvf ",archive,names->str);
+			result = xa_extract_tar_without_directories ( "tar --use-compress-program='xz -d' -xvf ",archive,names->str);
 			command = NULL;
 		}
 		break;
@@ -567,7 +567,7 @@ gboolean xa_extract_tar_without_director
 											archive->overwrite ? " --overwrite" : " --keep-old-files",
 											" --no-wildcards ",
 										#endif
-										archive->tar_touch ? " --touch" : "",
+										archive->tar_touch ? " -m" : "",
 										"-C ",archive->tmp," ",files_to_extract,NULL);
 	list = g_slist_append(list,command);
 	if (strstr(files_to_extract,"/") || strcmp(archive->tmp,archive->extraction_path) != 0)
@@ -618,15 +618,15 @@ void xa_tar_test(XArchive *archive)
 		break;
 
 		case XARCHIVETYPE_TAR_LZMA:
-			command = g_strconcat (tar, " --use-compress-program=lzma -tvf ",archive->path, NULL);
+			command = g_strconcat (tar, " --use-compress-program='lzma -d' -tvf ",archive->path, NULL);
 		break;
 
 		case XARCHIVETYPE_TAR_LZOP:
-			command = g_strconcat (tar, " --use-compress-program=lzop -tvf ",archive->path, NULL);
+			command = g_strconcat (tar, " --use-compress-program='lzop -d' -tvf ",archive->path, NULL);
 		break;
 		
 		case XARCHIVETYPE_TAR_XZ:
-			command = g_strconcat (tar, " --use-compress-program=xz -tvf ",archive->path, NULL);
+			command = g_strconcat (tar, " --use-compress-program='xz -d' -tvf ",archive->path, NULL);
 		break;
 
 		case XARCHIVETYPE_LZMA:
