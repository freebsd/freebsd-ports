--- jfsw_src_20051009/source/jaudiolib/unixglob.c.orig	1970-01-01 01:00:00.000000000 +0100
+++ jfsw_src_20051009/source/jaudiolib/unixglob.c	2005-10-10 15:02:08.000000000 +0200
@@ -0,0 +1,152 @@
+/*
+Copyright (C) 2003-2004 Ryan C. Gordon. and James Bentler
+
+This program is free software; you can redistribute it and/or
+modify it under the terms of the GNU General Public License
+as published by the Free Software Foundation; either version 2
+of the License, or (at your option) any later version.
+
+This program is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
+
+See the GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with this program; if not, write to the Free Software
+Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
+
+Originally written by Ryan C. Gordon. (icculus@clutteredmind.org)
+Adapted to work with JonoF's port by James Bentler (bentler@cs.umn.edu)
+
+*/
+
+static char ApogeePath[256] = "/tmp/";
+
+#define PATH_SEP_CHAR '/'
+#define PATH_SEP_STR  "/"
+#define ROOTDIR       "/"
+#define CURDIR        "./"
+
+#include "types.h"
+#include "compat.h"
+#include <dirent.h>
+#include <errno.h>
+
+#define Error printf
+
+#ifndef MAX_PATH
+#define MAX_PATH 256
+#endif
+
+void FixFilePath(char *filename)
+{
+    char *ptr;
+    char *lastsep = filename;
+
+    if ((!filename) || (*filename == '\0'))
+        return;
+
+    if (access(filename, F_OK) == 0)  /* File exists; we're good to go. */
+        return;
+
+    for (ptr = filename; 1; ptr++)
+    {
+        if (*ptr == '\\')
+            *ptr = PATH_SEP_CHAR;
+
+        if ((*ptr == PATH_SEP_CHAR) || (*ptr == '\0'))
+        {
+            char pch = *ptr;
+            struct dirent *dent = NULL;
+            DIR *dir;
+
+            if ((pch == PATH_SEP_CHAR) && (*(ptr + 1) == '\0'))
+                return; /* eos is pathsep; we're done. */
+
+            if (lastsep == ptr)
+                continue;  /* absolute path; skip to next one. */
+
+            *ptr = '\0';
+            if (lastsep == filename) {
+                dir = opendir((*lastsep == PATH_SEP_CHAR) ? ROOTDIR : CURDIR);
+                
+                if (*lastsep == PATH_SEP_CHAR) {
+                    lastsep++;
+                }
+            } 
+            else
+            {
+                *lastsep = '\0';
+                dir = opendir(filename);
+                *lastsep = PATH_SEP_CHAR;
+                lastsep++;
+            }
+
+            if (dir == NULL)
+            {
+                *ptr = PATH_SEP_CHAR;
+                return;  /* maybe dir doesn't exist? give up. */
+            }
+
+            while ((dent = readdir(dir)) != NULL)
+            {
+                if (strcasecmp(dent->d_name, lastsep) == 0)
+                {
+                    /* found match; replace it. */
+                    strcpy(lastsep, dent->d_name);
+                    break;
+                }
+            }
+
+            closedir(dir);
+            *ptr = pch;
+            lastsep = ptr;
+
+            if (dent == NULL)
+                return;  /* no match. oh well. */
+
+            if (pch == '\0')  /* eos? */
+                return;
+        }
+    }
+}
+
+int32 SafeOpenWrite (const char *_filename, int32 filetype)
+{
+   int handle;
+    char filename[MAX_PATH];
+    strncpy(filename, _filename, sizeof (filename));
+    filename[sizeof (filename) - 1] = '\0';
+    FixFilePath(filename);
+
+   handle = open(filename,O_RDWR | O_BINARY | O_CREAT | O_TRUNC
+   , S_IREAD | S_IWRITE);
+
+   if (handle == -1)
+       Error ("Error opening %s: %s",filename,strerror(errno));
+
+   return handle;
+}
+
+
+void SafeWrite (int32 handle, void *buffer, int32 count)
+{
+   unsigned    iocount;
+
+   while (count)
+   {
+       iocount = count > 0x8000 ? 0x8000 : count;
+       if (write (handle,buffer,iocount) != (int)iocount)
+           Error ("File write failure writing %ld bytes",count);
+       buffer = (void *)( (byte *)buffer + iocount );
+       count -= iocount;
+   }
+}
+
+
+
+void GetUnixPathFromEnvironment( char *fullname, int32 length, const char *filename )
+{
+   snprintf(fullname, length-1, "%s%s", ApogeePath, filename);
+}
