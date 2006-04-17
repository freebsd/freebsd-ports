# $FreeBSD$

SHLIB=		pty
SHLIB_NAME=	lpty.so

SRCS=		pty.c %%COMPATDIR%%/compat-5.1.c

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-lutil

.include <bsd.lib.mk>
