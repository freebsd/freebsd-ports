#ifndef _LIBUNWIND_UNWIND_H
#define _LIBUNWIND_UNWIND_H

#if __has_include("/usr/include/unwind.h")
#include "/usr/include/unwind.h"
#elif __has_include("/usr/include/c++/v1/unwind.h")

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__arm__) && !defined(__ARM_DWARF_EH__)
#include "/usr/include/c++/v1/unwind-arm.h"
#else
#include "/usr/include/c++/v1/unwind-itanium.h"
#endif

#ifdef __cplusplus
}
#endif

#else
#include_next <unwind.h>
#endif

#endif
