#include "pthread.h"
#include <netdb.h>
#include <string.h>

static pthread_mutex_t getprotoby_mutex = PTHREAD_MUTEX_INITIALIZER;

static int
convert (struct protoent *ret, struct protoent *result,
       char *buf, int buflen)
{
  int len, i;

  if (!buf) return -1;

  *result = *ret;
  result->p_name = (char *) buf;
  /* This is the size. */
  len = strlen (ret->p_name) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->p_name, ret->p_name);

  /* How many aliases and how big the buffer should be? There
     is always a NULL pointer. */
  for (len = sizeof (char *), i = 0; ret->p_aliases [i]; i++)
  {
    /* It should be size of (char *) and the length of string
       plus 1. */
    len += strlen (ret->p_aliases [i]) + 1 + sizeof (char *);
  }
  if (len > buflen) return -1;

  /* This is an array of char * for p_aliases. */
  result->p_aliases = (char **) buf;
  buf += (i + 1) * sizeof (char *);

  /* We copy the aliases now. */
  for (i = 0; ret->p_aliases [i]; i++)
  {
    result->p_aliases [i] = (char *) buf;
    strcpy (result->p_aliases [i], ret->p_aliases [i]);
    buf += strlen (ret->p_aliases [i]) + 1;
  }
  /* This is the last one */
  result->p_aliases [i] = NULL;

  return 0;
}

struct protoent *
getprotobynumber_r (int proto,
       struct protoent *result, char *buffer, int buflen)
{
  struct protoent *ret;

  pthread_mutex_lock (&getprotoby_mutex);

  ret = getprotobynumber (proto);
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getprotoby_mutex);
  return result;
}

struct protoent *
getprotobyname_r (const char *name,
       struct protoent *result, char *buffer, int buflen)
{
  struct protoent *ret;

  pthread_mutex_lock (&getprotoby_mutex);

  ret = getprotobyname (name);
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getprotoby_mutex);
  return result;
}

struct protoent *
getprotoent_r (struct protoent *result, char *buffer, int buflen)
{
  struct protoent *ret;

  pthread_mutex_lock (&getprotoby_mutex);

  ret = getprotoent ();
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getprotoby_mutex);
  return result;
}
