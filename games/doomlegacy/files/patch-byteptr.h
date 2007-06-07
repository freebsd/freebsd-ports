--- byteptr.h.orig	Sun Apr 18 18:02:24 2004
+++ byteptr.h	Wed Jun  6 20:09:36 2007
@@ -32,109 +32,123 @@
 //
 //-----------------------------------------------------------------------------
 
-#ifndef __BIG_ENDIAN__
-//
-// Little-endian machines
-//
-#define writeshort(p,b)     *(short*)  (p)   = b
-#define writelong(p,b)      *(long *)  (p)   = b
-#define WRITEBYTE(p,b)      *((byte   *)p)++ = b
-#define WRITECHAR(p,b)      *((char   *)p)++ = b
-#define WRITESHORT(p,b)     *((short  *)p)++ = b
-#define WRITEUSHORT(p,b)    *((USHORT *)p)++ = b
-#define WRITELONG(p,b)      *((long   *)p)++ = b
-#define WRITEULONG(p,b)     *((ULONG  *)p)++ = b
-#define WRITEFIXED(p,b)     *((fixed_t*)p)++ = b
-#define WRITEANGLE(p,b)     *((angle_t*)p)++ = b
-#define WRITESTRING(p,b)    { int tmp_i=0; do { WRITECHAR(p,b[tmp_i]); } while(b[tmp_i++]); }
-#define WRITESTRINGN(p,b,n) { int tmp_i=0; do { WRITECHAR(p,b[tmp_i]); if(!b[tmp_i]) break;tmp_i++; } while(tmp_i<n); }
-#define WRITEMEM(p,s,n)     memcpy(p, s, n);p+=n
+#include <assert.h>
+#include <stdint.h>
 
-#define readshort(p)	    *((short  *)p)
-#define readlong(p)	    *((long   *)p)
-#define READBYTE(p)         *((byte   *)p)++
-#define READCHAR(p)         *((char   *)p)++
-#define READSHORT(p)        *((short  *)p)++
-#define READUSHORT(p)       *((USHORT *)p)++
-#define READLONG(p)         *((long   *)p)++
-#define READULONG(p)        *((ULONG  *)p)++
-#define READFIXED(p)        *((fixed_t*)p)++
-#define READANGLE(p)        *((angle_t*)p)++
-#define READSTRING(p,s)     { int tmp_i=0; do { s[tmp_i]=READBYTE(p);  } while(s[tmp_i++]); }
-#define SKIPSTRING(p)       while(READBYTE(p))
-#define READMEM(p,s,n)      memcpy(s, p, n);p+=n
-#else 
-//
-// definitions for big-endian machines with alignment constraints.
-//
-// Write a value to a little-endian, unaligned destination.
-//
-static inline void writeshort(void * ptr, int val)
+#ifdef __BIG_ENDIAN__
+#define ptrtole(ptr, size)	endian_swap(ptr, size)
+#else
+#define ptrtole(ptr, size)	
+#endif
+
+static inline void *endian_swap(void *ptr, size_t size)
 {
-  char * cp = ptr;
-  cp[0] = val ;  val >>= 8;
-  cp[1] = val ;
+  unsigned char *myptr = ptr;
+  int i, x;
+
+  for (i = 1; i <= size / 2; i++) {
+    x = myptr[i-1];
+    myptr[i-1] = myptr[size-i];
+    myptr[size-i] = x;
+  }
+
+  return (ptr);
 }
 
-static inline void writelong(void * ptr, int val)
+static inline void *incptr(void **ptr, size_t size)
 {
-  char * cp = ptr;
-  cp[0] = val ;  val >>= 8;
-  cp[1] = val ;  val >>= 8;
-  cp[2] = val ;  val >>= 8;
-  cp[3] = val ;
+  unsigned char **myptr = ptr;
+  void *oldptr = *ptr;
+  int i;
+
+  for (i = 0; i < size; i++)
+    (*myptr)++;
+
+  return (oldptr);
 }
 
