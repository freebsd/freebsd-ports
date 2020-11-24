--- src/frame.c.orig	2002-05-25 22:04:48 UTC
+++ src/frame.c
@@ -69,31 +69,31 @@ isheader (unsigned char head[4])
 {
   if ((head[0] == 0xff) && ((head[1] & 0xe0) != 0xe0))
     { 
-      sprintf(log.buf, "%s: No syncbits found at the start of header %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
+      sprintf(mp3asm_log.buf, "%s: No syncbits found at the start of header %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
       print_log (10);
       return (0);
     }
   if ((head[1] & 0x18) == 0x08)
     {
-      sprintf(log.buf, "%s: Bad mpeg audio version specified in %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
+      sprintf(mp3asm_log.buf, "%s: Bad mpeg audio version specified in %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
       print_log (10);
       return (0);
     }
   if (!(head[1] & 0x06))
     {
-      sprintf(log.buf, "%s: Bad mpeg layer specified in %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
+      sprintf(mp3asm_log.buf, "%s: Bad mpeg layer specified in %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
       print_log (10);
       return (0);
     }
   if ((head[2] & 0xf0) == 0xf0)
     {
-      sprintf(log.buf, "%s: No valid bitrate specified in %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
+      sprintf(mp3asm_log.buf, "%s: No valid bitrate specified in %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
       print_log (10);
       return (0); 
     }
   if ((head[2] & 0x0c) == 0x0c)
     {
-      sprintf(log.buf, "%s: No valid sampling frequency specified in %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
+      sprintf(mp3asm_log.buf, "%s: No valid sampling frequency specified in %x%x%x%x.\n", me, head[0], head[1], head[2], head[3]);
       print_log (10);
       return (0); 
     }
@@ -129,7 +129,7 @@ search_first_header (buffer_t *buffer, stream_t *strea
     switch (read_buf(buffer, head, i, 4))
       {
       case 0:
-	sprintf(log.buf, "%s: No valid mp3header found in this buffer.\n", me);
+	sprintf(mp3asm_log.buf, "%s: No valid mp3header found in this buffer.\n", me);
 	print_log (10);
  	return(-1); /* fill the buffer */
 	
@@ -140,7 +140,7 @@ search_first_header (buffer_t *buffer, stream_t *strea
 	      {
 		if (samestream (head, (*heads)[k].head))
 		  {
-		    sprintf (log.buf, "other header: %x.%x.%x.%x, count = %d\n", (*heads)[k].head[0], (*heads)[k].head[1], (*heads)[k].head[2], (*heads)[k].head[3], (*heads)[k].count);
+		    sprintf (mp3asm_log.buf, "other header: %x.%x.%x.%x, count = %d\n", (*heads)[k].head[0], (*heads)[k].head[1], (*heads)[k].head[2], (*heads)[k].head[3], (*heads)[k].count);
 		    print_log (10);
 		    if ((*heads)[k].count == 3)
 		      {
@@ -167,7 +167,7 @@ search_first_header (buffer_t *buffer, stream_t *strea
 	break;
 	
       default:
-	sprintf(log.buf, "%s: Unable to read from buffer.\n", me);
+	sprintf(mp3asm_log.buf, "%s: Unable to read from buffer.\n", me);
 	print_all (0);
 	return(-2); /* flush the buffer */
       }
@@ -190,7 +190,7 @@ search_header (buffer_t *buffer, stream_t *stream)
     switch (read_buf(buffer, head, i, 4))
       {
       case 0:
-	sprintf(log.buf, "%s: No valid mp3header found in this buffer.\n", me);
+	sprintf(mp3asm_log.buf, "%s: No valid mp3header found in this buffer.\n", me);
 	print_log (10);
 	return(-1); /* fill the buffer */
 	
@@ -209,7 +209,7 @@ search_header (buffer_t *buffer, stream_t *stream)
 	break;
 	
       default:
-	sprintf(log.buf, "%s: Unable to read from buffer.\n", me);
+	sprintf(mp3asm_log.buf, "%s: Unable to read from buffer.\n", me);
 	print_all (0);
 	return(-2); /* flush the buffer */
       }
@@ -301,7 +301,7 @@ parse_frame_header (stream_t *stream)
 {
   frame_t *frame = stream->last;
 
-  sprintf (log.buf, "%x.%x.%x.%x\n", frame->head[0], frame->head[1], frame->head[2], frame->head[3]);
+  sprintf (mp3asm_log.buf, "%x.%x.%x.%x\n", frame->head[0], frame->head[1], frame->head[2], frame->head[3]);
   print_log (10);
   
   if (stream->count < 0)
@@ -483,10 +483,10 @@ read_frame (stream_t *stream, buffer_t *filebuf, buffe
   
   parse_frame_header(stream);
   
-  sprintf (log.buf, "Reading frame %ld\n", stream->count + 1);
+  sprintf (mp3asm_log.buf, "Reading frame %ld\n", stream->count + 1);
   print_log (10);  
 #ifdef FRAME_DEBUG
-  sprintf(log.buf, "Frame %ld: %d kbps, header to header size = %d\n", stream->count + 1, frame->kbps, frame->hsize);
+  sprintf(mp3asm_log.buf, "Frame %ld: %d kbps, header to header size = %d\n", stream->count + 1, frame->kbps, frame->hsize);
   print_log (10);
 #endif
   
@@ -518,14 +518,14 @@ read_frame (stream_t *stream, buffer_t *filebuf, buffe
 	}	
       
 #ifdef SIDE_DEBUG
-      sprintf(log.buf, "sideinfo = ");
+      sprintf(mp3asm_log.buf, "sideinfo = ");
       print_log (10);
       for ( k = 0; k < stream->isize; k++)
 	{
-	  sprintf(log.buf, ".%x", frame->info[k]);
+	  sprintf(mp3asm_log.buf, ".%x", frame->info[k]);
 	  print_log (10);
 	}
-      sprintf(log.buf, " \n");
+      sprintf(mp3asm_log.buf, " \n");
       print_log (10);
 #endif  
       
@@ -545,7 +545,7 @@ read_frame (stream_t *stream, buffer_t *filebuf, buffe
 
       if (temp)
 	{
-	  sprintf (log.buf, "Too much space between headers: %d bytes!\n", temp);
+	  sprintf (mp3asm_log.buf, "Too much space between headers: %d bytes!\n", temp);
 	  print_all (0);
 	  cut_buf(filebuf, databuf, temp);
 	}
@@ -553,13 +553,13 @@ read_frame (stream_t *stream, buffer_t *filebuf, buffe
       rem_buf(filebuf, 4 + stream->isize + 2 * stream->crc);
 
 #ifdef FRAME_DEBUG
-      sprintf(log.buf, "            Backref: %d, datasize: %d\n", frame->backref, frame->dsize);
+      sprintf(mp3asm_log.buf, "            Backref: %d, datasize: %d\n", frame->backref, frame->dsize);
       print_log (10);
 #endif
 
       if (databuf->used < frame->backref)
 	{
-	  sprintf(log.buf, "Error: bad stream formattin, bad backref!\n");
+	  sprintf(mp3asm_log.buf, "Error: bad stream formattin, bad backref!\n");
 	  print_all (0);
           frame->dsize = 0;
 	 /* free_frame (stream, frame);
@@ -575,7 +575,7 @@ read_frame (stream_t *stream, buffer_t *filebuf, buffe
       
       if (databuf->used < frame->dsize) /*skip frame data!!!*/
 	{
-	  sprintf(log.buf, "Error: bad stream formattin, databuffer underrun.\n");
+	  sprintf(mp3asm_log.buf, "Error: bad stream formattin, databuffer underrun.\n");
  	  print_all (0);
           frame->dsize = 0;
 	 /* free_frame (stream, frame);
@@ -590,7 +590,7 @@ read_frame (stream_t *stream, buffer_t *filebuf, buffe
     }
 
 #ifdef POINTER_DEBUG
-  sprintf (log.buf, "frame %ld; prev: %p, next: %p, info: %p, data: %p\n", stream->count + 1, frame->prev, frame->next, frame->info, frame->data);
+  sprintf (mp3asm_log.buf, "frame %ld; prev: %p, next: %p, info: %p, data: %p\n", stream->count + 1, frame->prev, frame->next, frame->info, frame->data);
   print_log (10);
 #endif
 
@@ -613,7 +613,7 @@ process_frames (stream_t *stream, long startframe, lon
   unsigned long count = 0;
 
 #ifdef POINTER_DEBUG
-      sprintf (log.buf, "frame %ld; prev: %p, next: %p, info: %p, data: %p\n", count, frame->prev, frame->next, frame->info, frame->data);
+      sprintf (mp3asm_log.buf, "frame %ld; prev: %p, next: %p, info: %p, data: %p\n", count, frame->prev, frame->next, frame->info, frame->data);
       print_log (10);
 #endif /* POINTER_DEBUG */
   
@@ -632,7 +632,7 @@ process_frames (stream_t *stream, long startframe, lon
 	      frame = NULL;
 	    }
 	  stream->count--;
-          sprintf (log.buf, "Removed frame %ld\n", count);
+          sprintf (mp3asm_log.buf, "Removed frame %ld\n", count);
 	    print_log (10);
 	}
       else
@@ -785,7 +785,7 @@ calc_backref (stream_t *stream)
 		frame->info[0] |= backref;
 	    }
 #ifdef FRAME_DEBUG	  
-	  sprintf (log.buf, "frame %d: hsize: %d, dsize: %d, backref: %d\n", count, frame->hsize, frame->dsize, frame->backref);
+	  sprintf (mp3asm_log.buf, "frame %d: hsize: %d, dsize: %d, backref: %d\n", count, frame->hsize, frame->dsize, frame->backref);
 	  print_log (10);
 #endif	  
 	  backref += (frame->hsize - 4 - stream->isize - frame->dsize);
@@ -794,7 +794,7 @@ calc_backref (stream_t *stream)
 	    backref = limit;
 	  else if (backref < 0)
 	    {
-	      sprintf (log.buf, "Unable to decently format stream, frame size (%d) exceeds available space (%d)\n", frame->dsize, frame->dsize + backref);
+	      sprintf (mp3asm_log.buf, "Unable to decently format stream, frame size (%d) exceeds available space (%d)\n", frame->dsize, frame->dsize + backref);
 	      print_log (2);
 
 	      if ((limit - highest + backref) < 0) /* local underrun */
@@ -863,7 +863,7 @@ write_frames (stream_t *stream, FILE *file)
 	{
 	  count = frame->hsize;
 #ifdef WRITE_DEBUG
-	  sprintf (log.buf, "FRAME: %d\n", fcount);
+	  sprintf (mp3asm_log.buf, "FRAME: %d\n", fcount);
 	  print_log (10);
 #endif
 	  write_buf (frame->head, framebuf, 4);
@@ -871,7 +871,7 @@ write_frames (stream_t *stream, FILE *file)
 	  write_buf (frame->info, framebuf, stream->isize);
 	  count -= stream->isize;
 #ifdef WRITE_DEBUG
-	  sprintf (log.buf, "wrote header & sideinfo (%d) to framebuf\n", 4 + stream->isize);
+	  sprintf (mp3asm_log.buf, "wrote header & sideinfo (%d) to framebuf\n", 4 + stream->isize);
 	  print_log (10);
 #endif
   
@@ -888,7 +888,7 @@ write_frames (stream_t *stream, FILE *file)
 		      backref -= temp;
 		      count -= temp;
 #ifdef WRITE_DEBUG
-		      sprintf (log.buf, "wrote %d null bytes to framebuf (backref = %d, count = %d)\n", temp, backref, count);
+		      sprintf (mp3asm_log.buf, "wrote %d null bytes to framebuf (backref = %d, count = %d)\n", temp, backref, count);
 		      print_log (10);
 #endif
 		    }
@@ -900,7 +900,7 @@ write_frames (stream_t *stream, FILE *file)
 		      offset += count;
 		      backref -= count;
 #ifdef WRITE_DEBUG
-		      sprintf (log.buf, "wrote %d bytes from data to framebuf (backref = %d, offset = %d, count = 0)\n", count, backref, offset);
+		      sprintf (mp3asm_log.buf, "wrote %d bytes from data to framebuf (backref = %d, offset = %d, count = 0)\n", count, backref, offset);
 		      print_log (10);
 #endif
 		      count = 0;
@@ -913,28 +913,28 @@ write_frames (stream_t *stream, FILE *file)
 		      backref -= temp;
 		      count -= temp;
 #ifdef WRITE_DEBUG
-		      sprintf (log.buf, "wrote %d bytes from data to framebuf (backref = %d, count = %d)\n", temp, backref, count);
+		      sprintf (mp3asm_log.buf, "wrote %d bytes from data to framebuf (backref = %d, count = %d)\n", temp, backref, count);
 		      print_log (10);
 #endif
 		    }
 		}
 	      backref += (dataframe->hsize - stream->isize - 4);
 #ifdef WRITE_DEBUG
-	      sprintf (log.buf, "backref: %d\n", backref);
+	      sprintf (mp3asm_log.buf, "backref: %d\n", backref);
 	      print_log (10);
 #endif
 	      dataframe = dataframe->next;
 	      offset = 0;
 	      dfcount++;
 #ifdef WRITE_DEBUG
-	      sprintf (log.buf, "DATAFRAME: %d\n", dfcount);
+	      sprintf (mp3asm_log.buf, "DATAFRAME: %d\n", dfcount);
 	      print_log (10);
 #endif
 	    }
 	  if (!dataframe && count)
 	    {
 	      write_buf (padding, framebuf, count);	    
-	      sprintf (log.buf, "padded frame %d with %d null bytes\n", fcount, count);
+	      sprintf (mp3asm_log.buf, "padded frame %d with %d null bytes\n", fcount, count);
 	      print_log (10);
 	    }
 	  write_file_from_buf (framebuf, file, frame->hsize);
