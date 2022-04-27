# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	rehex
DISTVERSION=	0.5.0
CATEGORIES=	editors

MAINTAINER=	fuz@fuz.su
COMMENT=	Hex editor for reverse engineering

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	p5-Template-Toolkit>0:www/p5-Template-Toolkit \
		zip:archivers/zip
LIB_DEPENDS=	libcapstone.so:devel/capstone4 \
		libharfbuzz.so:print/harfbuzz \
		libiconv.so:converters/libiconv \
		libjansson.so:devel/jansson \
		libunistring.so:devel/libunistring

USES=		compiler:c++11-lang gmake gnome lua:53 perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	solemnwarning
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
USE_PERL5=	build
USE_WX=		3.0+
MAKE_ENV=	LUA_PKG="lua-${LUA_VER}" LUA="${LUA_CMD}" STRIP="${STRIP}"
TEST_TARGET=	check

PORTDOCS=	CHANGES.txt

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
