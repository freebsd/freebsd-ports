#ifndef _OPENBSD_COMPAT_STDLIB_H_
#define _OPENBSD_COMPAT_STDLIB_H_

#include_next <stdlib.h>

void	freezero(void *, size_t);
void	*recallocarray(void *, size_t, size_t, size_t);

#endif
