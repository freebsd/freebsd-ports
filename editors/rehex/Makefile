# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	rehex
PORTVERSION=	0.4.1
CATEGORIES=	editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hex editor for reverse engineering

LICENSE=	GPLv2

LIB_DEPENDS=	libcapstone.so:devel/capstone4 \
		libjansson.so:devel/jansson \
		libunistring.so:devel/libunistring

USES=		compiler:c++11-lang gmake gnome lua:53 pkgconfig
USE_WX=		3.0+
MAKE_ENV=	LUA_PKG="lua-${LUA_VER}" LUA="${LUA_CMD}"
USE_GITHUB=	yes
GH_ACCOUNT=	solemnwarning

PORTDOCS=	CHANGES.txt

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
