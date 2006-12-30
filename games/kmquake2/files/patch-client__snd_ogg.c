--- ./client/snd_ogg.c.orig	Sun Apr  9 09:28:58 2006
+++ ./client/snd_ogg.c	Sat Dec 30 01:12:08 2006
@@ -1,4 +1,21 @@
 /*
+* This program is free software; you can redistribute it and/or
+* modify it under the terms of the GNU General Public License
+* as published by the Free Software Foundation; either version 2
+* of the License, or(at your option) any later version.
+* 
+* This program is distributed in the hope that it will be useful,
+* but WITHOUT ANY WARRANTY; without even the implied warranty of
+* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
+* 
+* See the GNU General Public License for more details.
+* 
+* You should have received a copy of the GNU General Public License
+* along with this program; if not, write to the Free Software
+* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
+*/
+
+/*
 ==========================================================
 
   OGG Vorbis decoding
@@ -8,12 +25,9 @@
 
 #include <sys/time.h>
 #include <errno.h>
-
-#include "client.h"
-
-#ifdef OGGVORBIS
 #include <vorbis/vorbisfile.h>
 
+#include "client.h"
 #include "snd_loc.h"
 #include "snd_ogg.h"
 
@@ -22,6 +36,7 @@
 
 qboolean	ogg_first_init = true;	/* First initialization flag. */
 qboolean	ogg_started = false;	/* Initialization flag. */
+byte		*ogg_buffer;		/* File buffer. */
 char		**ogg_filelist;		/* List of Ogg Vorbis files. */
 char		ovBuf[4096];		/* Buffer for sound. */
 int		ogg_curfile;		/* Index of currently played file. */
@@ -29,6 +44,7 @@
 int		ovSection;		/* Position in Ogg Vorbis file. */
 ogg_status_t	ogg_status;		/* Status indicator. */
 cvar_t		*ogg_autoplay;		/* Play this song when started. */
+cvar_t		*ogg_check;		/* Check Ogg files or not. */
 cvar_t		*ogg_playlist;		/* Playlist. */
 cvar_t		*ogg_sequence;		/* Sequence play indicator. */
 cvar_t		*ogg_volume;		/* Music volume. */
@@ -59,6 +75,7 @@
 
 	/* Cvars. */
 	ogg_autoplay = Cvar_Get("ogg_autoplay", "?", CVAR_ARCHIVE);
+	ogg_check = Cvar_Get("ogg_check", "0", CVAR_ARCHIVE);
 	ogg_playlist = Cvar_Get("ogg_playlist", "playlist", CVAR_ARCHIVE);
 	ogg_sequence = Cvar_Get("ogg_sequence", "next", CVAR_ARCHIVE);
 	ogg_volume = Cvar_Get("ogg_volume", "0.7", CVAR_ARCHIVE);
@@ -67,6 +84,7 @@
 	Cmd_AddCommand("ogg_list", OGG_ListCmd);
 	Cmd_AddCommand("ogg_pause", OGG_PauseCmd);
 	Cmd_AddCommand("ogg_play", OGG_PlayCmd);
+	Cmd_AddCommand("ogg_reinit", OGG_Reinit);
 	Cmd_AddCommand("ogg_resume", OGG_ResumeCmd);
 	Cmd_AddCommand("ogg_seek", OGG_SeekCmd);
 	Cmd_AddCommand("ogg_status", OGG_StatusCmd);
@@ -82,6 +100,7 @@
 	/* Check if we have Ogg Vorbis files. */
 	if (ogg_numfiles <= 0) {
 		Com_Printf("No Ogg Vorbis files found.\n");
+		ogg_started = true;	/* For OGG_Shutdown(). */
 		OGG_Shutdown();
 		return;
 	}
