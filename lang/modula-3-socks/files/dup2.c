#include "wrap.h"
#include <unistd.h>

int
m3_dup2(int oldd, int newd)
{
  int result;

  ENTER_CRITICAL;
  result = dup2(oldd, newd);
  EXIT_CRITICAL;
  return result;
}
