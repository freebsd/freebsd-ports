--- scripts/editor.sl.orig	Mon Jun  7 16:07:23 1999
+++ scripts/editor.sl	Sat Jan  6 21:23:30 2001
@@ -35,6 +35,13 @@
      {
 	irc_edit_insert_pos--;
 	buf = chop_last(irc_buffer);
+#ifdef KANJI
+      if(iskanji(irc_buffer[irc_edit_insert_pos]))
+        {
+           irc_edit_insert_pos--;
+           buf = substr(irc_buffer, 1, irc_edit_insert_pos);
+        }
+#endif
 	irc_set_buffer(buf);
      }
    else
@@ -42,6 +49,14 @@
 	irc_edit_insert_pos--;
 	buf = substr(irc_buffer, 1, irc_edit_insert_pos)
 	    + substr(irc_buffer, irc_edit_insert_pos + 2, -1);
+#ifdef KANJI
+      if(iskanji(irc_buffer[irc_edit_insert_pos]))
+        {
+           irc_edit_insert_pos--;
+           buf = substr(irc_buffer, 1, irc_edit_insert_pos)
+             + substr(irc_buffer, irc_edit_insert_pos + 3, -1);
+        }
+#endif
 	irc_set_buffer(buf);
      }
      !if(irc_edit_insert_pos)
@@ -67,10 +82,25 @@
 	   if(ch <  0x0a0) return; % ISO-LATIN-1 are 0xa0-0xff
    }
    variable buf;
+#ifdef KANJI
+   variable keysym;
+#endif
    if(irc_edit_insert_pos >= strlen(irc_buffer))
      {
+#ifdef KANJI
+	buf = irc_buffer + char(ch);
+	irc_edit_insert_pos = strlen(buf);
+	if (iskanji(ch))
+	  {
+	     keysym = irc_get_input();
+	     buf = irc_buffer + char(ch) + char(keysym);
+	     irc_edit_insert_pos = strlen(buf);
+	  }
+	irc_set_buffer(buf);
+#else
 	irc_set_buffer(irc_buffer + char(ch));
 	irc_edit_insert_pos = strlen(irc_buffer);
+#endif
      }
    else
      {
@@ -78,12 +108,30 @@
 	  {
 	     buf = char(ch) + irc_buffer;
 	     irc_edit_insert_pos = 1;
+#ifdef KANJI
+	     if (iskanji(ch))
+	       {
+		  keysym = irc_get_input();
+		  buf = char(ch) + char(keysym) + irc_buffer;
+		  irc_edit_insert_pos = 2;
+	       }
+#endif
 	  }
 	else
 	  {
 	     buf = substr(irc_buffer, 1, irc_edit_insert_pos)
 		 + char(ch)
 		 + substr(irc_buffer, irc_edit_insert_pos + 1, -1);
+#ifdef KANJI
+	     if (iskanji(ch))
+	       {
+		  keysym = irc_get_input();
+		  buf = substr(irc_buffer, 1, irc_edit_insert_pos)
+		    + char(ch) + char(keysym)
+		    + substr(irc_buffer, irc_edit_insert_pos + 1, -1);
+		  irc_edit_insert_pos++;
+	       }
+#endif
 	     irc_edit_insert_pos++;
 	  }
 	irc_set_buffer(buf);
@@ -96,10 +144,20 @@
 {
    if(irc_edit_insert_pos > 0)
      irc_edit_insert_pos --;
+#ifdef KANJI
+   if(irc_edit_insert_pos > 0)
+     if(iskanji(irc_buffer[irc_edit_insert_pos]))
+       irc_edit_insert_pos--;
+#endif
 }
 
 define do_scroll_right()
 {
+#ifdef KANJI
+   if(irc_edit_insert_pos < strlen(irc_buffer))
+     if(iskanji(irc_buffer[irc_edit_insert_pos]))
+       irc_edit_insert_pos++;
+#endif
    if(irc_edit_insert_pos < strlen(irc_buffer))
      irc_edit_insert_pos++;
 }
