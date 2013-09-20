# Created by: vanilla@
# $FreeBSD$

PORTNAME=	iconv
PORTVERSION=	6
CATEGORIES=	converters
MASTER_SITES=	http://luaforge.net/frs/download.php/4181/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Iconv binding for Lua 5

WRKSRC=		${WRKDIR}/lua-${PORTNAME}-${PORTVERSION}
USE_LUA?=	5.1
USES=		pkgconfig iconv

PLIST_FILES=	%%LUA_MODLIBDIR%%/iconv.so

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%INCDIR%%|-I${PREFIX}/include| ; \
		s|%%LIBDIR%%|-L${PREFIX}/lib|; \
		s|%%ICONV_LIB%%|${ICONV_LIB}|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/iconv.so ${LUA_MODLIBDIR}

.include <bsd.port.mk>
