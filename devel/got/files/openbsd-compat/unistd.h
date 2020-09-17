#ifndef _OPENBSD_COMPAT_UNISTD_H_
#define _OPENBSD_COMPAT_UNISTD_H_

#include_next <unistd.h>

int	getdtablecount(void);

/* void -> int */
#define closefrom(fd)			(closefrom(fd), 0)

#define pledge(promises, execpromises)	0
#define unveil(path, permissions)	0

#endif
