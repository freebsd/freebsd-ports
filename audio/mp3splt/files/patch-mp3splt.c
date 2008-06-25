--- mp3splt.c.orig	2008-06-25 00:19:32.000000000 -0400
+++ mp3splt.c	2008-06-25 00:20:37.000000000 -0400
@@ -114,6 +114,13 @@
 		if (state->mstate) {
 			fclose(state->mstate->file_input);
 			mp3_state_free(state->mstate);
+			  /*
+			   * Explicitly setting mstate to NULL
+			   * prevents encoding misdetection (resulting
+			   * in a crash) if an mp3 file is followed by
+			   * a vorbis file.
+			   */
+			state->mstate = NULL;
 		}
 #ifndef NO_OGG
 		else if (state->ostate) { // If file has been opened with ov_open we should close it using ov_clear()
