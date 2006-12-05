# $FreeBSD$

SHLIB=		pty
SHLIB_NAME=	lpty.so

SRCS=		pty.c
.if defined(COMPATDIR)
SRCS+=		${COMPATDIR}/compat-5.1.c
.endif

CFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L/usr/lib -lutil

.include <bsd.lib.mk>
