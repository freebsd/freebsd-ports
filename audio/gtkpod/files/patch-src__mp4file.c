--- ./src/mp4file.c.orig	2010-07-13 12:23:59.000000000 +0100
+++ ./src/mp4file.c	2010-07-13 12:39:31.000000000 +0100
@@ -132,6 +132,8 @@
 /* define metadata bug is present (see note at mp4_write_file_info()) */
 #define MP4V2_HAS_METADATA_BUG TRUE
 
+#define HAVE_LIBMP4V2_19X 1
+
 #include <sys/types.h>
 #include <sys/param.h>
 #include <inttypes.h>
@@ -399,7 +401,7 @@
 #else
 #warning "Album Artist field not supported with this version of libmp4v2. Album Artist support requires at least V1.6.0"
 #endif
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 		    if (MP4GetMetadataComposer(mp4File, &value) && value != NULL)
 #else
 		    if (MP4GetMetadataWriter(mp4File, &value) && value != NULL)
@@ -413,7 +415,7 @@
 			track->comment = charset_to_utf8 (value);
 			g_free(value);
 		    }
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 		    if (MP4GetMetadataReleaseDate(mp4File, &value) && value != NULL)
 #else
 		    if (MP4GetMetadataYear(mp4File, &value) && value != NULL)
@@ -447,7 +449,7 @@
 			track->genre = charset_to_utf8 (value);
 			g_free(value);
 		    }
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 		    if (MP4GetMetadataBPM (mp4File, &numvalue))
 #else
 		    if (MP4GetMetadataTempo (mp4File, &numvalue))
@@ -541,7 +543,7 @@
 						      &m_track, &m_tracks);
 	    gboolean has_disk = MP4GetMetadataDisk (mp4File,
 	    &m_disk, &m_disks);*/
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 	    gboolean has_tempo = MP4GetMetadataBPM (mp4File,
 						      &m_tempo);
 #else
@@ -553,13 +555,13 @@
 /*	    MP4GetMetadataName (mp4File, &m_name);
 	    MP4GetMetadataArtist (mp4File, &m_artist);
 	    MP4GetMetadataAlbumArtist (mp4File, &m_albumartist);
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 	    MP4GetMetadataComposer (mp4File, &m_writer);
 #else
 	    MP4GetMetadataWriter (mp4File, &m_writer);
 #endif
 	    MP4GetMetadataComment (mp4File, &m_comment);
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 	    MP4GetMetadataReleaseDate (mp4File, &m_year);
 #else
 	    MP4GetMetadataYear (mp4File, &m_year);
@@ -584,7 +586,7 @@
 	    g_free (value);
 #endif
 	    value = charset_from_utf8 (track->composer);
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 	    MP4SetMetadataComposer (mp4File, value);
 #else
 	    MP4SetMetadataWriter (mp4File, value);
@@ -596,7 +598,7 @@
 	    g_free (value);
 
 	    value = g_strdup_printf ("%d", track->year);
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 	    MP4SetMetadataReleaseDate (mp4File, value);
 #else
 	    MP4SetMetadataYear (mp4File, value);
@@ -611,7 +613,7 @@
 
 	    MP4SetMetadataDisk (mp4File, track->cd_nr, track->cds);
 
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 	    MP4SetMetadataBPM (mp4File, track->BPM);
 #else
 	    MP4SetMetadataTempo (mp4File, track->BPM);
@@ -626,7 +628,7 @@
 	    g_free (value);
 
 #if MP4V2_HAS_METADATA_BUG
-#if HAVE_LIBMP4V2_2
+#if HAVE_LIBMP4V2_2 && !HAVE_LIBMP4V2_19X
 	    if (has_tempo) MP4SetMetadataBPM (mp4File, m_tempo);
 #else
 	    if (has_tempo) MP4SetMetadataTempo (mp4File, m_tempo);
