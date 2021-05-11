#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <sys/types.h>

#define __bitwise
#define __le16 __u16
#define __le32 __u32
#define __le64 __u64

typedef pid_t __kernel_pid_t;
typedef off_t __kernel_off_t;
typedef long __kernel_long_t;

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;

typedef int8_t __s8;
typedef int16_t __s16;
typedef int32_t __s32;
typedef int64_t __s64;

#endif /* _LINUX_TYPES_H */
