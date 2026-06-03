PORTNAME=	qrencode
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	graphics
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	libqrencode wrapper for the Lua programming language
WWW=		https://github.com/vincascm/qrencode

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqrencode.so:graphics/libqrencode \
		libpng.so:graphics/png

USES=		lua:module localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	vincascm

do-build:
	(cd ${WRKSRC} && ${SETENVI} ${CC} ${PORTNAME}.c -o ${PORTNAME}.so \
	    ${CFLAGS} ${CPPFLAGS} -I${LUA_INCDIR} -std=gnu99 ${LDFLAGS} \
	    -pedantic -Wall -Wextra -shared -fPIC -lqrencode -lpng)

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/qrencode.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
