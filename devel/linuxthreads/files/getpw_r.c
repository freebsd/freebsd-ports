#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <pwd.h>
#include <osreldate.h>
#include "pthread.h"

#if __FreeBSD_version < 500112
static pthread_mutex_t getpw_mutex = PTHREAD_MUTEX_INITIALIZER;

static int
convert (struct passwd *ret, struct passwd *result,
       char *buf, int buflen)
{
  int len;

  if (!buf) return -1;

  *result = *ret;

  result->pw_name = (char *) buf;
  /* This is the size. */
  len = strlen (ret->pw_name) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_name, ret->pw_name);

  result->pw_passwd = (char *) buf;
  /* This is the size. */
  len = strlen (ret->pw_passwd) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_passwd, ret->pw_passwd);

  result->pw_gecos = (char *) buf;
  /* This is the size. */
  len = strlen (ret->pw_gecos) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_gecos, ret->pw_gecos);

  result->pw_dir = (char *) buf;
  /* This is the size. */
  len = strlen (ret->pw_dir) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_dir, ret->pw_dir);

  result->pw_shell = (char *) buf;
  /* This is the size. */
  len = strlen (ret->pw_shell) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_shell, ret->pw_shell);

  return 0;
}

int getpwnam_r (const char *name, struct passwd *result,
                char *buffer, size_t buflen,
                struct passwd ** resptr)
{
  struct passwd * p;
  int retval;

  pthread_mutex_lock (&getpw_mutex);
  p = getpwnam (name);
  if (p == NULL) {
    *resptr = NULL;
    retval = ESRCH;
  } else
  if (convert (p, result, buffer, buflen) != 0) {
    *resptr = NULL;
    retval = ERANGE;
  } else {
    *resptr = result;
    retval = 0;
  }
  pthread_mutex_unlock (&getpw_mutex);
  return retval;
}

int getpwuid_r (uid_t uid, struct passwd *result, 
                char *buffer, size_t buflen,
                struct passwd ** resptr)
{
  struct passwd * p;
  int retval;

  pthread_mutex_lock (&getpw_mutex);
  p = getpwuid (uid);
  if (p == NULL) {
    *resptr = NULL;
    retval = ESRCH;
  } else
  if (convert (p, result, buffer, buflen) != 0) {
    *resptr = NULL;
    retval = ERANGE;
  } else {
    *resptr = result;
    retval = 0;
  }
  pthread_mutex_unlock (&getpw_mutex);
  return retval;
}
#endif
