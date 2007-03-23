Index: atc/include.h
@@ -63,6 +63,14 @@
 #include <sys/utsname.h>
 #endif
 
+#ifdef POSIX
+#include <termios.h>
+#include <fcntl.h>
+#include <unistd.h>
+#include <string.h>
+#include <sys/utsname.h>
+#endif
+
 #include <signal.h>
 #include <math.h>
 
@@ -76,6 +84,18 @@
 #define	srandom	srand
 #define	random	rand
 #define	sgttyb	termio
+#define	sg_erase c_cc[VERASE]
+#define	sg_kill c_cc[VKILL]
+#endif
+
+#ifdef POSIX
+#define	index	strchr
+#define	rindex	strrchr
+#define bcopy(a,b,c)	memcpy((b), (a), (c))
+#define	bzero(a,b)	memset((a), '\0', (b))
+#define	srandom	srand
+#define	random	rand
+#define	sgttyb	termios
 #define	sg_erase c_cc[2]
 #define	sg_kill c_cc[3]
 #endif
