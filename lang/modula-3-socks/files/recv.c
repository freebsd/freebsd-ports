#include "wrap.h"
#include <sys/types.h>
#include <sys/socket.h>

ssize_t
m3_recv(int s, void *buf, size_t len, int flags)
{
  int result;

  ENTER_CRITICAL;
  MAKE_WRITABLE(buf);
  result = recv(s, buf, len, flags);
  EXIT_CRITICAL;
  return result;
}
