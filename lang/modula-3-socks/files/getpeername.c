#include "wrap.h"
#include <sys/types.h>
#include <sys/socket.h>

int
m3_getpeername(int s, struct sockaddr *name, int *namelen)
{
  int result;

  ENTER_CRITICAL;
  MAKE_WRITABLE(name);
  MAKE_WRITABLE(namelen);
  result = getpeername(s, name, namelen);
  EXIT_CRITICAL;
  return result;
}
