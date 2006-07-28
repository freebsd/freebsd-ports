# $FreeBSD$

SHLIB_NAME=	game.so

SRCS!=		ls *.c

CFLAGS+=	-Dstricmp=strcasecmp -ffast-math -funroll-loops \
		-fomit-frame-pointer -fexpensive-optimizations

LDFLAGS+=	-L/lib -L/usr/lib -lm

.include <bsd.lib.mk>
