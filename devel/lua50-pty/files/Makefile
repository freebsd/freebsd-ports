# $FreeBSD$

SHLIB=		pty
SHLIB_NAME=	lpty.so

SRCS=		pty.c ${COMPATDIR}/compat-5.1.c

CFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L/usr/lib -lutil

.include <bsd.lib.mk>
