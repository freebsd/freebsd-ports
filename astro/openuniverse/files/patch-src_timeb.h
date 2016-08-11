--- src/timeb.h.orig	2016-07-26 13:11:57 UTC
+++ src/timeb.h
@@ -0,0 +1,46 @@
+/* Copyright (C) 1994, 1995, 1996 Free Software Foundation, Inc.
+   This file is part of the GNU C Library.
+
+   The GNU C Library is free software; you can redistribute it and/or
+   modify it under the terms of the GNU Library General Public License as
+   published by the Free Software Foundation; either version 2 of the
+   License, or (at your option) any later version.
+
+   The GNU C Library is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   Library General Public License for more details.
+
+   You should have received a copy of the GNU Library General Public
+   License along with the GNU C Library; see the file COPYING.LIB.  If not,
+   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.  */
+
+#ifndef _SYS_TIMEB_H
+#define _SYS_TIMEB_H	1
+
+//#include <features.h>
+
+#define __need_time_t
+#include <time.h>
+
+
+__BEGIN_DECLS
+
+/* Structure returned by the `ftime' function.  */
+
+struct timeb
+  {
+    time_t time;		/* Seconds since epoch, as from `time'.  */
+    unsigned short int millitm;	/* Additional milliseconds.  */
+    short int timezone;		/* Minutes west of GMT.  */
+    short int dstflag;		/* Nonzero if Daylight Savings Time used.  */
+  };
+
+/* Fill in TIMEBUF with information about the current time.  */
+
+extern int ftime __P ((struct timeb *__timebuf));
+
+__END_DECLS
+
+#endif	/* sys/timeb.h */
