--- libasync.c.orig	2015-10-20 14:12:13 UTC
+++ libasync.c
@@ -96,6 +96,15 @@
 
 #include <sys/types.h>
 #include <aio.h>
+
+#if defined(_LARGEFILE64_SOURCE) && !defined(__LP64__)
+#	define aio_error	aio_error64
+#	define aio_return	aio_return64
+#	define aio_read 	aio_read64
+#	define aio_cancel	aio_cancel64
+#	define aio_write	aio_write64
+#endif
+
 #if defined(solaris) || defined(linux) || defined(SCO_Unixware_gcc) || defined(__NetBSD__)
 #else
 #include <sys/timers.h>
@@ -132,11 +141,15 @@
 #include <strings.h> /* For the BSD string functions */
 #endif
 
-void mbcopy(char *source, char *dest, size_t len);
+static void mbcopy(const char *source, char *dest, size_t len);
 
 
 #if !defined(solaris) && !defined(off64_t) && !defined(_OFF64_T) && !defined(__off64_t_defined) && !defined(SCO_Unixware_gcc)
+#	if defined(bsd4_4)
+typedef off_t off64_t;
+#	else
 typedef long long off64_t;
+#	endif
 #endif
 #if defined(OSFV5)
 #include <string.h>
@@ -150,15 +163,16 @@ extern int one;
  * cache, pointed to by async_init(gc) will be of
  * this structure type.
  */
