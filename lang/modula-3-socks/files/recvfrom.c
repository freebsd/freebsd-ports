#include "wrap.h"
#include <sys/types.h>
#include <sys/socket.h>

ssize_t
m3_recvfrom(int s, void *buf, size_t len, int flags,
  struct sockaddr *from, int *fromlen)
{
  int result;

  ENTER_CRITICAL;
  MAKE_WRITABLE(buf);
  MAKE_WRITABLE(from);
  MAKE_WRITABLE(fromlen);
  result = recvfrom(s, buf, len, flags, from, fromlen);
  EXIT_CRITICAL;
  return result;
}
