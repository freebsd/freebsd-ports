#include "wrap.h"
#include <sys/types.h>
#include <sys/socket.h>

int
m3_shutdown(int s, int how)
{
  int result;

  ENTER_CRITICAL;
  result = shutdown(s, how);
  EXIT_CRITICAL;
  return result;
}
