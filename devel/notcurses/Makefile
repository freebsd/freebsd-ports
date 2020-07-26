# $FreeBSD$

PORTNAME=	notcurses
DISTVERSIONPREFIX=	v
DISTVERSION=	${ABIVERSION}.6.6
CATEGORIES=	devel

MAINTAINER=	nickblack@linux.com
COMMENT=	TUI library for modern terminal emulators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libqrcodegen.so:graphics/qr-code-generator
BUILD_DEPENDS=	${LOCALBASE}/include/doctest/doctest.h:devel/doctest \
    pandoc:textproc/hs-pandoc

USES=		cmake:noninja compiler:c++17-lang localbase ncurses:port pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dankamongmen
USE_LDCONFIG=	yes

LDFLAGS+=	-lc

ABIVERSION=	1

PLIST_SUB=	REL_VER=${DISTVERSION} ABI_VER=${ABIVERSION}

OPTIONS_SUB=yes
OPTIONS_DEFINE= DOCS

PORTDOCS=	*.md

TEST_TARGET= test

.include <bsd.port.mk>
