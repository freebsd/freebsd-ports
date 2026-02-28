PORTNAME=	cjson
PORTVERSION=	2.1.0.16
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-openresty
DISTNAME=	lua-cjson-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Fast JSON encoding/parsing for Lua with OpenResty enhancements
WWW=		https://github.com/openresty/lua-cjson

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		lua:module

CONFLICTS_INSTALL=	lua[0-9][0-9]-cjson

MAKE_ARGS=	LUA_VERSION=${LUA_VER}

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	lua-cjson

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

DOCSDIR=	${PREFIX}/share/doc/${LUA_PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

PLIST_FILES=	${LUA_MODLIBDIR}/cjson.so
DOC_FILES=      README.md
DOCS_PLIST_FILES=       ${DOC_FILES:S|^|${DOCSDIR_REL}/|}

post-patch:
	@${REINPLACE_CMD} '16,18d; \
		21s|^\(LUA_INCLUDE.*\)\(PREFIX\)\(.*\)|\1LOCALBASE\3/lua${LUA_VER_STR}|' \
		${WRKSRC}/Makefile

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
