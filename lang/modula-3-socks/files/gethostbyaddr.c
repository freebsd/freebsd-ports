#include "wrap.h"
#include <netdb.h>

struct hostent *
m3_gethostbyaddr(const char *addr, int len, int type)
{
  struct hostent *result;

  ENTER_CRITICAL;
  MAKE_READABLE(addr);
  result = gethostbyaddr(addr, len, type);
  EXIT_CRITICAL;
  return result;
}
