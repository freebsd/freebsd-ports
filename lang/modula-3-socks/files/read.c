#include "wrap.h"
#include <sys/types.h>
#include <unistd.h>

ssize_t
m3_read(int d, void *buf, size_t nbytes)
{
  int result;

  ENTER_CRITICAL;
  MAKE_WRITABLE(buf);
  result = read(d, buf, nbytes);
  EXIT_CRITICAL;
  return result;
}
