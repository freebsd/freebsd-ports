# $FreeBSD$

SHLIB=		gettext
SHLIB_NAME=	lgettext.so

SRCS=		lua_gettext.c

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib -lintl

.include <bsd.lib.mk>
