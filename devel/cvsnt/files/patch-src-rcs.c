--- src/rcs.c.orig	Thu Jan 29 06:12:24 2004
+++ src/rcs.c	Sun Feb 22 03:30:20 2004
@@ -6600,7 +6600,7 @@
 		{
 			struct binbuffer *bb;
 		} binary;
-	};
+	} u;
 };
 
 static void linevector_init (struct linevector *vec);
@@ -6637,30 +6637,30 @@
 		int n = 0, ln;
 		char *p;
 
-		for (ln = 0; ln < lines->text.nlines; ++ln)
+		for (ln = 0; ln < lines->u.text.nlines; ++ln)
 			/* 1 for \n */
-			n += lines->text.vector[ln]->len + 1;
+			n += lines->u.text.vector[ln]->len + 1;
 
 		lv.is_binary = 1;
-		lv.binary.bb=(struct binbuffer*)xmalloc(sizeof(struct binbuffer));
-		memset(lv.binary.bb,0,sizeof(struct binbuffer));
-		p = lv.binary.bb->buffer = xmalloc (n);
-		lv.binary.bb->refcount=1;
+		lv.u.binary.bb=(struct binbuffer*)xmalloc(sizeof(struct binbuffer));
+		memset(lv.u.binary.bb,0,sizeof(struct binbuffer));
+		p = lv.u.binary.bb->buffer = xmalloc (n);
+		lv.u.binary.bb->refcount=1;
 
-		for (ln = 0; ln < lines->text.nlines; ++ln)
+		for (ln = 0; ln < lines->u.text.nlines; ++ln)
 		{
-			memcpy (p, lines->text.vector[ln]->text,
-				lines->text.vector[ln]->len);
-			p += lines->text.vector[ln]->len;
-			if (lines->text.vector[ln]->has_newline)
+			memcpy (p, lines->u.text.vector[ln]->text,
+				lines->u.text.vector[ln]->len);
+			p += lines->u.text.vector[ln]->len;
+			if (lines->u.text.vector[ln]->has_newline)
 			*p++ = '\n';
 		}
-		assert ((p-((char*)lv.binary.bb->buffer))==n);
+		assert ((p-((char*)lv.u.binary.bb->buffer))==n);
 		linevector_free(lines);
 		memcpy(lines,&lv,sizeof(struct linevector));
 	}
 
-	if(cvsdelta_patch(lines->binary.bb->buffer,lines->binary.bb->length,diffbuf,difflen,&tmpbuf->binary.bb->buffer,&tmpbuf->binary.bb->length,&tmpbuf->binary.bb->reserved))
+	if(cvsdelta_patch(lines->u.binary.bb->buffer,lines->u.binary.bb->length,diffbuf,difflen,&tmpbuf->u.binary.bb->buffer,&tmpbuf->u.binary.bb->length,&tmpbuf->u.binary.bb->reserved))
 		error(1,0,"Binary patch failed");
 
 	t = *lines;
@@ -6704,18 +6704,18 @@
 	if(is_binary)
 	{
 		assert(!pos);
-		if(vec->text.vector || vec->text.lines_alloced)
+		if(vec->u.text.vector || vec->u.text.lines_alloced)
 		{
 			error(1,0,"Attempting binary operation on text linevector");
 		}
 
 		vec->is_binary=1;
-		vec->binary.bb=(struct binbuffer *)xmalloc(sizeof(struct binbuffer));
-		vec->binary.bb->buffer = xmalloc(len);
-		vec->binary.bb->length = len;
-		vec->binary.bb->reserved = len;
-		vec->binary.bb->refcount=1;
-		memcpy(vec->binary.bb->buffer,text,len);
+		vec->u.binary.bb=(struct binbuffer *)xmalloc(sizeof(struct binbuffer));
+		vec->u.binary.bb->buffer = xmalloc(len);
+		vec->u.binary.bb->length = len;
+		vec->u.binary.bb->reserved = len;
+		vec->u.binary.bb->refcount=1;
+		memcpy(vec->u.binary.bb->buffer,text,len);
 		return 1;
 	}
 
@@ -6733,29 +6733,29 @@
  		    ++nnew;
 
     /* Expand VEC->VECTOR if needed.  */
