PORTNAME=	luaunbound
DISTVERSION=	1.0.0
PORTREVISION=	9
CATEGORIES=	dns
MASTER_SITES=	https://code.zash.se/dl/luaunbound/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	twm@pdp11.pw
COMMENT=	Lua binding to libunbound
WWW=		https://www.zash.se/luaunbound.html

LICENSE=	MIT

LIB_DEPENDS=	libunbound.so:dns/unbound

USES=		lua:module

CFLAGS+=	-fPIC -I${LUA_INCDIR} -I${LOCALBASE}/include
LDFLAGS+=	-shared -L${LUA_LIBDIR} -L${LOCALBASE}/lib -llua-${LUA_VER} -lunbound

do-build:
	cd ${WRKSRC} ;\
	${CC} ${CFLAGS} ${LDFLAGS} -o lunbound.so lunbound.c

do-install:
	${MKDIR} ${STAGEDIR}/${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/lunbound.so ${STAGEDIR}/${LUA_MODLIBDIR}

.include <bsd.port.mk>
