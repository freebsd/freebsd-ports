PORTNAME=	optparse
PORTVERSION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse and process command-line options
WWW=		https://luarocks.org/modules/gvvaughan/optparse \
		https://gvvaughan.github.io/optparse/ \
		https://github.com/gvvaughan/optparse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		lua:module

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gvvaughan

do-patch:
	@${REINPLACE_CMD} -e 's|@version@|${PORTVERSION}|' ${WRKSRC}/lib/optparse/version.lua.in > ${WRKSRC}/lib/optparse/version.lua

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/optparse
	${INSTALL_DATA} ${WRKSRC}/lib/optparse/*.lua ${STAGEDIR}${LUA_MODSHAREDIR}/optparse

.include <bsd.port.mk>
