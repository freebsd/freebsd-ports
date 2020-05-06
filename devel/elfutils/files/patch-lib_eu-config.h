--- lib/eu-config.h.orig	2020-03-30 12:17:45 UTC
+++ lib/eu-config.h
@@ -176,6 +176,182 @@ asm (".section predict_data, \"aw\"; .previous\n"
 #define ELFUTILS_HEADER(name) <lib##name.h>
 
 
+/* FreeBSD ports of glibcisms */
+#include <sys/cdefs.h>
+#include <libgen.h>
+#include <limits.h>
+#include <stdarg.h>
+#include <stdint.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <wchar.h>
+
+#define	_GL_ATTRIBUTE_PURE	__attribute__((__pure__))
+
+struct obstack;
+extern int obstack_printf(struct obstack *, const char *, ...);
+extern int obstack_vprintf(struct obstack *, const char *, va_list);
+
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wshadow"
+static inline void *
+mempcpy(void * restrict dst, const void * restrict src, size_t len)
+{
+
+	return (((char *)memcpy(dst, src, len)) + len);
+}
+
+static inline wchar_t *
+wmempcpy(wchar_t * restrict dst, const wchar_t * restrict src, size_t len)
+{
+
+	return (wmemcpy(dst, src, len) + len);
+}
+#pragma GCC diagnostic pop
+
+static inline void *
+rawmemchr(const void *s, int c)
+{
+
+	return (memchr(s, c, SSIZE_MAX));
+}
+
+static inline void
+tdestroy(void *vroot __unused, void (*freefct)(void *) __unused)
+{
+
+	/* XXX: Just leak the memory for now. */
+}
+
+static inline char *
+canonicalize_file_name(const char *path)
+{
+
+	return (realpath(path, NULL));
+}
+
+/*
+ * A GNU-like basename().
+ *
+ * Unlike POSIX basename(3), this version never modifies its argument.  If the
+ * argument ends in a slash, it returns the empty string.
+ */
+static inline char *
+eu_basename(const char *path)
+{
+	const char *slash;
+
+	slash = strrchr(path, '/');
+	if (slash != NULL)
+		slash++;
+	else
+		slash = path;
+	return (__DECONST(char *, slash));
+}
+#ifdef	basename
+#undef	basename
+#endif
+#define	basename	eu_basename
+
+#ifndef	TEMP_FAILURE_RETRY
+#define	TEMP_FAILURE_RETRY(expr)	({		\
+	long value;					\
+	do {						\
+		value = (long)(expr);			\
+	} while (value == -1 && errno == EINTR);	\
+	(value);					\
+})
+#endif
+
+#define	strndupa(s, n)	\
+({					\
+	size_t len = (n);		\
+	const char *end;		\
+	char *res;			\
+					\
+	end = memchr((s), 0, (n));	\
+	if (end != NULL)		\
+		len = end - (s);	\
+					\
+	res = alloca(len + 1);		\
+	memcpy(res, (s), len);		\
+	res[len] = '\0';		\
+	res;				\
+})
+
+
+#define	program_invocation_short_name	__DECONST(char *, getprogname())
+#ifndef	loff_t
+#define	loff_t	off_t
+#endif
+#ifndef	off64_t
+#define	off64_t	off_t
+#endif
+
+#define	ftruncate64	ftruncate
+#define	open64	open
+#define	fstat64	fstat
+#define	stat64	stat
+#define	pread64	pread
+#define	mmap64	mmap
+#define	lseek64	lseek
+
+#define	MAP_POPULATE	MAP_PREFAULT_READ
+
+#define	bswap_16	bswap16
+#define	bswap_32	bswap32
+#define	bswap_64	bswap64
+
+/*
+ * Future versions of FreeBSD will provide proper versions of these _unlocked
+ * variants.  These can and should be used instead, but won't be available
+ * until FreeBSD 11.4 and 12.2, at which point we should limit the scope of
+ * these to DragonFlyBSD.
+ */
+#ifndef fputc_unlocked
+#define	fputc_unlocked	putc_unlocked
+#endif
+#define	fputs_unlocked	fputs
+#define	fwrite_unlocked	fwrite
+#define	fread_unlocked	fread
+
+#ifndef	__BYTE_ORDER
+#define	__BYTE_ORDER	_BYTE_ORDER
+#endif
+#ifndef	__LITTLE_ENDIAN
+#define	__LITTLE_ENDIAN	_LITTLE_ENDIAN
+#endif
+#ifndef	__BIG_ENDIAN
+#define	__BIG_ENDIAN	_BIG_ENDIAN
+#endif
+
+#define	DL_CALL_FCT(fn, args)	((fn) args)
+
+/* This package doesn't really respect --disable-nls.  Hack it. */
+#if	!ENABLE_NLS
+/* Skip loading libintl.h, which is hardcoded in most source files: */
+#define	_LIBINTL_H	1
+#define	dgettext(module, str)	(str)
+#define	gettext(str)	(str)
+
+static inline char *
+bindtextdomain(const char *d __unused, const char *dr __unused)
+{
+
+	return ("/");
+}
+
+static inline char *
+textdomain(const char *dom)
+{
+
+	return (__DECONST(char *, dom));
+}
+
+#define	ngettext(s, p, n)	(((n) == 1) ? (s) : (p))
+#endif
+
 #ifdef SYMBOL_VERSIONING
 # define OLD_VERSION(name, version) \
   asm (".globl _compat." #version "." #name "\n" \
