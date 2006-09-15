# $FreeBSD$

SHLIB=		gettext
SHLIB_NAME=	lgettext.so

SRCS=		lua_gettext.c

CFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

.include <bsd.lib.mk>
