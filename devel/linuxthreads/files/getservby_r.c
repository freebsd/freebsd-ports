#include "pthread.h"
#include <netdb.h>
#include <string.h>

static pthread_mutex_t getservby_mutex = PTHREAD_MUTEX_INITIALIZER;

static int
convert (struct servent *ret, struct servent *result,
       char *buf, int buflen)
{
  int len, i;

  if (!buf) return -1;

  *result = *ret;
  /* This is the size. */
  len = strlen (ret->s_name) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  result->s_name = (char *) buf;
  buf += len;
  strcpy (result->s_name, ret->s_name);

  /* How many aliases and how big the buffer should be? There
     is always a NULL pointer. */
  for (len = sizeof (char *), i = 0; ret->s_aliases [i]; i++)
  {
    /* It should be size of (char *) and the length of string
       plus 1. */
    len += strlen (ret->s_aliases [i]) + 1 + sizeof (char *);
  }
  if (len > buflen) return -1;
  buflen -= len;

  /* This is an array of char * for s_aliases. */
  result->s_aliases = (char **) buf;
  buf += (i + 1) * sizeof (char *);

  /* We copy the aliases now. */
  for (i = 0; ret->s_aliases [i]; i++)
  {
    result->s_aliases [i] = (char *) buf;
    strcpy (result->s_aliases [i], ret->s_aliases [i]);
    buf += strlen (ret->s_aliases [i]) + 1;
  }
  /* This is the last one */
  result->s_aliases [i] = NULL;

  /* s_proto */
  len = strlen (ret->s_proto) + 1;
  if (len > buflen) return -1;
  buf += len;
  result->s_proto = (char *) buf;
  strcpy (result->s_proto, ret->s_proto);

  return 0;
}

struct servent *
getservbyport_r (int port, const char *proto,
       struct servent *result, char *buffer, int buflen)
{
  struct servent *ret;

  pthread_mutex_lock (&getservby_mutex);

  ret = getservbyport (port, proto);
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getservby_mutex);
  return result;
}

struct servent *
getservbyname_r (const char *name, const char *proto,
       struct servent *result, char *buffer, int buflen)
{
  struct servent *ret;

  pthread_mutex_lock (&getservby_mutex);

  ret = getservbyname (name, proto);
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getservby_mutex);
  return result;
}

struct servent *
getservent_r (struct servent *result, char *buffer, int buflen)
{
  struct servent *ret;

  pthread_mutex_lock (&getservby_mutex);

  ret = getservent ();
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getservby_mutex);
  return result;
}
