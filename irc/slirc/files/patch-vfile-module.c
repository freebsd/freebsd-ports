--- ./vfile-module.c.orig	2008-08-11 21:49:04.000000000 +0000
+++ ./vfile-module.c	2008-08-11 22:25:20.246320000 +0000
@@ -97,13 +97,13 @@
 	int ct;
 
 	if (at->data_type != SLANG_CHAR_TYPE) {
-		SLang_doerror("Operation requires character array");
+		SLang_verror(SL_INTRINSIC_ERROR, "Operation requires character array");
 		return -1;
 	}
 
 	if (len<0) ct = at->num_elements;
 	else if (len > at->num_elements) {
-		SLang_doerror("Too much data for array size");
+		SLang_verror(SL_INTRINSIC_ERROR, "Too much data for array size");
 		return -1;
 	}else ct = len;
 	*data = at->data;
@@ -446,11 +446,11 @@
 
 	VFerrno = 0;
 	if (t->fd < 0) {
-		/* SLang_doerror("file already closed"); */
+		/* SLang_verror(SL_INTRINSIC_ERROR,"file already closed"); */
 		r = 0; goto return_r;
 	}
 	if (t->rdvf || t->wrvf) {
-		SLang_doerror("You must set_wrdep(*,*,0) before close");
+		SLang_verror(SL_INTRINSIC_ERROR, "You must set_wrdep(*,*,0) before close");
 		goto return_r;
 	}
 	r = close(t->fd);
@@ -1171,7 +1171,7 @@
 
 	l = t->rbuft - t->rbufr;
 	if (l <= 0) { /* shouldn't happen */
-		SLang_doerror("read_into_buf() called with window=0");
+		SLang_verror(SL_INTRINSIC_ERROR,"read_into_buf() called with window=0");
 		return -1;
 	}
 	if (t->fd < 0 || t->flags & SJ_EOF) return 0; /* also shouldn't happen */
@@ -1209,7 +1209,7 @@
 
 	if (!l || t->rtermn < 0 || !(m = t->rbufr - t->rbufq)) goto dflt_ret;
 	if (t->rbufq < t->rbufp) {
-		SLang_doerror("q<p");
+		SLang_verror(SL_INTRINSIC_ERROR, "q<p");
 		t->rbufq = t->rbufp;
 	}
 	if ( (cp = (char*)memchr(t->rbufq,t->rtermn,m))
@@ -1259,7 +1259,7 @@
 
 /*fprintf(stderr,"fd=%d, rthrsh=%d, bytes=%d\n",t->fd,t->rthrsh,t->rbufr-t->rbufp); */
 	if (t->fd < 0) {
-		SLang_doerror("Read on closed VFile");
+		SLang_verror(SL_INTRINSIC_ERROR, "Read on closed VFile");
 		goto return_r;
 	}
 
@@ -1364,7 +1364,7 @@
 	
 	if (!(mmt = pop_vfd(SJ_WRITE, &t))) goto free_fail; /* ct = -1 */
 	if (t->fd < 0) {
-		SLang_doerror("Write on closed VFile");
+		SLang_verror(SL_INTRINSIC_ERROR, "Write on closed VFile");
 		goto free_fail;
 	}
 
@@ -1420,7 +1420,7 @@
 	if (!(wr_mmt = pop_vfd(SJ_WRITE, &wt))) goto free1;
 
 	if (wt != rt->wrvf || rt != wt->rdvf) {
-		SLang_doerror("copybytes filepair not linked by set_wrdep()");
+		SLang_verror(SL_INTRINSIC_ERROR, "copybytes filepair not linked by set_wrdep()");
 		goto free2;
 	}
 
@@ -1469,7 +1469,7 @@
 	if (!(mmt = pop_vfd(SJ_READ, &t))) return -1; /* ct = -1 */
 
 	if (t->fd < 0) {
-		SLang_doerror("Read on closed VFile");
+		SLang_verror(SL_INTRINSIC_ERROR,"Read on closed VFile");
 		r = -1; goto return_r;
 	}
 	r = check_buf_data(t);
@@ -1672,7 +1672,7 @@
 		fnt = SLang_get_function(func_name);
 		if (!fnt) {r = -2; goto return_r;}
 		if (t->fd < 0) {
-			SLang_doerror("Can't set_action() on closed VFile");
+			SLang_verror(SL_INTRINSIC_ERROR,"Can't set_action() on closed VFile");
 			r = -3; goto return_r;
 		}
 	}
