#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <sys/types.h>

#define __bitwise
#define __le16 __u16
#define __le32 __u32
#define __le64 __u64

typedef pid_t __kernel_pid_t;
typedef off_t __kernel_off_t;

typedef uint64_t __u64;
#endif /* _LINUX_TYPES_H */
