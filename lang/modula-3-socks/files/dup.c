#include "wrap.h"
#include <unistd.h>

int
m3_dup(int oldd)
{
  int result;

  ENTER_CRITICAL;
  result = dup(oldd);
  EXIT_CRITICAL;
  return result;
}
