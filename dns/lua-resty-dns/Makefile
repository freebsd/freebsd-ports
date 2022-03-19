PORTNAME=	lua-resty-dns
DISTVERSIONPREFIX=v
DISTVERSION=	0.22
CATEGORIES=	dns www

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Lua DNS resolver for ngx_lua

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	luajit-openresty>=2.1:lang/luajit-openresty

USE_GITHUB=	yes
GH_ACCOUNT=	openresty

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=${LOCALBASE}/share/lua/5.1

PLIST_FILES=	${LUA_MODSHAREDIR}/resty/dns/resolver.lua

PORTDOCS=	README.markdown

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/resty/dns
	${INSTALL_DATA} ${WRKSRC}/lib/resty/dns/resolver.lua ${STAGEDIR}${LUA_MODSHAREDIR}/resty/dns

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
