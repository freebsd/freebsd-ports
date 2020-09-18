#ifndef _OPENBSD_COMPAT_LIBGEN_H_
#define _OPENBSD_COMPAT_LIBGEN_H_

#define basename(path)	basename_const(path)
#define dirname(path)	dirname_const(path)

char	*basename(const char *);
char	*dirname(const char *);

#endif
