#include <sys/param.h>
#include <sys/stat.h>
#include <runetype.h>
#include <stdlib.h>

long int
__strtol_internal(__const char *__restrict __nptr, char **__restrict __endptr,
	int __base, int __group)
{

	return (strtol(__nptr, __endptr, __base));
}

/*
 * This one is special.  We cannot simply call stat(2) and be done with it:
 * Linux' and FreeBSD's ``struct stat'' have different sizes (88 and 96,
 * respectively per my testing here, but YMMV), leading us to core dump
 * if we do so.  Instead, copy only mtime field from FreeBSD's ``struct
 * stat'' into proper place of provided Linux' ``struct stat'' buffer.
 */

struct __linux_stat {
	char pad0[0x40];
	struct timespec __st_mtim;
	char pad1[0x10];
};

int
__xstat(int __ver, __const char *__filename, struct __linux_stat *__stat_buf)
{
	struct stat sb;
	int err = stat(__filename, &sb);

	if (!err)
		__stat_buf->__st_mtim = sb.st_mtimespec;
	return (err);
}

const int *__ctype_tolower;
const int *__ctype_toupper;

static void __fbsd_prepare(void) __attribute__ ((constructor));

static void
__fbsd_prepare(void)
{
#if __FreeBSD_version > 502118
	__ctype_tolower = _CurrentRuneLocale->__maplower;
	__ctype_toupper = _CurrentRuneLocale->__mapupper;
#else
	__ctype_tolower = _CurrentRuneLocale->maplower;
	__ctype_toupper = _CurrentRuneLocale->mapupper;
#endif
}