-char version[] = "Libasync Version $Revision: 3.25 $";
+static const char version[] = "Libasync Version $Revision: 3.25 $";
 struct cache_ent {
-	struct aiocb myaiocb;			/* For use in small file mode */
 #ifdef _LARGEFILE64_SOURCE 
 #if defined(__CrayX1__)
-	aiocb64_t myaiocb64;		/* For use in large file mode */
+	aiocb64_t myaiocb;		/* For use in large file mode */
 #else
-	struct aiocb64 myaiocb64;		/* For use in large file mode */
-#endif 
+	struct aiocb64 myaiocb;		/* For use in large file mode */
+#endif
+#else
+	struct aiocb myaiocb;
 #endif 
 	long long fd;				/* File descriptor */
 	long long size;				/* Size of the transfer */
@@ -191,8 +205,8 @@ struct cache {
 
 long long max_depth;
 extern int errno;
-struct cache_ent *alloc_cache();
-struct cache_ent *incache();
+static struct cache_ent *alloc_cache();
+static struct cache_ent *incache();
 void async_init();
 void end_async();
 int async_suspend();
@@ -274,7 +288,7 @@ async_suspend(struct cache_ent *ce)
 #ifdef __LP64__
 	const struct aiocb * const cblist[1] = {&ce->myaiocb};
 #else
-	const struct aiocb64 * const cblist[1] = {&ce->myaiocb64};
+	const struct aiocb64 * const cblist[1] = {&ce->myaiocb};
 #endif
 #else
 	const struct aiocb * const cblist[1] = {&ce->myaiocb};
@@ -347,89 +361,28 @@ long long depth;
 	 */
 	if((ce=(struct cache_ent *)incache(gc,fd,offset,size)))
 	{
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		while((ret=aio_error(&ce->myaiocb))== EINPROGRESS)
-		{
-			async_suspend(ce);
-		}
-#else
-		while((ret=aio_error64(&ce->myaiocb64))== EINPROGRESS)
-		{
-			async_suspend(ce);
-		}
-#endif
-#else
 		while((ret=aio_error(&ce->myaiocb))== EINPROGRESS)
 		{
 			async_suspend(ce);
 		}
-#endif
 		if(ret)
 		{
-			printf("aio_error 1: ret %d %d\n",ret,errno);
+			printf("aio_error 1: ret %zd %d\n",ret,errno);
 		}
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 		retval=aio_return(&ce->myaiocb);
-#else
-#if defined(__CrayX1__)
-		retval=aio_return64((aiocb64_t *)&ce->myaiocb64);
-#else
-		retval=aio_return64((struct aiocb64 *)&ce->myaiocb64);
-#endif
-
-#endif
-#else
-		retval=aio_return(&ce->myaiocb);
-#endif
 		if(retval > 0)
 		{
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-			mbcopy((char *)ce->myaiocb.aio_buf,(char *)ubuffer,(size_t)retval);
-#else
-			mbcopy((char *)ce->myaiocb64.aio_buf,(char *)ubuffer,(size_t)retval);
-#endif
-#else
 			mbcopy((char *)ce->myaiocb.aio_buf,(char *)ubuffer,(size_t)retval);
-#endif
 		}
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		if(retval < ce->myaiocb.aio_nbytes)
-#else
-		if(retval < ce->myaiocb64.aio_nbytes)
-#endif
-#else
 		if(retval < ce->myaiocb.aio_nbytes)
-#endif
 		{
-			printf("aio_return error1: ret %d %d\n",retval,errno);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-			printf("aio_return error1: fd %d offset %ld buffer %lx size %d Opcode %d\n",
-				ce->myaiocb.aio_fildes,
-				ce->myaiocb.aio_offset,
-				(long)(ce->myaiocb.aio_buf),
-				ce->myaiocb.aio_nbytes,
-				ce->myaiocb.aio_lio_opcode
-#else
-			printf("aio_return error1: fd %d offset %lld buffer %lx size %d Opcode %d\n",
-				ce->myaiocb64.aio_fildes,
-				ce->myaiocb64.aio_offset,
-				(long)(ce->myaiocb64.aio_buf),
-				ce->myaiocb64.aio_nbytes,
-				ce->myaiocb64.aio_lio_opcode
-#endif
-#else
-			printf("aio_return error1: fd %d offset %d buffer %lx size %d Opcode %d\n",
+			printf("aio_return error1: ret %zd %d\n",retval,errno);
+			printf("aio_return error1: fd %d offset %lld buffer %p size %zd Opcode %d\n",
 				ce->myaiocb.aio_fildes,
-				ce->myaiocb.aio_offset,
-				(long)(ce->myaiocb.aio_buf),
+				(long long)ce->myaiocb.aio_offset,
+				ce->myaiocb.aio_buf,
 				ce->myaiocb.aio_nbytes,
 				ce->myaiocb.aio_lio_opcode
-#endif
 				);
 		}
 		ce->direct=0;
@@ -443,21 +396,13 @@ long long depth;
 		del_read++;
 		first_ce=alloc_cache(gc,fd,offset,size,(long long)LIO_READ);
 again:
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		ret=aio_read(&first_ce->myaiocb);
-#else
-		ret=aio_read64(&first_ce->myaiocb64);
-#endif
-#else
 		ret=aio_read(&first_ce->myaiocb);
-#endif
 		if(ret!=0)
 		{
 			if(errno==EAGAIN)
 				goto again;
 			else
-				printf("error returned from aio_read(). Ret %d errno %d\n",ret,errno);
+				printf("error returned from aio_read(). Ret %zd errno %d\n",ret,errno);
 		}
 	}
 	if(stride==0)	 /* User does not want read-ahead */
@@ -482,15 +427,7 @@ again:
 		if((ce=incache(gc,fd,r_offset,a_size)))
 			continue;
 		ce=alloc_cache(gc,fd,r_offset,a_size,(long long)LIO_READ);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		ret=aio_read(&ce->myaiocb);
-#else
-		ret=aio_read64(&ce->myaiocb64);
-#endif
-#else
 		ret=aio_read(&ce->myaiocb);
-#endif
 		if(ret!=0)
 		{
 			takeoff_cache(gc,ce);
@@ -500,83 +437,27 @@ again:
 out:
 	if(del_read)	/* Wait for the first read to complete */
 	{
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 		while((ret=aio_error(&first_ce->myaiocb))== EINPROGRESS)
 		{
 			async_suspend(first_ce);
 		}
-#else
-		while((ret=aio_error64(&first_ce->myaiocb64))== EINPROGRESS)
-		{
-			async_suspend(first_ce);
-		}
-#endif
-#else
-		while((ret=aio_error(&first_ce->myaiocb))== EINPROGRESS)
-		{
-			async_suspend(first_ce);
-		}
-#endif
 		if(ret)
-			printf("aio_error 2: ret %d %d\n",ret,errno);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		retval=aio_return(&first_ce->myaiocb);
-#else
-		retval=aio_return64(&first_ce->myaiocb64);
-#endif
-#else
+			printf("aio_error 2: ret %zd %d\n",ret,errno);
 		retval=aio_return(&first_ce->myaiocb);
-#endif
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		if(retval < first_ce->myaiocb.aio_nbytes)
-#else
-		if(retval < first_ce->myaiocb64.aio_nbytes)
-#endif
-#else
 		if(retval < first_ce->myaiocb.aio_nbytes)
-#endif
 		{
-			printf("aio_return error2: ret %d %d\n",retval,errno);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-			printf("aio_return error2: fd %d offset %lld buffer %lx size %d Opcode %d\n",
-				first_ce->myaiocb.aio_fildes,
-				first_ce->myaiocb.aio_offset,
-				(long)(first_ce->myaiocb.aio_buf),
-				first_ce->myaiocb.aio_nbytes,
-				first_ce->myaiocb.aio_lio_opcode
-#else
-			printf("aio_return error2: fd %d offset %lld buffer %lx size %d Opcode %d\n",
-				first_ce->myaiocb64.aio_fildes,
-				first_ce->myaiocb64.aio_offset,
-				(long)(first_ce->myaiocb64.aio_buf),
-				first_ce->myaiocb64.aio_nbytes,
-				first_ce->myaiocb64.aio_lio_opcode
-#endif
-#else
-			printf("aio_return error2: fd %d offset %d buffer %lx size %d Opcode %d\n",
+			printf("aio_return error2: ret %zd %d\n",retval,errno);
+			printf("aio_return error2: fd %d offset %lld buffer %p size %zd Opcode %d\n",
 				first_ce->myaiocb.aio_fildes,
-				first_ce->myaiocb.aio_offset,
-				(long)(first_ce->myaiocb.aio_buf),
+				(long long)first_ce->myaiocb.aio_offset,
+				first_ce->myaiocb.aio_buf,
 				first_ce->myaiocb.aio_nbytes,
 				first_ce->myaiocb.aio_lio_opcode
-#endif
 				);
 		}
 		if(retval > 0)
 		{
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 			mbcopy((char *)first_ce->myaiocb.aio_buf,(char *)ubuffer,(size_t)retval);
-#else
-			mbcopy((char *)first_ce->myaiocb64.aio_buf,(char *)ubuffer,(size_t)retval);
-#endif
-#else
-			mbcopy((char *)first_ce->myaiocb.aio_buf,(char *)ubuffer,(size_t)retval);
-#endif
 		}
 		first_ce->direct=0;
 		takeoff_cache(gc,first_ce);
@@ -601,7 +482,7 @@ long long fd,size,op;
 off64_t offset;
 {
 	struct cache_ent *ce;
-	long temp;
+	intptr_t temp;
 	ce=(struct cache_ent *)malloc((size_t)sizeof(struct cache_ent));
 	if(ce == (struct cache_ent *)0)
 	{
@@ -609,56 +490,22 @@ off64_t offset;
 		exit(175);
 	}
 	bzero(ce,sizeof(struct cache_ent));
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 	ce->myaiocb.aio_fildes=(int)fd;
 	ce->myaiocb.aio_offset=(off64_t)offset;
-	ce->real_address = (char *)malloc((size_t)(size+page_size));
-	temp=(long)ce->real_address;
-	temp = (temp+page_size) & ~(page_size-1);
-	ce->myaiocb.aio_buf=(volatile void *)temp;
-	if(ce->myaiocb.aio_buf == 0)
-#else
-	ce->myaiocb64.aio_fildes=(int)fd;
-	ce->myaiocb64.aio_offset=(off64_t)offset;
-	ce->real_address = (char *)malloc((size_t)(size+page_size));
-	temp=(long)ce->real_address;
-	temp = (temp+page_size) & ~(page_size-1);
-	ce->myaiocb64.aio_buf=(volatile void *)temp;
-	if(ce->myaiocb64.aio_buf == 0)
-#endif
-#else
-	ce->myaiocb.aio_fildes=(int)fd;
-	ce->myaiocb.aio_offset=(off_t)offset;
-	ce->real_address = (char *)malloc((size_t)(size+page_size));
-	temp=(long)ce->real_address;
+	ce->real_address = malloc((size_t)(size+page_size));
+	temp = (intptr_t)ce->real_address;
 	temp = (temp+page_size) & ~(page_size-1);
 	ce->myaiocb.aio_buf=(volatile void *)temp;
-	if(ce->myaiocb.aio_buf == 0)
-#endif
+	if(ce->myaiocb.aio_buf == NULL)
 	{
 		printf("Malloc failed\n");
 		exit(176);
 	}
 	/*bzero(ce->myaiocb.aio_buf,(size_t)size);*/
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 	ce->myaiocb.aio_reqprio=0;
 	ce->myaiocb.aio_nbytes=(size_t)size;
 	ce->myaiocb.aio_sigevent.sigev_notify=SIGEV_NONE;
 	ce->myaiocb.aio_lio_opcode=(int)op;
-#else
-	ce->myaiocb64.aio_reqprio=0;
-	ce->myaiocb64.aio_nbytes=(size_t)size;
-	ce->myaiocb64.aio_sigevent.sigev_notify=SIGEV_NONE;
-	ce->myaiocb64.aio_lio_opcode=(int)op;
-#endif
-#else
-	ce->myaiocb.aio_reqprio=0;
-	ce->myaiocb.aio_nbytes=(size_t)size;
-	ce->myaiocb.aio_sigevent.sigev_notify=SIGEV_NONE;
-	ce->myaiocb.aio_lio_opcode=(int)op;
-#endif
 	ce->fd=(int)fd;
 	ce->forward=0;
 	ce->back=gc->tail;
@@ -687,8 +534,6 @@ off64_t offset;
 		return(0);
 	}
 	move=gc->head;
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 	while(move)
 	{
 		if((move->fd == fd) && (move->myaiocb.aio_offset==(off64_t)offset) &&
@@ -698,28 +543,6 @@ off64_t offset;
 			}
 		move=move->forward;
 	}
-#else
-	while(move)
-	{
-		if((move->fd == fd) && (move->myaiocb64.aio_offset==(off64_t)offset) &&
-			((size_t)size==move->myaiocb64.aio_nbytes))
-			{
-				return(move);
-			}
-		move=move->forward;
-	}
-#endif
-#else
-	while(move)
-	{
-		if((move->fd == fd) && (move->myaiocb.aio_offset==(off_t)offset) &&
-			((size_t)size==move->myaiocb.aio_nbytes))
-			{
-				return(move);
-			}
-		move=move->forward;
-	}
-#endif
 	return(0);
 }
 
@@ -804,26 +627,10 @@ struct cache *gc;
 		ce=gc->head;
 		if(ce==0)
 			return;
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 		while((ret = aio_cancel(0,&ce->myaiocb))==AIO_NOTCANCELED)
-#else
-		while((ret = aio_cancel64(0,&ce->myaiocb64))==AIO_NOTCANCELED)
-#endif
-#else
-		while((ret = aio_cancel(0,&ce->myaiocb))==AIO_NOTCANCELED)
-#endif
 			; 
 
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 		ret = aio_return(&ce->myaiocb);
-#else
-		ret = aio_return64(&ce->myaiocb64);
-#endif
-#else
-		ret = aio_return(&ce->myaiocb);
-#endif
 		ce->direct=0;
 		takeoff_cache(gc,ce);	  /* remove from cache */
 	}
@@ -864,100 +671,29 @@ long long depth;
 	 */
 	if((ce=(struct cache_ent *)incache(gc,fd,offset,size)))
 	{
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		while((ret=aio_error(&ce->myaiocb))== EINPROGRESS)
-		{
-			async_suspend(ce);
-		}
-#else
-		while((ret=aio_error64(&ce->myaiocb64))== EINPROGRESS)
-		{
-			async_suspend(ce);
-		}
-#endif
-#else
 		while((ret=aio_error(&ce->myaiocb))== EINPROGRESS)
 		{
 			async_suspend(ce);
 		}
-#endif
 		if(ret)
-			printf("aio_error 3: ret %d %d\n",ret,errno);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		if(ce->oldbuf != ce->myaiocb.aio_buf ||
-			ce->oldfd != ce->myaiocb.aio_fildes ||
-			ce->oldsize != ce->myaiocb.aio_nbytes) 
-#else
-		if(ce->oldbuf != ce->myaiocb64.aio_buf ||
-			ce->oldfd != ce->myaiocb64.aio_fildes ||
-			ce->oldsize != ce->myaiocb64.aio_nbytes) 
-#endif
-#else
-		if(ce->oldbuf != ce->myaiocb.aio_buf ||
-			ce->oldfd != ce->myaiocb.aio_fildes ||
-			ce->oldsize != ce->myaiocb.aio_nbytes) 
-#endif
+			printf("aio_error 3: ret %zd %d\n",ret,errno);
 			printf("It changed in flight\n");
 			
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		retval=aio_return(&ce->myaiocb);
-#else
-		retval=aio_return64(&ce->myaiocb64);
-#endif
-#else
 		retval=aio_return(&ce->myaiocb);
-#endif
 		if(retval > 0)
 		{
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-			*ubuffer=(char *)ce->myaiocb.aio_buf;
-#else
-			*ubuffer=(char *)ce->myaiocb64.aio_buf;
-#endif
-#else
-			*ubuffer=(char *)ce->myaiocb.aio_buf;
-#endif
+			*ubuffer= (char *)ce->myaiocb.aio_buf;
 		}else
-			*ubuffer=0;
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		if(retval < ce->myaiocb.aio_nbytes)
-#else
-		if(retval < ce->myaiocb64.aio_nbytes)
-#endif
-#else
+			*ubuffer= NULL;
 		if(retval < ce->myaiocb.aio_nbytes)
-#endif
 		{
-			printf("aio_return error4: ret %d %d\n",retval,errno);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-			printf("aio_return error4: fd %d offset %lld buffer %lx size %d Opcode %d\n",
-				ce->myaiocb.aio_fildes,
-				ce->myaiocb.aio_offset,
-				(long)(ce->myaiocb.aio_buf),
-				ce->myaiocb.aio_nbytes,
-				ce->myaiocb.aio_lio_opcode
-#else
-			printf("aio_return error4: fd %d offset %lld buffer %lx size %d Opcode %d\n",
-				ce->myaiocb64.aio_fildes,
-				ce->myaiocb64.aio_offset,
-				(long)(ce->myaiocb64.aio_buf),
-				ce->myaiocb64.aio_nbytes,
-				ce->myaiocb64.aio_lio_opcode
-#endif
-#else
-			printf("aio_return error4: fd %d offset %d buffer %lx size %d Opcode %d\n",
+			printf("aio_return error4: ret %zd %d\n",retval,errno);
+			printf("aio_return error4: fd %d offset %lld buffer %p size %zd Opcode %d\n",
 				ce->myaiocb.aio_fildes,
-				ce->myaiocb.aio_offset,
-				(long)(ce->myaiocb.aio_buf),
+				(long long)ce->myaiocb.aio_offset,
+				ce->myaiocb.aio_buf,
 				ce->myaiocb.aio_nbytes,
 				ce->myaiocb.aio_lio_opcode
-#endif
 				);
 		}
 		ce->direct=1;
@@ -973,30 +709,16 @@ long long depth;
 		first_ce=alloc_cache(gc,fd,offset,size,(long long)LIO_READ); /* allocate buffer */
 		/*printf("allocated buffer/read %x offset %d\n",first_ce->myaiocb.aio_buf,offset);*/
 again:
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		first_ce->oldbuf=first_ce->myaiocb.aio_buf;
-		first_ce->oldfd=first_ce->myaiocb.aio_fildes;
-		first_ce->oldsize=first_ce->myaiocb.aio_nbytes;
-		ret=aio_read(&first_ce->myaiocb);
-#else
-		first_ce->oldbuf=first_ce->myaiocb64.aio_buf;
-		first_ce->oldfd=first_ce->myaiocb64.aio_fildes;
-		first_ce->oldsize=first_ce->myaiocb64.aio_nbytes;
-		ret=aio_read64(&first_ce->myaiocb64);
-#endif
-#else
 		first_ce->oldbuf=first_ce->myaiocb.aio_buf;
 		first_ce->oldfd=first_ce->myaiocb.aio_fildes;
 		first_ce->oldsize=first_ce->myaiocb.aio_nbytes;
 		ret=aio_read(&first_ce->myaiocb);
-#endif
 		if(ret!=0)
 		{
 			if(errno==EAGAIN)
 				goto again;
 			else
-				printf("error returned from aio_read(). Ret %d errno %d\n",ret,errno);
+				printf("error returned from aio_read(). Ret %zd errno %d\n",ret,errno);
 		}
 	}
 	if(stride==0)	 /* User does not want read-ahead */
@@ -1021,24 +743,10 @@ again:
 		if((ce=incache(gc,fd,r_offset,a_size)))
 			continue;
 		ce=alloc_cache(gc,fd,r_offset,a_size,(long long)LIO_READ);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 		ce->oldbuf=ce->myaiocb.aio_buf;
 		ce->oldfd=ce->myaiocb.aio_fildes;
 		ce->oldsize=ce->myaiocb.aio_nbytes;
 		ret=aio_read(&ce->myaiocb);
-#else
-		ce->oldbuf=ce->myaiocb64.aio_buf;
-		ce->oldfd=ce->myaiocb64.aio_fildes;
-		ce->oldsize=ce->myaiocb64.aio_nbytes;
-		ret=aio_read64(&ce->myaiocb64);
-#endif
-#else
-		ce->oldbuf=ce->myaiocb.aio_buf;
-		ce->oldfd=ce->myaiocb.aio_fildes;
-		ce->oldsize=ce->myaiocb.aio_nbytes;
-		ret=aio_read(&ce->myaiocb);
-#endif
 		if(ret!=0)
 		{
 			takeoff_cache(gc,ce);
@@ -1048,97 +756,33 @@ again:
 out:
 	if(del_read)	/* Wait for the first read to complete */
 	{
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 		while((ret=aio_error(&first_ce->myaiocb))== EINPROGRESS)
 		{
 			async_suspend(first_ce);
 		}
-#else
-		while((ret=aio_error64(&first_ce->myaiocb64))== EINPROGRESS)
-		{
-			async_suspend(first_ce);
-		}
-#endif
-#else
-		while((ret=aio_error(&first_ce->myaiocb))== EINPROGRESS)
-		{
-			async_suspend(first_ce);
-		}
-#endif
 		if(ret)
-			printf("aio_error 4: ret %d %d\n",ret,errno);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		if(first_ce->oldbuf != first_ce->myaiocb.aio_buf ||
-			first_ce->oldfd != first_ce->myaiocb.aio_fildes ||
-			first_ce->oldsize != first_ce->myaiocb.aio_nbytes) 
-			printf("It changed in flight2\n");
-		retval=aio_return(&first_ce->myaiocb);
-#else
-		if(first_ce->oldbuf != first_ce->myaiocb64.aio_buf ||
-			first_ce->oldfd != first_ce->myaiocb64.aio_fildes ||
-			first_ce->oldsize != first_ce->myaiocb64.aio_nbytes) 
-			printf("It changed in flight2\n");
-		retval=aio_return64(&first_ce->myaiocb64);
-#endif
-#else
+			printf("aio_error 4: ret %zd %d\n",ret,errno);
 		if(first_ce->oldbuf != first_ce->myaiocb.aio_buf ||
 			first_ce->oldfd != first_ce->myaiocb.aio_fildes ||
 			first_ce->oldsize != first_ce->myaiocb.aio_nbytes) 
 			printf("It changed in flight2\n");
 		retval=aio_return(&first_ce->myaiocb);
-#endif
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 		if(retval < first_ce->myaiocb.aio_nbytes)
-#else
-		if(retval < first_ce->myaiocb64.aio_nbytes)
-#endif
-#else
-		if(retval < first_ce->myaiocb.aio_nbytes)
-#endif
 		{
-			printf("aio_return error5: ret %d %d\n",retval,errno);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-			printf("aio_return error5: fd %d offset %lld buffer %lx size %d Opcode %d\n",
-				first_ce->myaiocb.aio_fildes,
-				first_ce->myaiocb.aio_offset,
-				(long)(first_ce->myaiocb.aio_buf),
-				first_ce->myaiocb.aio_nbytes,
-				first_ce->myaiocb.aio_lio_opcode
-#else
-			printf("aio_return error5: fd %d offset %lld buffer %lx size %d Opcode %d\n",
-				first_ce->myaiocb64.aio_fildes,
-				first_ce->myaiocb64.aio_offset,
-				(long)(first_ce->myaiocb64.aio_buf),
-				first_ce->myaiocb64.aio_nbytes,
-				first_ce->myaiocb64.aio_lio_opcode
-#endif
-#else
-			printf("aio_return error5: fd %d offset %ld buffer %lx size %d Opcode %d\n",
+			printf("aio_return error5: ret %zd %d\n",retval,errno);
+			printf("aio_return error5: fd %d offset %lld buffer %p size %zd Opcode %d\n",
 				first_ce->myaiocb.aio_fildes,
-				first_ce->myaiocb.aio_offset,
-				(long)(first_ce->myaiocb.aio_buf),
+				(long long)first_ce->myaiocb.aio_offset,
+				first_ce->myaiocb.aio_buf,
 				first_ce->myaiocb.aio_nbytes,
 				first_ce->myaiocb.aio_lio_opcode
-#endif
 				);
 		}
 		if(retval > 0)
 		{
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-			*ubuffer=(char *)first_ce->myaiocb.aio_buf;
-#else
-			*ubuffer=(char *)first_ce->myaiocb64.aio_buf;
-#endif
-#else
-			*ubuffer=(char *)first_ce->myaiocb.aio_buf;
-#endif
+			*ubuffer= (char *)first_ce->myaiocb.aio_buf;
 		}else
-			*ubuffer=(char *)0;
+			*ubuffer= NULL;
 		first_ce->direct=1;	 /* do not delete the buffer */
 		takeoff_cache(gc,first_ce);
 		putoninuse(gc,first_ce);
@@ -1217,32 +861,16 @@ long long depth;
 	size_t ret;
 	ce=allocate_write_buffer(gc,fd,offset,size,(long long)LIO_WRITE,depth,0LL,(char *)0,(char *)0);
 	ce->direct=0;	 /* not direct. Lib supplies buffer and must free it */
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-	mbcopy(buffer,(char *)(ce->myaiocb.aio_buf),(size_t)size);
-#else
-	mbcopy(buffer,(char *)(ce->myaiocb64.aio_buf),(size_t)size);
-#endif
-#else
 	mbcopy(buffer,(char *)(ce->myaiocb.aio_buf),(size_t)size);
-#endif
 	async_put_on_write_queue(gc,ce);
 	/*
-	printf("asw: fd %d offset %lld, size %d\n",ce->myaiocb64.aio_fildes,
-		ce->myaiocb64.aio_offset,
-		ce->myaiocb64.aio_nbytes);
+	printf("asw: fd %d offset %lld, size %zd\n",ce->myaiocb.aio_fildes,
+		ce->myaiocb.aio_offset,
+		ce->myaiocb.aio_nbytes);
 	*/	
 
 again:
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-	ret=aio_write(&ce->myaiocb);
-#else
-	ret=aio_write64(&ce->myaiocb64);
-#endif
-#else
 	ret=aio_write(&ce->myaiocb);
-#endif
 	if(ret==-1)
 	{
 		if(errno==EAGAIN)
@@ -1258,13 +886,13 @@ again:
 		}
 		else
 		{
-			printf("Error in aio_write: ret %d errno %d count %lld\n",ret,errno,gc->w_count);
+			printf("Error in aio_write: ret %zd errno %d count %lld\n",ret,errno,gc->w_count);
 			/*
-			printf("aio_write_no_copy: fd %d buffer %x offset %lld size %d\n",
-				ce->myaiocb64.aio_fildes,
-				ce->myaiocb64.aio_buf,
-				ce->myaiocb64.aio_offset,
-				ce->myaiocb64.aio_nbytes);
+			printf("aio_write_no_copy: fd %d buffer %x offset %lld size %zd\n",
+				ce->myaiocb.aio_fildes,
+				ce->myaiocb.aio_buf,
+				ce->myaiocb.aio_offset,
+				ce->myaiocb.aio_nbytes);
 			*/
 			exit(177);
 		}
@@ -1288,7 +916,7 @@ long long direct;
 char *buffer,*free_addr;
 {
 	struct cache_ent *ce;
-	long temp;
+	intptr_t temp;
 	if(fd==0LL)
 	{
 		printf("Setting up write buffer insane\n");
@@ -1303,46 +931,12 @@ char *buffer,*free_addr;
 		exit(179);
 	}
 	bzero(ce,sizeof(struct cache_ent));
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-	ce->myaiocb.aio_fildes=(int)fd;
-	ce->myaiocb.aio_offset=(off64_t)offset;
-	if(!direct)
-	{
-		ce->real_address = (char *)malloc((size_t)(size+page_size));
-		temp=(long)ce->real_address;
-		temp = (temp+page_size) & ~(page_size-1);
-		ce->myaiocb.aio_buf=(volatile void *)temp;
-	}else
-	{
-		ce->myaiocb.aio_buf=(volatile void *)buffer;
-		ce->real_address=(char *)free_addr;
-	}
-	if(ce->myaiocb.aio_buf == 0)
-#else
-	ce->myaiocb64.aio_fildes=(int)fd;
-	ce->myaiocb64.aio_offset=(off64_t)offset;
-	if(!direct)
-	{
-		ce->real_address = (char *)malloc((size_t)(size+page_size));
-		temp=(long)ce->real_address;
-		temp = (temp+page_size) & ~(page_size-1);
-		ce->myaiocb64.aio_buf=(volatile void *)temp;
-	}
-	else
-	{
-		ce->myaiocb64.aio_buf=(volatile void *)buffer;
-		ce->real_address=(char *)free_addr;
-	}
-	if(ce->myaiocb64.aio_buf == 0)
-#endif
-#else
 	ce->myaiocb.aio_fildes=(int)fd;
 	ce->myaiocb.aio_offset=(off_t)offset;
 	if(!direct)
 	{
-		ce->real_address = (char *)malloc((size_t)(size+page_size));
-		temp=(long)ce->real_address;
+		ce->real_address = malloc((size_t)(size+page_size));
+		temp = (intptr_t)ce->real_address;
 		temp = (temp+page_size) & ~(page_size-1);
 		ce->myaiocb.aio_buf=(volatile void *)temp;
 	}
@@ -1352,29 +946,14 @@ char *buffer,*free_addr;
 		ce->real_address=(char *)free_addr;
 	}
 	if(ce->myaiocb.aio_buf == 0)
-#endif
 	{
 		printf("Malloc failed 2\n");
 		exit(180);
 	}
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 	ce->myaiocb.aio_reqprio=0;
 	ce->myaiocb.aio_nbytes=(size_t)size;
 	ce->myaiocb.aio_sigevent.sigev_notify=SIGEV_NONE;
 	ce->myaiocb.aio_lio_opcode=(int)op;
-#else
-	ce->myaiocb64.aio_reqprio=0;
-	ce->myaiocb64.aio_nbytes=(size_t)size;
-	ce->myaiocb64.aio_sigevent.sigev_notify=SIGEV_NONE;
-	ce->myaiocb64.aio_lio_opcode=(int)op;
-#endif
-#else
-	ce->myaiocb.aio_reqprio=0;
-	ce->myaiocb.aio_nbytes=(size_t)size;
-	ce->myaiocb.aio_sigevent.sigev_notify=SIGEV_NONE;
-	ce->myaiocb.aio_lio_opcode=(int)op;
-#endif
 	ce->fd=(int)fd;
 	return(ce);
 }
@@ -1408,7 +987,7 @@ struct cache *gc;
 {
 	while(gc->w_head)
 	{
-		/*printf("async_write_finish: Waiting for buffer %x to finish\n",gc->w_head->myaiocb64.aio_buf);*/
+		/*printf("async_write_finish: Waiting for buffer %x to finish\n",gc->w_head->myaiocb.aio_buf);*/
 		async_wait_for_write(gc);
 	}
 }
@@ -1422,7 +1001,8 @@ async_wait_for_write(gc)
 struct cache *gc;
 {
 	struct cache_ent *ce;
-	size_t ret,retval;
+	size_t ret;
+	int retval;
 	if(gc->w_head==0)
 		return;
 	ce=gc->w_head;
@@ -1431,69 +1011,28 @@ struct cache *gc;
 	ce->forward=0;
 	if(ce==gc->w_tail)
 		gc->w_tail=0;
-	/*printf("Wait for buffer %x  offset %lld  size %d to finish\n",
-		ce->myaiocb64.aio_buf,
-		ce->myaiocb64.aio_offset,
-		ce->myaiocb64.aio_nbytes);
+	/*printf("Wait for buffer %x  offset %lld  size %zd to finish\n",
+		ce->myaiocb.aio_buf,
+		ce->myaiocb.aio_offset,
+		ce->myaiocb.aio_nbytes);
 	printf("write count %lld \n",gc->w_count);
 	*/
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
 	while((ret=aio_error(&ce->myaiocb))== EINPROGRESS)
 	{
 		async_suspend(ce);
 	}
-#else
-	while((ret=aio_error64(&ce->myaiocb64))== EINPROGRESS)
-	{
-		async_suspend(ce);
-	}
-#endif
-#else
-	while((ret=aio_error(&ce->myaiocb))== EINPROGRESS)
-	{
-		async_suspend(ce);
-	}
-#endif
 	if(ret)
 	{
-		printf("aio_error 5: ret %d %d\n",ret,errno);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-		printf("fd %d offset %lld size %d\n",
-			ce->myaiocb.aio_fildes,
-			ce->myaiocb.aio_offset,
-			ce->myaiocb.aio_nbytes);
-#else
-		printf("fd %d offset %lld size %d\n",
-			ce->myaiocb64.aio_fildes,
-			ce->myaiocb64.aio_offset,
-			ce->myaiocb64.aio_nbytes);
-#endif
-#else
-		printf("fd %d offset %lld size %d\n",
+		printf("aio_error 5: ret %zd %d\n",ret,errno);
+		printf("fd %d offset %lld size %zd\n",
 			ce->myaiocb.aio_fildes,
-			ce->myaiocb.aio_offset,
+			(long long)ce->myaiocb.aio_offset,
 			ce->myaiocb.aio_nbytes);
-#endif
 		exit(181);
 	}
 
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-	retval=aio_return(&ce->myaiocb);
-#else
-#if defined(__CrayX1__)
-	retval=aio_return64((aiocb64_t *)&ce->myaiocb64);
-#else
-	retval=aio_return64((struct aiocb64 *)&ce->myaiocb64);
-#endif
-
-#endif
-#else
 	retval=aio_return(&ce->myaiocb);
-#endif
-	if((int)retval < 0)
+	if(retval < 0)
 	{
 		printf("aio_return error: %d\n",errno);
 	}
@@ -1533,21 +1072,13 @@ char *free_addr;
 	ce->direct=0;	/* have library de-allocate the buffer */
 	async_put_on_write_queue(gc,ce);
 	/*
-	printf("awnc: fd %d offset %lld, size %d\n",ce->myaiocb64.aio_fildes,
-		ce->myaiocb64.aio_offset,
-		ce->myaiocb64.aio_nbytes);
+	printf("awnc: fd %d offset %lld, size %zd\n",ce->myaiocb.aio_fildes,
+		ce->myaiocb.aio_offset,
+		ce->myaiocb.aio_nbytes);
 	*/
 
 again:
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-	ret=aio_write(&ce->myaiocb);
-#else
-	ret=aio_write64(&ce->myaiocb64);
-#endif
-#else
 	ret=aio_write(&ce->myaiocb);
-#endif
 	if(ret==-1)
 	{
 		if(errno==EAGAIN)
@@ -1563,28 +1094,12 @@ again:
 		}
 		else
 		{
-			printf("Error in aio_write: ret %d errno %d\n",ret,errno);
-#ifdef _LARGEFILE64_SOURCE 
-#ifdef __LP64__
-			printf("aio_write_no_copy: fd %d buffer %lx offset %lld size %d\n",
-				ce->myaiocb.aio_fildes,
-				(long)(ce->myaiocb.aio_buf),
-				ce->myaiocb.aio_offset,
-				ce->myaiocb.aio_nbytes);
-#else
-			printf("aio_write_no_copy: fd %d buffer %lx offset %lld size %d\n",
-				ce->myaiocb64.aio_fildes,
-				(long)(ce->myaiocb64.aio_buf),
-				ce->myaiocb64.aio_offset,
-				ce->myaiocb64.aio_nbytes);
-#endif
-#else
-			printf("aio_write_no_copy: fd %d buffer %lx offset %ld size %d\n",
+			printf("Error in aio_write: ret %zd errno %d\n",ret,errno);
+			printf("aio_write_no_copy: fd %d buffer %p offset %lld size %zd\n",
 				ce->myaiocb.aio_fildes,
-				(long)(ce->myaiocb.aio_buf),
-				ce->myaiocb.aio_offset,
+				ce->myaiocb.aio_buf,
+				(long long)ce->myaiocb.aio_offset,
 				ce->myaiocb.aio_nbytes);
-#endif
 			exit(182);
 		}
 	} 
@@ -1595,7 +1110,8 @@ again:
 }
 
 void mbcopy(source, dest, len)
-char *source,*dest;
+const char *source;
+char *dest;
 size_t len;
 {
 	int i;