@@ -1720,7 +1720,7 @@
 		) return -1;
 
 	if (t->flags & SJ_UDP) {
-		SLang_doerror("only default (unbuffered) rmode makes sense for UDP");
+		SLang_verror(SL_INTRINSIC_ERROR,"only default (unbuffered) rmode makes sense for UDP");
 		r = -1; goto return_r;
 	}
 
@@ -1729,7 +1729,7 @@
 	if (!ct) {
 		if (t->rthrsh) { /* changing from buffered to unbuffered */
 			if (t->rbufr > t->rbufp) {
-				SLang_doerror("must read data before switching to unbuffered mode");
+				SLang_verror(SL_INTRINSIC_ERROR,"must read data before switching to unbuffered mode");
 				r = -1; goto return_r;
 			}
 			SLfree(t->rbuf0);
@@ -1737,7 +1737,7 @@
 			vfile_list_dirty = 1; /* just t */
 		}
 		if (ch>=0) {
-			SLang_doerror("termination char ignored in unbuffered mode");
+			SLang_verror(SL_INTRINSIC_ERROR,"termination char ignored in unbuffered mode");
 			ch = -1;
 		}
 	}
@@ -1802,12 +1802,12 @@
 	stkdep = _SLstack_depth() - stkdep; /* % items left on stack. */
 	/* for some reason, this next seems to cause segfault when */
 	/* used from ./vf and do_actions() is called in SLang ?!   */
-	if (stkdep && SLang_Error != USER_BREAK) {
+	if (stkdep && USER_BREAK != SLang_get_error()) {
 		SLang_verror(SL_APPLICATION_ERROR,
 		  "Eeek... %s() left %d units on stack",t->fns[i]->name,stkdep);
 		if (stkdep>0) {
 			SLdo_pop_n(stkdep);
-			SLang_Error = 0;  /* probably safe to keep going */
+			SLang_set_error(0);  /* probably safe to keep going */
 		}
 	}
 
@@ -1840,7 +1840,7 @@
 			ct++;
 			do_action_i(t,0);
 			if (t->fd >= 0 && t->fns[0] && rbufp == t->rbufp && check_buf_data(t) >= 0) {
-				SLang_doerror("read-action did not handle data");
+				SLang_verror(SL_INTRINSIC_ERROR,"read-action did not handle data");
 				t->fns[0] = NULL; /* this to radically kill it */
 			}
 		}while (!vfile_list_dirty && t != tn);
@@ -1868,7 +1868,7 @@
 	static fd_set fds[3];  /* a big one, we could malloc */
 
 	if (do_actions_dep++) { /* we are NOT recursive! */
-		SLang_doerror("Can't call do_actions() recursively");
+		SLang_verror(SL_INTRINSIC_ERROR,"Can't call do_actions() recursively");
 		goto return_ct;
 	}
 	/*tim = (int)time(NULL); */
@@ -2133,8 +2133,8 @@
 {
 	SLang_Class_Type *cl;
 
-	if (SLclass_add_typecast(SLANG_CHAR_TYPE, SLANG_INT_TYPE, char_to_int, 1)
-	 || SLclass_add_typecast(SLANG_INT_TYPE, SLANG_CHAR_TYPE, int_to_char, 1))
+        if (SLclass_add_typecast(SLANG_CHAR_TYPE, SLANG_INT_TYPE, char_to_int, 1)
+         || SLclass_add_typecast(SLANG_INT_TYPE, SLANG_CHAR_TYPE, int_to_char, 1))
 	{
 		fprintf(stderr,"VFile: fail add_typecast(CHAR<->INT)\n");
 		return -1;
@@ -2151,8 +2151,9 @@
 
 	if (NULL == (cl = SLclass_allocate_class("VFile_Type")))
 		return -1;
-	cl->cl_destroy = destroy_vfile_type;
-	cl->cl_string = vfile_string;
+	SLclass_set_destroy_function(cl, destroy_vfile_type);
+	SLclass_set_string_function(cl, vfile_string);
+
 	if (-1 == SLclass_register_class(cl, SJ_VFILE_TYPE, sizeof(VFILE), SLANG_CLASS_TYPE_MMT)) 
 		return -1;
 
