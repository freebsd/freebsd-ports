/*
 * Compatibility mappings for system headers and
 * prototypes for functions in libopenbsd-compat.
 */

#ifndef _OPENBSD_COMPAT_H_
#define _OPENBSD_COMPAT_H_

/*
 * <sys/cdefs.h>
 */
#define __dead __dead2

/*
 * <fcntl.h>
 */
#define open(...)	open_posix(__VA_ARGS__)
#define openat(...)	openat_posix(__VA_ARGS__)

int	open_posix(const char *path, int flags, ...);
int	openat_posix(int fd, const char *path, int flags, ...);

/*
 * <stdlib.h>
 */
void	freezero(void *, size_t);
void	*recallocarray(void *, size_t, size_t, size_t);

/*
 * <unistd.h>
 */
int	getdtablecount(void);

/* void -> int */
#define closefrom(fd)			(closefrom(fd), 0)

#define pledge(promises, execpromises)	0
#define unveil(path, permissions)	0

#endif	/* _OPENBSD_COMPAT_H_ */