-    if (vec->text.nlines + nnew >= vec->text.lines_alloced)
+    if (vec->u.text.nlines + nnew >= vec->u.text.lines_alloced)
     {
-	if (vec->text.lines_alloced == 0)
-	    vec->text.lines_alloced = 10;
-	while (vec->text.nlines + nnew >= vec->text.lines_alloced)
-	    vec->text.lines_alloced *= 3;
-	vec->text.vector = xrealloc (vec->text.vector,
-				vec->text.lines_alloced * sizeof (*vec->text.vector));
+	if (vec->u.text.lines_alloced == 0)
+	    vec->u.text.lines_alloced = 10;
+	while (vec->u.text.nlines + nnew >= vec->u.text.lines_alloced)
+	    vec->u.text.lines_alloced *= 3;
+	vec->u.text.vector = xrealloc (vec->u.text.vector,
+				vec->u.text.lines_alloced * sizeof (*vec->u.text.vector));
     }
 
-    /* Make room for the new lines in vec->text.VECTOR.  */
-   if(vec->text.nlines && pos < vec->text.nlines)
-     memmove(vec->text.vector + pos + nnew, vec->text.vector + pos, sizeof(vec->text.vector[0]) * (vec->text.nlines - pos));
-/*    for (i = vec->text.nlines + nnew - 1; i >= pos + nnew; --i)
-	vec->text.vector[i] = vec->text.vector[i - nnew];
+    /* Make room for the new lines in vec->u.text.VECTOR.  */
+   if(vec->u.text.nlines && pos < vec->u.text.nlines)
+     memmove(vec->u.text.vector + pos + nnew, vec->u.text.vector + pos, sizeof(vec->u.text.vector[0]) * (vec->u.text.nlines - pos));
+/*    for (i = vec->u.text.nlines + nnew - 1; i >= pos + nnew; --i)
+	vec->u.text.vector[i] = vec->text.vector[i - nnew];
 */
-    if (pos > vec->text.nlines)
+    if (pos > vec->u.text.nlines)
     {
-	error(0,0,"Dropping data: pos>vec->text.nlines");
+	error(0,0,"Dropping data: pos>vec->u.text.nlines");
 	return 0;
     }
 
-    /* Actually add the lines, to vec->text.VECTOR.  */
+    /* Actually add the lines, to vec->u.text.VECTOR.  */
     i = pos;
     nextline_text = text;
     nextline_newline = 0;
@@ -6776,7 +6776,7 @@
 	    q->has_newline = nextline_newline;
 	    q->refcount = 1;
 	    memcpy (q->text, nextline_text, nextline_len);
-	    vec->text.vector[i++] = q;
+	    vec->u.text.vector[i++] = q;
 
 	    nextline_text = (char *)p + 1;
 	    nextline_newline = 0;
@@ -6790,9 +6790,9 @@
     q->has_newline = nextline_newline;
     q->refcount = 1;
     memcpy (q->text, nextline_text, nextline_len);
-    vec->text.vector[i] = q;
+    vec->u.text.vector[i] = q;
 
-    vec->text.nlines += nnew;
+    vec->u.text.nlines += nnew;
 
     return 1;
 }
@@ -6807,15 +6807,15 @@
     register unsigned int i;
     unsigned int last;
 
-    last = vec->text.nlines - nlines;
+    last = vec->u.text.nlines - nlines;
     for (i = pos; i < pos + nlines; ++i)
     {
-	if (--vec->text.vector[i]->refcount == 0)
-	    xfree (vec->text.vector[i]);
+	if (--vec->u.text.vector[i]->refcount == 0)
+	    xfree (vec->u.text.vector[i]);
     }
-    if(nlines && (i < vec->text.nlines))
-       memmove(vec->text.vector + pos, vec->text.vector + pos + nlines, sizeof(vec->text.vector[0]) * (vec->text.nlines - i));
-    vec->text.nlines -= nlines;
+    if(nlines && (i < vec->u.text.nlines))
+       memmove(vec->u.text.vector + pos, vec->u.text.vector + pos + nlines, sizeof(vec->u.text.vector[0]) * (vec->u.text.nlines - i));
+    vec->u.text.nlines -= nlines;
 }
 
 