-#define WRITEBYTE(p,b)      *((byte   *)p)++ = (b)
-#define WRITECHAR(p,b)      *((char   *)p)++ = (b)
-#define WRITESHORT(p,b)     writeshort(((short *)p)++,  (b))
-#define WRITEUSHORT(p,b)    writeshort(((u_short*)p)++, (b))
-#define WRITELONG(p,b)      writelong (((long  *)p)++,  (b))
-#define WRITEULONG(p,b)     writelong (((u_long *)p)++, (b))
-#define WRITEFIXED(p,b)     writelong (((fixed_t*)p)++,  (b))
-#define WRITEANGLE(p,b)     writelong (((angle_t*)p)++, (long) (b))
-#define WRITESTRING(p,b)    { int tmp_i=0; do { WRITECHAR(p,b[tmp_i]); } while(b[tmp_i++]); }
-#define WRITESTRINGN(p,b,n) { int tmp_i=0; do { WRITECHAR(p,b[tmp_i]); if(!b[tmp_i]) break;tmp_i++; } while(tmp_i<n); }
-#define WRITEMEM(p,s,n)     memcpy(p, s, n);p+=n
+static inline intmax_t readptr(void **ptr, size_t size)
+{
+  intmax_t res = 0;
 
-// Read a signed quantity from little-endian, unaligned data.
-// 
-static inline short readshort(void * ptr)
+  // Check if it won't work
+  assert(size > 0 && size <= sizeof(intmax_t));
+
+  memcpy(&res, incptr(ptr, size), size);
+  ptrtole(&res, size);
+
+  return (res);
+}
+
+static inline intmax_t writeptr(void **dst, intmax_t src, size_t size)
 {
-  char   *cp  = ptr;
-  u_char *ucp = ptr;
-  return (cp[1] << 8)  |  ucp[0] ;
+  intmax_t res = 0;
+
+  // Check if it won't work
+  assert(size > 0 && size <= sizeof(intmax_t));
+
+  memcpy(*dst, &src, size);
+  ptrtole(*dst, size);
+  memcpy(&res, *dst, size);
+  incptr(dst, size);
+
+  return (res);
 }
 
-static inline u_short readushort(void * ptr)
+static inline short readshort(void *ptr)
 {
-  u_char *ucp = ptr;
-  return (ucp[1] << 8) |  ucp[0] ;
+  short res = *(short *)ptr;
+
+  ptrtole(&res, sizeof(short));
+
+  return (res);
 }
 
-static inline long readlong(void * ptr)
+static inline long readlong(void *ptr)
 {
-  char   *cp  = ptr;
-  u_char *ucp = ptr;
-  return (cp[3] << 24) | (ucp[2] << 16) | (ucp[1] << 8) | ucp[0] ;
+  long res = *(long *)ptr;
+
+  ptrtole(&res, sizeof(long));
+
+  return (res);
 }
 
-static inline u_long readulong(void * ptr)
+static inline void writeshort(void *ptr, int val)
 {
-  u_char *ucp = ptr;
-  return (ucp[3] << 24) | (ucp[2] << 16) | (ucp[1] << 8) | ucp[0] ;
+  short *myptr = ptr;
+
+  *myptr = val;
+  ptrtole(myptr, sizeof(*myptr));
 }
 
+static inline void writelong(void *ptr, int val)
+{
+  long *myptr = ptr;
 
-#define READBYTE(p)         *((byte   *)p)++
-#define READCHAR(p)         *((char   *)p)++
-#define READSHORT(p)        readshort ( ((short*) p)++)
-#define READUSHORT(p)       readushort(((USHORT*) p)++)
-#define READLONG(p)         readlong  (  ((long*) p)++)
-#define READULONG(p)        readulong ( ((ULONG*) p)++)
-#define READFIXED(p)        readlong  (  ((long*) p)++)
-#define READANGLE(p)        readulong ( ((ULONG*) p)++)
+  *myptr = val;
+  ptrtole(myptr, sizeof(*myptr));
+}
+
+#define WRITEBYTE(p,b)      writeptr(&p, b, sizeof(byte))
+#define WRITECHAR(p,b)      writeptr(&p, b, sizeof(char))
+#define WRITESHORT(p,b)     writeptr(&p, b, sizeof(short))
+#define WRITEUSHORT(p,b)    writeptr(&p, b, sizeof(USHORT))
+#define WRITELONG(p,b)      writeptr(&p, b, sizeof(long))
+#define WRITEULONG(p,b)     writeptr(&p, b, sizeof(ULONG))
+#define WRITEFIXED(p,b)     writeptr(&p, b, sizeof(fixed_t))
+#define WRITEANGLE(p,b)     writeptr(&p, b, sizeof(angle_t))
+#define WRITESTRING(p,b)    { int tmp_i=0; do { WRITECHAR(p,b[tmp_i]); } while(b[tmp_i++]); }
+#define WRITESTRINGN(p,b,n) { int tmp_i=0; do { WRITECHAR(p,b[tmp_i]); if(!b[tmp_i]) break;tmp_i++; } while(tmp_i<n); }
+#define WRITEMEM(p,s,n)     memcpy(p, s, n);p+=n
+
+#define READBYTE(p)         readptr(&p, sizeof(byte))
+#define READCHAR(p)         readptr(&p, sizeof(char))
+#define READSHORT(p)        readptr(&p, sizeof(short))
+#define READUSHORT(p)       readptr(&p, sizeof(USHORT))
+#define READLONG(p)         readptr(&p, sizeof(long))
+#define READULONG(p)        readptr(&p, sizeof(ULONG))
+#define READFIXED(p)        readptr(&p, sizeof(fixed_t))
+#define READANGLE(p)        readptr(&p, sizeof(angle_t))
 #define READSTRING(p,s)     { int tmp_i=0; do { s[tmp_i]=READBYTE(p);  } while(s[tmp_i++]); }
 #define SKIPSTRING(p)       while(READBYTE(p))
 #define READMEM(p,s,n)      memcpy(s, p, n);p+=n
-#endif //__BIG_ENDIAN__
