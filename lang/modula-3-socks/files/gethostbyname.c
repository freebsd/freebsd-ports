#include "wrap.h"
#include <netdb.h>

struct hostent *
m3_gethostbyname(const char *name)
{
  struct hostent *result;

  ENTER_CRITICAL;
  MAKE_READABLE(name);
  result = gethostbyname(name);
  EXIT_CRITICAL;
  return result;
}
