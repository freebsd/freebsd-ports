/*
 * Path sanitation code by Ludwig Nussel <ludwig.nussel@suse.de>. Public Domain.
 */

#include "unarj.h"

#include <string.h>
#include <limits.h>
#include <stdio.h>

#ifndef PATH_CHAR
#define PATH_CHAR '/'
#endif
#ifndef MIN
#define MIN(x,y) ((x)<(y)?(x):(y))
#endif

/* copy src into dest converting the path to a relative one inside the current
 * directory. dest must hold at least len bytes */
void copy_path_relative(char *dest, char *src, size_t len)
{
    char* o = dest;
    char* p = src;

    *o = '\0';

    while(*p && *p == PATH_CHAR) ++p;
    for(; len && *p;)
    {
	src = p;
	p = strchr(src, PATH_CHAR);
	if(!p) p = src+strlen(src);

	/* . => skip */
	if(p-src == 1 && *src == '.' )
	{
	    if(*p) src = ++p;
	}
	/* .. => pop one */
	else if(p-src == 2 && *src == '.' && src[1] == '.')
	{
	    if(o != dest)
	    {
		char* tmp;
		*o = '\0';
		tmp = strrchr(dest, PATH_CHAR);
		if(!tmp)
		{
		    len += o-dest;
		    o = dest;
		    if(*p) ++p;
		}
		else
		{
		    len += o-tmp;
		    o = tmp;
		    if(*p) ++p;
		}
	    }
	    else /* nothing to pop */
		if(*p) ++p;
	}
	else
	{
	    size_t copy;
	    if(o != dest)
	    {
		--len;
		*o++ = PATH_CHAR;
	    }
	    copy = MIN(p-src,len);
	    memcpy(o, src, copy);
	    len -= copy;
	    src += copy;
	    o += copy;
	    if(*p) ++p;
	}
	while(*p && *p == PATH_CHAR) ++p;
    }
    o[len?0:-1] = '\0';
}
