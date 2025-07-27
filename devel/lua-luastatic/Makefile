PORTNAME=	luastatic
PORTVERSION=	0.0.12
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Build a standalone executable from a Lua program
WWW=		https://github.com/ers35/luastatic

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		gmake lua

USE_GITHUB=	yes
GH_ACCOUNT=	ers35

MAKE_ENV+=	LUA=${LUA_CMD}
MAKE_ENV+=	LIBLUA_A=${LOCALBASE}/lib/liblua-${LUA_VER}.a
MAKE_ENV+=	LUA_INCLUDE=${LUA_INCDIR}

PLIST_FILES=	bin/luastatic
ALL_TARGET=	luastatic
TEST_TARGET=	run_test

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/luastatic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
