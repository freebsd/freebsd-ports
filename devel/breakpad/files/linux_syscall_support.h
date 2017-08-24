#include <unistd.h>
#include <sys/stat.h>

#define sys_readlink readlink

#define sys_open open
#define sys_close close
#define sys_fstat fstat
#define sys_mmap mmap
#define sys_munmap munmap
