#include "wrap.h"
#include <sys/types.h>
#include <sys/socket.h>

int
m3_accept(int s, struct sockaddr *addr, int *addrlen)
{
  int result;

  ENTER_CRITICAL;
  MAKE_WRITABLE(addr);
  MAKE_WRITABLE(addrlen);
  result = accept(s, addr, addrlen);
  EXIT_CRITICAL;
  return result;
}
