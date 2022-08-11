PORTNAME=	libac
PORTVERSION=	g20190308
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ implementation of the Aho-Corasick (AC) string matching algorithm

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

PLIST_FILES=	lib/libac.a \
		lib/libac.so

USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_PROJECT=	lua-aho-corasick
GH_TAGNAME=	ca6043c

do-install:
	${INSTALL_DATA} ${WRKSRC}/libac.a ${STAGEDIR}${PREFIX}/lib/libac.a
	${INSTALL_LIB} ${WRKSRC}/libac.so ${STAGEDIR}${PREFIX}/lib/libac.so

.include <bsd.port.mk>
