#include "wrap.h"
#include <sys/types.h>
#include <sys/socket.h>

ssize_t
m3_send(int s, const void *msg, size_t len, int flags)
{
  int result;

  ENTER_CRITICAL;
  MAKE_READABLE(msg);
  result = send(s, msg, len, flags);
  EXIT_CRITICAL;
  return result;
}
