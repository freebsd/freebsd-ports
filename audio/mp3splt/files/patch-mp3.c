--- mp3.c.orig	Sun Feb  1 09:28:27 2004
+++ mp3.c	Sun Feb  1 09:29:11 2004
@@ -529,9 +529,10 @@
 				{
 					while (state->bytes < begin)
 					{
+						off_t to_read;
 						if (feof(state->file_input))
 							return -1;
-						off_t to_read = (begin - state->bytes);
+						to_read = (begin - state->bytes);
 						if (to_read > MAD_BSIZE)
 							to_read = MAD_BSIZE;
 						if ((state->data_len = fread(state->inputBuffer, 1, to_read, state->file_input))<=0)
