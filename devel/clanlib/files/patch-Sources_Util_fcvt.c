
$FreeBSD$

--- /dev/null	Wed Jan 10 00:32:20 2001
+++ Sources/Util/fcvt.c	Wed Jan 10 00:31:59 2001
@@ -0,0 +1,139 @@
+/* Compatibility functions for floating point formatting, reentrant versions.
+   Copyright (C) 1995, 1996, 1997, 1998, 1999 Free Software Foundation, Inc.
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
+#include <ctype.h>
+#include <errno.h>
+#include <float.h>
+#include <math.h>
+#include <stdio.h>
+#include <string.h>
+#include <sys/param.h>
+
+extern int errno;
+
+#if DBL_MANT_DIG == 53
+#  define NDIGIT_MAX 17
+#else
+/* 
+ * See IEEE 854 5.6, table 2 for this formula.  Unfortunately we need a
+ * compile time constant here, so we cannot use it.
+ */
+#  error "NDIGIT_MAX must be precomputed"
+#  define NDIGIT_MAX (lrint (ceil (M_LN2 / M_LN10 * DBL_MANT_DIG + 1.0)))
+#endif
+#define MAXDIG (NDIGIT_MAX + 3)
+#define signbit(x) (((x)<(0))?(1):(0))
+
+static char *FCVT_BUFFER[MAXDIG];
+
+static int fcvt_r(double value, int ndigit, int *decpt, int *sign, char *buf, \
+                  size_t len)
+{
+  int n, i;
+  int left;
+
+  if (buf == NULL)
+  {
+    errno = EINVAL;
+    return -1;
+  }
+
+  left = 0;
+  if (finite(value))
+  {
+    *sign = signbit(value) != 0;
+    if (*sign)
+      value = -value;
+
+    if (ndigit < 0)
+    {
+
+      while (ndigit < 0)
+      {
+	double  new_value = value * 0.1;
+
+	if (new_value < 1.0)
+	{
+	  ndigit = 0;
+	  break;
+	}
+
+	value = new_value;
+	++left;
+	++ndigit;
+      }
+    }
+  }
+  else
+    *sign = 0;
+
+  n = snprintf(buf, len, "%.*f", MIN(ndigit, NDIGIT_MAX), value);
+   
+  if (n >= len)
+    return -1;
+
+  i = 0;
+  while (i < n && isdigit(buf[i]))
+    ++i;
+  *decpt = i;
+
+  if (i == 0)
+    return 0;
+
+  if (i < n)
+  {
+    do
+      ++i;
+    while (i < n && !isdigit(buf[i]));
+
+    if (*decpt == 1 && buf[0] == '0' && value != 0.0)
+    {
+      --*decpt;
+
+      while (i < n && buf[i] == '0')
+      {
+	--*decpt;
+	++i;
+      }
+    }
+
+    memmove(&buf[MAX(*decpt, 0)], &buf[i], n - i);
+    buf[n - (i - MAX(*decpt, 0))] = '\0';
+  }
+
+  if (left)
+  {
+    *decpt += left;
+    if (--len > n)
+    {
+      while (left-- > 0 && n < len)
+        buf[n++] = '0';
+      buf[n] = '\0';
+    }
+  }
+
+  return 0;
+}
+
+char *fcvt(double value, int ndigit, int *decpt, int *sign)
+{
+  fcvt_r(value, ndigit, decpt, sign, (char *)FCVT_BUFFER, MAXDIG);
+  return (char *)FCVT_BUFFER;
+}
+
