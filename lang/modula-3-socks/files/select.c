#include "wrap.h"
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

int
m3_select(int nfds, fd_set *readfds, fd_set *writefds,
  fd_set *exceptfds, struct timeval *timeout)
{
  int result;

  ENTER_CRITICAL;
  MAKE_WRITABLE(readfds);
  MAKE_WRITABLE(writefds);
  MAKE_WRITABLE(exceptfds);
  MAKE_READABLE(timeout);
  result = select(nfds, readfds, writefds, exceptfds, timeout);
  EXIT_CRITICAL;
  return result;
}
