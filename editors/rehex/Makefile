PORTNAME=	rehex
DISTVERSION=	0.63.3
CATEGORIES=	editors

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Hex editor for reverse engineering
WWW=		https://github.com/solemnwarning/rehex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbotan-3.so:security/botan3 \
		libcapstone.so:devel/capstone \
		libharfbuzz.so:print/harfbuzz \
		libiconv.so:converters/libiconv \
		libjansson.so:devel/jansson \
		libunistring.so:devel/libunistring

USES=		compiler:c++11-lang gmake gnome lua:53 perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	solemnwarning
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 pango
USE_PERL5=	build
USE_WX=		3.0+
MAKE_ENV=	INSTALL_STRIP="${STRIP}" LUA_PKG="lua-${LUA_VER}" LUA="${LUA_CMD}"
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	p5-Template-Toolkit>0:www/p5-Template-Toolkit \
			zip:archivers/zip
DOCS_MAKE_ARGS_OFF=	BUILD_HELP=0

.include <bsd.port.mk>
