#include "wrap.h"
#include <unistd.h>

int
m3_close(int d)
{
  int result;

  ENTER_CRITICAL;
  result = close(d);
  EXIT_CRITICAL;
  return result;
}
