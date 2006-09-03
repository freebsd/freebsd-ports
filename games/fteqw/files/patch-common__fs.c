--- ./common/fs.c.orig	Tue Jul 18 00:34:40 2006
+++ ./common/fs.c	Sat Sep  2 19:18:59 2006
@@ -2051,7 +2051,7 @@
 	case FS_GAMEONLY:	//OS access only, no paks
 		if (*com_homedir)
 		{
-			snprintf(fullname, sizeof(fullname), "%s%s/%s", com_homedir, gamedirfile, filename);
+			snprintf(fullname, sizeof(fullname), "%s/%s/%s", com_homedir, gamedirfile, filename);
 			vfs = VFSOS_Open(fullname, mode);
 			if (vfs)
 				return vfs;
@@ -2060,7 +2060,7 @@
 		return VFSOS_Open(fullname, mode);
 	case FS_GAME:
 		if (*com_homedir)
-			snprintf(fullname, sizeof(fullname), "%s%s/%s", com_homedir, gamedirfile, filename);
+			snprintf(fullname, sizeof(fullname), "%s/%s/%s", com_homedir, gamedirfile, filename);
 		else
 			snprintf(fullname, sizeof(fullname), "%s%s/%s", com_quakedir, gamedirfile, filename);
 		break;
@@ -2073,7 +2073,7 @@
 	case FS_BASE:
 		if (*com_homedir)
 		{
-			snprintf(fullname, sizeof(fullname), "%s%s", com_homedir, filename);
+			snprintf(fullname, sizeof(fullname), "%s/%s", com_homedir, filename);
 			vfs = VFSOS_Open(fullname, mode);
 			if (vfs)
 				return vfs;
@@ -2083,7 +2083,7 @@
 	case FS_CONFIGONLY:
 		if (*com_homedir)
 		{
-			snprintf(fullname, sizeof(fullname), "%sfte/%s", com_homedir, filename);
+			snprintf(fullname, sizeof(fullname), "%s/fte/%s", com_homedir, filename);
 			vfs = VFSOS_Open(fullname, mode);
 			if (vfs)
 				return vfs;
