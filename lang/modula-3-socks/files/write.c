#include "wrap.h"
#include <sys/types.h>
#include <unistd.h>

size_t
m3_write(int fd, const void *buf, int nbytes)
{
  int result;

  ENTER_CRITICAL;
  MAKE_READABLE(buf);
  result = write(fd, buf, nbytes);
  EXIT_CRITICAL;
  return result;
}
