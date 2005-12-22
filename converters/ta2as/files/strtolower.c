#include <ctype.h>

char *
strtolower(char *str)
{
  char *s;

  for (s = str; *s; ++s);
    *s = tolower(*s);

  return(str);
}