@@ -6828,32 +6828,32 @@
 		linevector_free(to);
     if(from->is_binary)
     {
-		from->binary.bb->refcount++;
+		from->u.binary.bb->refcount++;
 		linevector_free(to);
 		to->is_binary=1;
-		to->binary.bb=from->binary.bb;
+		to->u.binary.bb=from->u.binary.bb;
     }
     else
     {
-      for (ln = 0; ln < to->text.nlines; ++ln)
+      for (ln = 0; ln < to->u.text.nlines; ++ln)
       {
-	if (--to->text.vector[ln]->refcount == 0)
-	    xfree (to->text.vector[ln]);
+	if (--to->u.text.vector[ln]->refcount == 0)
+	    xfree (to->u.text.vector[ln]);
       }
-      if (from->text.nlines > to->text.lines_alloced)
+      if (from->u.text.nlines > to->u.text.lines_alloced)
       {
-	if (to->text.lines_alloced == 0)
-	    to->text.lines_alloced = 10;
-	while (from->text.nlines > to->text.lines_alloced)
-	    to->text.lines_alloced *= 2;
-	to->text.vector = (struct line **)
-	    xrealloc (to->text.vector, to->text.lines_alloced * sizeof (*to->text.vector));
+	if (to->u.text.lines_alloced == 0)
+	    to->u.text.lines_alloced = 10;
+	while (from->u.text.nlines > to->u.text.lines_alloced)
+	    to->u.text.lines_alloced *= 2;
+	to->u.text.vector = (struct line **)
+	    xrealloc (to->u.text.vector, to->u.text.lines_alloced * sizeof (*to->u.text.vector));
       }
-      memcpy (to->text.vector, from->text.vector,
-	    from->text.nlines * sizeof (*to->text.vector));
-      to->text.nlines = from->text.nlines;
-      for (ln = 0; ln < to->text.nlines; ++ln)
-	++to->text.vector[ln]->refcount;
+      memcpy (to->u.text.vector, from->u.text.vector,
+	    from->u.text.nlines * sizeof (*to->u.text.vector));
+      to->u.text.nlines = from->u.text.nlines;
+      for (ln = 0; ln < to->u.text.nlines; ++ln)
+	++to->u.text.vector[ln]->refcount;
     }
 }
 
@@ -6864,23 +6864,23 @@
 
 	if(vec->is_binary)
 	{
-		if(vec->binary.bb && !vec->binary.bb->refcount--)
+		if(vec->u.binary.bb && !vec->u.binary.bb->refcount--)
 		{
-			xfree(vec->binary.bb->buffer);
-			xfree(vec->binary.bb);
+			xfree(vec->u.binary.bb->buffer);
+			xfree(vec->u.binary.bb);
 		}
 		else
-			vec->binary.bb=NULL;
+			vec->u.binary.bb=NULL;
 	}
 	else
 	{
-		if (vec->text.vector != NULL)
+		if (vec->u.text.vector != NULL)
 		{
-			for (ln = 0; ln < vec->text.nlines; ++ln)
-				if (--vec->text.vector[ln]->refcount == 0)
-				xfree (vec->text.vector[ln]);
+			for (ln = 0; ln < vec->u.text.nlines; ++ln)
+				if (--vec->u.text.vector[ln]->refcount == 0)
+				xfree (vec->u.text.vector[ln]);
 
-			xfree (vec->text.vector);
+			xfree (vec->u.text.vector);
 		}
 	}
 }
@@ -6944,7 +6944,7 @@
 	if(lines->is_binary)
 	{
 		struct linevector lv = {0};
-		linevector_add(&lv,lines->binary.bb->buffer,lines->binary.bb->length,delvers,0,0);
+		linevector_add(&lv,lines->u.binary.bb->buffer,lines->u.binary.bb->length,delvers,0,0);
 		linevector_free(lines);
 		lv=*lines;
 	}
@@ -7025,12 +7025,12 @@
 		return 0;
 	    break;
 	case FRAG_DELETE:
-	    if (df->pos > lines->text.nlines
-		|| df->pos + df->nlines > lines->text.nlines)
+	    if (df->pos > lines->u.text.nlines
+		|| df->pos + df->nlines > lines->u.text.nlines)
 		return 0;
 	    if (delvers != NULL)
 		for (ln = df->pos; ln < df->pos + df->nlines; ++ln)
-		    lines->text.vector[ln]->vers = delvers;
+		    lines->u.text.vector[ln]->vers = delvers;
 	    linevector_delete (lines, df->pos, df->nlines);
 	    break;
 	}
@@ -7084,18 +7084,18 @@
 	unsigned int ln;
 
 	n = 0;
-	for (ln = 0; ln < lines.text.nlines; ++ln)
+	for (ln = 0; ln < lines.u.text.nlines; ++ln)
 	    /* 1 for \n */
-	    n += lines.text.vector[ln]->len + 1;
+	    n += lines.u.text.vector[ln]->len + 1;
 
 	p = xmalloc (n);
 	*retbuf = p;
 
-	for (ln = 0; ln < lines.text.nlines; ++ln)
+	for (ln = 0; ln < lines.u.text.nlines; ++ln)
 	{
-	    memcpy (p, lines.text.vector[ln]->text, lines.text.vector[ln]->len);
-	    p += lines.text.vector[ln]->len;
-	    if (lines.text.vector[ln]->has_newline)
+	    memcpy (p, lines.u.text.vector[ln]->text, lines.u.text.vector[ln]->len);
+	    p += lines.u.text.vector[ln]->len;
+	    if (lines.u.text.vector[ln]->has_newline)
 		*p++ = '\n';
 	}
 