@@ -89,6 +108,7 @@
 	/* Initialize variables. */
 	if (ogg_first_init) {
 		srand(time(NULL));
+		ogg_buffer = NULL;
 		ogg_curfile = -1;
 		ogg_status = STOP;
 		ogg_first_init = false;
@@ -112,7 +132,6 @@
 */
 void OGG_Shutdown(void)
 {
-	int i;	/* Loop counter. */
 
 	if (!ogg_started)
 		return;
@@ -122,15 +141,13 @@
 	OGG_Stop();
 
 	/* Free the list of files. */
-	for (i = 0; i < ogg_numfiles; i++)
-		free(ogg_filelist[i]);
-	if (ogg_numfiles > 0)
-		free(ogg_filelist);
+	FS_FreeList(ogg_filelist, ogg_numfiles + 1);
 
 	/* Remove console commands. */
 	Cmd_RemoveCommand("ogg_list");
 	Cmd_RemoveCommand("ogg_pause");
 	Cmd_RemoveCommand("ogg_play");
+	Cmd_RemoveCommand("ogg_reinit");
 	Cmd_RemoveCommand("ogg_resume");
 	Cmd_RemoveCommand("ogg_seek");
 	Cmd_RemoveCommand("ogg_status");
@@ -162,17 +179,21 @@
 */
 qboolean OGG_Check(char *name)
 {
-	qboolean	 res;	/* Return value. */
-	FILE		*fp;	/* File pointer. */
-	OggVorbis_File	 ovf;	/* Ogg Vorbis file. */
+	qboolean	 res;		/* Return value. */
+	byte		*buffer;	/* File buffer. */
+	int		 size;		/* File size. */
+	OggVorbis_File	 ovf;		/* Ogg Vorbis file. */
+
+	if (ogg_check->value == 0)
+		return (true);
 
 	res = false;
-	if ((fp = fopen(name, "r")) != NULL) {
-		if (ov_test(fp, &ovf, NULL, 0) == 0) {
+	if ((size = FS_LoadFile(name, (void**)&buffer)) > 0) {
+		if (ov_test(NULL, &ovf, (char *)buffer, size) == 0) {
 			res = true;
 			ov_clear(&ovf);
-		} else
-			fclose(fp);
+		}
+		FS_FreeFile(buffer);
 	}
 
 	return (res);
@@ -229,23 +250,15 @@
 Load list of Ogg Vorbis files in "music".
 ==========
 */
-void FS_FreeList(char **list, int nfiles);
-char **FS_ListFiles(char *findname, int *numfiles, unsigned musthave, unsigned canthave);
 void OGG_LoadFileList(void)
 {
 	char	**list;			/* List of .ogg files. */
-	char	  oggpath[MAX_OSPATH];	/* Path to .ogg files. */
 	int	  i;			/* Loop counter. */
 	int	  j;			/* Real position in list. */
-	int	  length;		/* Name length. */
 
-	/* Set search path. */
-	strncpy(oggpath, fs_basedir->string, sizeof(oggpath)-1);
-	oggpath[sizeof(oggpath)-1] = '\0';
-	strncat(oggpath, "/music/*.ogg", sizeof(oggpath)-strlen(oggpath)-1);
-	
 	/* Get file list. */
-	list = FS_ListFiles(oggpath, &ogg_numfiles, 0, SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM);
+	list = FS_ListFiles2(va("%s/*.ogg", OGG_DIR), &ogg_numfiles, 0,
+	    SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM);
 	ogg_numfiles--;
 
 	/* Check if there are posible Ogg files. */
@@ -257,17 +270,15 @@
 
 	/* Add valid Ogg Vorbis file to the list. */
 	for (i = 0, j = 0; i < ogg_numfiles; i++) {
-		if (!OGG_Check(list[i]))
+		if (!OGG_Check(list[i])) {
+			free(list[i]);
 			continue;
-		length = strlen(list[j]);
-		ogg_filelist[j] = malloc(length+1);
-		strncpy(ogg_filelist[j], list[j], length);
-		ogg_filelist[j][length] = '\0';
-		j++;
+		}
+		ogg_filelist[j++] = list[i];
 	}
 
 	/* Free the file list. */
-	FS_FreeList(list, ogg_numfiles);
+	free(list);
 
 	/* Adjust the list size (remove space for invalid music files). */
 	ogg_numfiles = j;
@@ -283,54 +294,40 @@
 */
 void OGG_LoadPlaylist(char *playlist)
 {
-	char	*buffer;	/* Buffer to read the file. */
-	char	*name;		/* Name of music file. */
+	byte	*buffer;	/* Buffer to read the file. */
 	char	*ptr;		/* Pointer for parsing the file. */
 	int	 i;		/* Loop counter. */
-	int	 j;		/* Real position in list. */
-	int	 length;	/* Length of buffer and strings. */
-	FILE	*fp;		/* File pointer. */
+	int	 size;		/* Length of buffer and strings. */
 
 	/* Open playlist. */
-	if ((fp = fopen(va("%s/music/%s", fs_basedir->string, playlist), "r")) == NULL) {
+	if ((size = FS_LoadFile(va("%s/%s.lst", OGG_DIR, ogg_playlist->string),
+	    (void **)&buffer)) < 0) {
 		Com_Printf("OGG_LoadPlaylist: could not open playlist: %s.\n", strerror(errno));
 		return;
 	}
 
-	/* Read playlist into buffer. */
-	fseek(fp, 0, SEEK_END);
-	length = ftell(fp);
-	fseek(fp, 0, SEEK_SET);
-	buffer = malloc(length);
-	fread(buffer, length, 1, fp);
-
 	/* Count the files in playlist. */
-	ptr = buffer;
-	while ((name = COM_Parse(&ptr))[0] != '\0')
-		ogg_numfiles++;
+	for (ptr = strtok((char *)buffer, "\n");
+	    ptr != NULL;
+	    ptr = strtok(NULL, "\n")) {
+		if ((byte *)ptr != buffer)
+			ptr[-1] = '\n';
+		if (OGG_Check(va("%s/%s", OGG_DIR, ptr)))
+			ogg_numfiles++;
+	}
 
 	/* Allocate file list. */
 	ogg_filelist = malloc(sizeof(char *) * ogg_numfiles);
 
-	/* Add valid Ogg Vorbis file to the list. */
-	ptr = buffer;
-	for (i = 0, j = 0; i < ogg_numfiles; i++) {
-		name = va("%s/music/%s.ogg", fs_basedir->string, COM_Parse(&ptr));
-		if (!OGG_Check(name))
-			continue;
-		length = strlen(name);
-		ogg_filelist[j] = malloc(length+1);
-		strncpy(ogg_filelist[j], name, length);
-		ogg_filelist[j][length] = '\0';
-		j++;
-	}
-
-	/* Adjust the list size (remove space for invalid music files). */
-	ogg_numfiles = j;
-	ogg_filelist = realloc(ogg_filelist, sizeof(char *) * ogg_numfiles);
+	i = 0;
+	for (ptr = strtok((char *)buffer, "\n");
+	    ptr != NULL;
+	    ptr = strtok(NULL, "\n"))
+		if (OGG_Check(va("%s/%s", OGG_DIR, ptr)))
+			ogg_filelist[i++] = strdup(va("%s/%s", OGG_DIR, ptr));
 
 	/* Free file buffer. */
-	free(buffer);
+	FS_FreeFile(buffer);
 }
 
 /*
@@ -342,9 +339,9 @@
 */
 qboolean OGG_Open(ogg_seek_t type, int offset)
 {
-	int	 pos;	/* Absolute position. */
-	int	 res;	/* Error indicator. */
-	FILE	*fp;	/* File pointer. */
+	int		 size;		/* File size. */
+	int		 pos;		/* Absolute position. */
+	int		 res;		/* Error indicator. */
 
 	pos = -1;
 
@@ -378,15 +375,15 @@
 	}
 
 	/* Find file. */
-	if ((fp = fopen(ogg_filelist[pos], "r")) == NULL) {
+	if ((size = FS_LoadFile(ogg_filelist[pos], (void **)&ogg_buffer)) == -1) {
 		Com_Printf("OGG_Open: could not open %d (%s): %s.\n", pos, ogg_filelist[pos], strerror(errno));
 		return (false);
 	}
 
 	/* Open ogg vorbis file. */
-	if ((res = ov_open(fp, &ovFile, NULL, 0)) < 0) {
+	if ((res = ov_open(NULL, &ovFile, (char *)ogg_buffer, size)) < 0) {
 		Com_Printf("OGG_Open: '%s' is not a valid Ogg Vorbis file (error %i).\n", ogg_filelist[pos], res);
-		fclose(fp);
+		FS_FreeFile(ogg_buffer);
 		return (false);
 	}
 
@@ -395,9 +392,8 @@
 	ogg_curfile = pos;
 	ogg_status = PLAY;
 
-	//OGG_StatusCmd();
 	Com_Printf("Playing file %d '%s'\n", pos, ogg_filelist[pos]);
-	
+
 	return (true);
 }
 
@@ -413,7 +409,7 @@
 	char	*name;	/* File name. */
 	int	 i;	/* Loop counter. */
 
-	name = va("%s/music/%s.ogg", fs_basedir->string, filename);
+	name = va("%s/%s.ogg", OGG_DIR, filename);
 
 	for (i = 0; i < ogg_numfiles; i++)
 		if (strcmp(name, ogg_filelist[i]) == 0)
@@ -482,11 +478,19 @@
 Stop playing the current file.
 ==========
 */
-void OGG_Stop( void )
+void OGG_Stop(void)
 {
 
+	if (ogg_status == STOP)
+		return;
+
 	ov_clear(&ovFile);
 	ogg_status = STOP;
+
+	if (ogg_buffer != NULL) {
+		FS_FreeFile(ogg_buffer);
+		ogg_buffer = NULL;
+	}
 }
 
 /*
@@ -498,6 +502,7 @@
 */
 void OGG_Stream(void)
 {
+
 	if (!ogg_started)
 		return;
 
@@ -617,9 +622,6 @@
 {
 	int i;
 
-	if (!ogg_started)
-		return;
-
 	for (i = 0; i < ogg_numfiles; i++)
 		Com_Printf("%d %s\n", i+1, ogg_filelist[i]);
 
@@ -687,9 +689,6 @@
 void OGG_PlayCmd( void )
 {
 
-	if (!ogg_started)
-		return;
-
 	if (Cmd_Argc() < 2) {
 		Com_Printf("Usage: ogg_play {filename | #n | ? | >n | <n}\n");
 		return;
@@ -722,6 +721,9 @@
 void OGG_SeekCmd(void)
 {
 
+	if (ogg_status != STOP)
+		return;
+
 	if (Cmd_Argc() < 2) {
 		Com_Printf("Usage: ogg_seek {n | <n | >n}\n");
 		return;
@@ -760,9 +762,11 @@
 		    ogg_curfile+1, ogg_filelist[ogg_curfile], ov_time_tell(&ovFile));
 		break;
 	case STOP:
-		Com_Printf("Stopped file %d (%s).\n",
-		    ogg_curfile+1, ogg_filelist[ogg_curfile]);
+		if (ogg_curfile == -1)
+			Com_Printf("Stopped.\n");
+		else
+			Com_Printf("Stopped file %d (%s).\n",
+			    ogg_curfile+1, ogg_filelist[ogg_curfile]);
 		break;
 	}
 }
-#endif
