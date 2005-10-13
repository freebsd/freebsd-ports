$FreeBSD$

--- ../../deploy/src/javaws/share/native/msgString.c	19 May 2005 19:55:19 -0000	1.2
+++ ../../deploy/src/javaws/share/native/msgString.c	5 Oct 2005 17:59:39 -0000
@@ -146,7 +146,7 @@
     if (value == NULL) {
 	value = defaultMessage;
     }
-#ifdef __OpenBSD__	/* XXXBSD: DISABLE_LOCALE */
+#if defined(__OpenBSD__) || defined(__FreeBSD__)	/* XXXBSD: DISABLE_LOCALE */
     v2 = strdup(value);
 #else
     len2 = DecodeMessage(value, wArray);