@@ -7303,13 +7303,13 @@
 				else if(STREQ(deltatype,"binary") || STREQ(deltatype,"compressed_binary"))
 				{
 					/* If we've been copied, disconnect the copy */
-					if(!binbuf.binary.bb || binbuf.binary.bb->refcount>1)
+					if(!binbuf.u.binary.bb || binbuf.u.binary.bb->refcount>1)
 					{
-						if(binbuf.binary.bb)
-							binbuf.binary.bb->refcount--;
-						binbuf.binary.bb=(struct binbuffer*)xmalloc(sizeof(struct binbuffer));
-						memset(binbuf.binary.bb,0,sizeof(struct binbuffer));
-						binbuf.binary.bb->refcount=1;
+						if(binbuf.u.binary.bb)
+							binbuf.u.binary.bb->refcount--;
+						binbuf.u.binary.bb=(struct binbuffer*)xmalloc(sizeof(struct binbuffer));
+						memset(binbuf.u.binary.bb,0,sizeof(struct binbuffer));
+						binbuf.u.binary.bb->refcount=1;
 					}
 					if (! apply_binary_changes(&curlines, &binbuf, value, vallen))
 						error(1,0,"invalid binary delta text in %s", fn_root(rcs->path));
@@ -7364,8 +7364,8 @@
 		      /* Reset the version information we have
                          accumulated so far.  It only applies to the
                          changes from the head to this version.  */
-		      for (ln = 0; ln < curlines.text.nlines; ++ln)
-		        curlines.text.vector[ln]->vers = NULL;
+		      for (ln = 0; ln < curlines.u.text.nlines; ++ln)
+		        curlines.u.text.vector[ln]->vers = NULL;
 		    }
 		}
 
@@ -7423,7 +7423,7 @@
 		if(headlines.is_binary)
 			error(1,0,"Cannot annotate a binary delta");
 
-		for (ln = 0; ln < headlines.text.nlines; ++ln)
+		for (ln = 0; ln < headlines.u.text.nlines; ++ln)
 		{
 		    char buf[80];
 		    /* Period which separates year from month in date.  */
@@ -7432,7 +7432,7 @@
 		    char *md;
 		    RCSVers *prvers;
 
-		    prvers = headlines.text.vector[ln]->vers;
+		    prvers = headlines.u.text.vector[ln]->vers;
 		    if (prvers == NULL)
 			prvers = vers;
 
@@ -7474,9 +7474,9 @@
 			cvs_output (ym - 2, 2);
 		    }
 		    cvs_output ("): ", 0);
-		    if (headlines.text.vector[ln]->len != 0)
-			cvs_output (headlines.text.vector[ln]->text,
-				    headlines.text.vector[ln]->len);
+		    if (headlines.u.text.vector[ln]->len != 0)
+			cvs_output (headlines.u.text.vector[ln]->text,
+				    headlines.u.text.vector[ln]->len);
 		    cvs_output ("\n", 1);
 		}
 	    }
@@ -7492,25 +7492,25 @@
 
 		if(headlines.is_binary)
 		{
-			p = xmalloc(headlines.binary.bb->length);
+			p = xmalloc(headlines.u.binary.bb->length);
 			*text = p;
-			*len = headlines.binary.bb->length;
-			memcpy(p, headlines.binary.bb->buffer,headlines.binary.bb->length);
+			*len = headlines.u.binary.bb->length;
+			memcpy(p, headlines.u.binary.bb->buffer,headlines.u.binary.bb->length);
 		}
 		else
 		{
 			n = 0;
-			for (ln = 0; ln < headlines.text.nlines; ++ln)
+			for (ln = 0; ln < headlines.u.text.nlines; ++ln)
 				/* 1 for \n */
-				n += headlines.text.vector[ln]->len + 1;
+				n += headlines.u.text.vector[ln]->len + 1;
 			p = xmalloc (n);
 			*text = p;
-			for (ln = 0; ln < headlines.text.nlines; ++ln)
+			for (ln = 0; ln < headlines.u.text.nlines; ++ln)
 			{
-				memcpy (p, headlines.text.vector[ln]->text,
-					headlines.text.vector[ln]->len);
-				p += headlines.text.vector[ln]->len;
-				if (headlines.text.vector[ln]->has_newline)
+				memcpy (p, headlines.u.text.vector[ln]->text,
+					headlines.u.text.vector[ln]->len);
+				p += headlines.u.text.vector[ln]->len;
+				if (headlines.u.text.vector[ln]->has_newline)
 				*p++ = '\n';
 			}
 			*len = p - *text;
