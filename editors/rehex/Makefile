PORTNAME=	rehex
DISTVERSION=	0.60.1
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Hex editor for reverse engineering
WWW=		https://github.com/solemnwarning/rehex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

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
MAKE_ENV=	INSTALL_STRIP="${STRIP}" LUA_PKG="lua-${LUA_VER}" LUA="${LUA_CMD}"
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	p5-Template-Toolkit>0:www/p5-Template-Toolkit \
			zip:archivers/zip
DOCS_MAKE_ARGS_OFF=	BUILD_HELP=0

.include <bsd.port.mk>
