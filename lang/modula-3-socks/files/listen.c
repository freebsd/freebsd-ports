#include "wrap.h"
#include <sys/types.h>
#include <sys/socket.h>

int
m3_listen(int s, int backlog)
{
  int result;

  ENTER_CRITICAL;
  result = listen(s, backlog);
  EXIT_CRITICAL;
  return result;
}
