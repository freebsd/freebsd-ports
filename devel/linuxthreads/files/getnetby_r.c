#include "pthread.h"
#include <netdb.h>
#include <string.h>

static pthread_mutex_t getnetby_mutex = PTHREAD_MUTEX_INITIALIZER;

static int
convert (struct netent *ret, struct netent *result,
       char *buf, int buflen)
{
  int len, i;

  if (!buf) return -1;

  *result = *ret;
  result->n_name = (char *) buf;
  /* This is the size. */
  len = strlen (ret->n_name) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->n_name, ret->n_name);

  /* How many aliases and how big the buffer should be? There
     is always a NULL pointer. */
  for (len = sizeof (char *), i = 0; ret->n_aliases [i]; i++)
  {
    /* It should be size of (char *) and the length of string
       plus 1. */
    len += strlen (ret->n_aliases [i]) + 1 + sizeof (char *);
  }
  if (len > buflen) return -1;

  /* This is an array of char * for n_aliases. */
  result->n_aliases = (char **) buf;
  buf += (i + 1) * sizeof (char *);

  /* We copy the aliases now. */
  for (i = 0; ret->n_aliases [i]; i++)
  {
    result->n_aliases [i] = (char *) buf;
    strcpy (result->n_aliases [i], ret->n_aliases [i]);
    buf += strlen (ret->n_aliases [i]) + 1;
  }
  /* This is the last one */
  result->n_aliases [i] = NULL;

  return 0;
}

struct netent *
getnetbyaddr_r (long net, int type,
       struct netent *result, char *buffer, int buflen)
{
  struct netent *ret;

  pthread_mutex_lock (&getnetby_mutex);

  ret = getnetbyaddr (net, type);
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getnetby_mutex);
  return result;
}

struct netent *
getnetbyname_r (const char *name,
       struct netent *result, char *buffer, int buflen)
{
  struct netent *ret;

  pthread_mutex_lock (&getnetby_mutex);

  ret = getnetbyname (name);
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getnetby_mutex);
  return result;
}

struct netent *
getnetent_r (struct netent *result, char *buffer, int buflen)
{
  struct netent *ret;

  pthread_mutex_lock (&getnetby_mutex);

  ret = getnetent ();
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getnetby_mutex);
  return result;
}
