#include "wrap.h"
#include <sys/types.h>
#include <sys/socket.h>

int
m3_socket(int domain, int type, int protocol)
{
  int result;

  ENTER_CRITICAL;
  result = socket(domain, type, protocol);
  EXIT_CRITICAL;
  return result;
}
