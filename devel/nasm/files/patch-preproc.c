
$FreeBSD$

--- preproc.c.orig
+++ preproc.c
@@ -528,7 +528,7 @@
 	    fname++;
 	fnlen = strcspn(fname, "\"");
 	line = nasm_malloc(20 + fnlen);
-	sprintf(line, "%%line %d %.*s", lineno, fnlen, fname);
+	snprintf(line, 20+fnlen,"%%line %d %.*s", lineno, fnlen, fname);
 	nasm_free(oldline);
     }
     if (tasm_compatible_mode)
@@ -833,6 +833,7 @@
 	    type = TOK_STRING;
 	    while (*p && *p != c)
 		p++;
+
 	    if (*p)
 	    {
 		p++;
@@ -840,6 +841,8 @@
 	    else
 	    {
 		error(ERR_WARNING, "unterminated string");
+		/* Handling unterminated strings by UNV */
+		/* type = -1; */
 	    }
 	}
 	else if (isnumstart(*p))
@@ -901,6 +904,15 @@
 	    }
 	    p++;
 	}
+
+	/* Handling unterminated string by UNV */
+	/*if (type == -1)
+	{
+	    *tail = t = new_Token(NULL, TOK_STRING, line, p-line+1);
+	    t->text[p-line] = *line;
+	    tail = &t->next;
+	}
+	else*/
 	if (type != TOK_COMMENT)
 	{
 	    *tail = t = new_Token(NULL, type, line, p - line);
@@ -919,20 +931,20 @@
 static void *
 new_Block(size_t size)
 {
-	Blocks *b = &blocks;
+    Blocks *b = &blocks;
 	
-	/* first, get to the end of the linked list	 */
-	while (b->next)
-		b = b->next;
-	/* now allocate the requested chunk */
-	b->chunk = nasm_malloc(size);
+    /* first, get to the end of the linked list */
+    while (b->next)
+	b = b->next;
+    /* now allocate the requested chunk */
+    b->chunk = nasm_malloc(size);
 	
-	/* now allocate a new block for the next request */
-	b->next = nasm_malloc(sizeof(Blocks));
-	/* and initialize the contents of the new block */
-	b->next->next = NULL;
-	b->next->chunk = NULL;
-	return b->chunk;
+    /* now allocate a new block for the next request */
+    b->next = nasm_malloc(sizeof(Blocks));
+    /* and initialize the contents of the new block */
+    b->next->next = NULL;
+    b->next->chunk = NULL;
+    return b->chunk;
 }
 
 /*
@@ -941,22 +953,22 @@
 static void
 delete_Blocks(void)
 {
-	Blocks *a,*b = &blocks;
+    Blocks *a,*b = &blocks;
 
-	/* 
-	 * keep in mind that the first block, pointed to by blocks
-	 * is a static and not dynamically allocated, so we don't 
-	 * free it.
-	 */
-	while (b)
-	{
-		if (b->chunk)
-			nasm_free(b->chunk);
-		a = b;
-		b = b->next;
-                if (a != &blocks)
-			nasm_free(a);
-	}
+    /* 
+     * keep in mind that the first block, pointed to by blocks
+     * is a static and not dynamically allocated, so we don't 
+     * free it.
+     */
+    while (b)
+    {
+	if (b->chunk)
+	    nasm_free(b->chunk);
+	a = b;
+	b = b->next;
+	if (a != &blocks)
+	    nasm_free(a);
+    }
 }	
 
 /*
@@ -1043,7 +1055,7 @@
 		char *p, *q = t->text + 2;
 
 		q += strspn(q, "$");
-		sprintf(buffer, "..@%lu.", ctx->number);
+		snprintf(buffer, sizeof(buffer), "..@%lu.", ctx->number);
 		p = nasm_strcat(buffer, q);
 		nasm_free(t->text);
 		t->text = p;
@@ -1520,23 +1532,30 @@
 		    t = t->next;
 		    continue;
 		}
-		else if (tt->type == TOK_WHITESPACE)
+		if (tt->type == TOK_WHITESPACE)
 		{
 		    tt = tt->next;
 		    continue;
 		}
-		else if (tt->type != t->type ||
-			mstrcmp(tt->text, t->text, casesense))
+		if (tt->type != t->type)
 		{
 		    j = FALSE;	/* found mismatching tokens */
 		    break;
 		}
-		else
+		/* Unify surrounding quotes for strings */
+		if (t->type == TOK_STRING)
 		{
-		    t = t->next;
-		    tt = tt->next;
-		    continue;
+		    tt->text[0] = t->text[0];
+		    tt->text[strlen(tt->text) - 1] = t->text[0];
 		}
+		if (mstrcmp(tt->text, t->text, casesense) != 0)
+		{
+		    j = FALSE;	/* found mismatching tokens */
+		    break;
+		}
+
+		t = t->next;
+		tt = tt->next;
 	    }
 	    if ((t->type != TOK_OTHER || strcmp(t->text, ",")) || tt)
 		j = FALSE;	/* trailing gunk on one end or other */
@@ -1954,7 +1973,7 @@
 		free_tlist(tt);
 
 		/* Now define the macro for the argument */
-		sprintf(directive, "%%define %s (%s+%d)", arg, StackPointer,
+		snprintf(directive, sizeof(directive), "%%define %s (%s+%d)", arg, StackPointer,
 			offset);
 		do_directive(tokenise(directive));
 		offset += size;
@@ -2051,13 +2070,13 @@
 		free_tlist(tt);
 
 		/* Now define the macro for the argument */
-		sprintf(directive, "%%define %s (%s-%d)", local, StackPointer,
+		snprintf(directive, sizeof(directive), "%%define %s (%s-%d)", local, StackPointer,
 			offset);
 		do_directive(tokenise(directive));
 		offset += size;
 
 		/* Now define the assign to setup the enter_c macro correctly */
-		sprintf(directive, "%%assign %%$localsize %%$localsize+%d",
+		snprintf(directive, sizeof(directive), "%%assign %%$localsize %%$localsize+%d",
 			size);
 		do_directive(tokenise(directive));
 
@@ -3182,12 +3201,12 @@
 			 */
 		    case '0':
 			type = TOK_NUMBER;
-			sprintf(tmpbuf, "%d", mac->nparam);
+			snprintf(tmpbuf, sizeof(tmpbuf), "%d", mac->nparam);
 			text = nasm_strdup(tmpbuf);
 			break;
 		    case '%':
 			type = TOK_ID;
-			sprintf(tmpbuf, "..@%lu.", mac->unique);
+			snprintf(tmpbuf, sizeof(tmpbuf), "..@%lu.", mac->unique);
 			text = nasm_strcat(tmpbuf, t->text + 2);
 			break;
 		    case '-':
@@ -4067,7 +4086,7 @@
 	return;
 
     va_start(arg, fmt);
-    vsprintf(buff, fmt, arg);
+    vsnprintf(buff, sizeof(buff), fmt, arg);
     va_end(arg);
 
     if (istk && istk->mstk && istk->mstk->name)
@@ -4530,7 +4549,7 @@
 make_tok_num(Token * tok, long val)
 {
     char numbuf[20];
-    sprintf(numbuf, "%ld", val);
+    snprintf(numbuf, sizeof(numbuf), "%ld", val);
     tok->text = nasm_strdup(numbuf);
     tok->type = TOK_NUMBER;
 }
