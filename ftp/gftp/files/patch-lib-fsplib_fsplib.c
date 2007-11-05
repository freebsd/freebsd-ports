--- lib/fsplib/fsplib.c.orig	2005-01-19 03:03:45.000000000 +0100
+++ lib/fsplib/fsplib.c	2007-11-05 16:37:32.000000000 +0100
@@ -612,7 +612,7 @@
     entry->d_reclen = fentry.reclen;
     strncpy(entry->d_name,fentry.name,MAXNAMLEN);
 
-    if (fentry.namlen > MAXNAMLEN)
+    if (fentry.namlen >= MAXNAMLEN)
     {
 	entry->d_name[MAXNAMLEN + 1 ] = '\0';
 #ifdef HAVE_NAMLEN
@@ -680,9 +680,19 @@
        /* skip file date and file size */
        dir->dirpos += 9;
        /* read file name */
-       entry->name[255 + 1] = '\0';
+       entry->name[255] = '\0';
        strncpy(entry->name,(char *)( dir->data + dir->dirpos ),MAXNAMLEN);
+       /* check for ASCIIZ encoded filename */
+       if (memchr(dir->data + dir->dirpos,0,dir->datasize - dir->dirpos) != NULL)
+       {
        namelen = strlen( (char *) dir->data+dir->dirpos);
+       }
+       else
+       {
+            /* \0 terminator not found at end of filename */
+            *result = NULL;
+            return 0;
+       }
        /* skip over file name */
        dir->dirpos += namelen +1;
 
@@ -709,12 +719,12 @@
 
 struct dirent * fsp_readdir(FSP_DIR *dirp)
 {
-    static struct dirent entry;
+    static dirent_workaround entry;
     struct dirent *result;
     
     
     if (dirp == NULL) return NULL;
-    if ( fsp_readdir_r(dirp,&entry,&result) )
+    if ( fsp_readdir_r(dirp,&entry.dirent,&result) )
         return NULL;
     else
         return result;
