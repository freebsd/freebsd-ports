# $FreeBSD$

PORTNAME=	notcurses
DISTVERSIONPREFIX=	v
DISTVERSION=	${ABIVERSION}.5.2
CATEGORIES=	devel

MAINTAINER=	nickblack@linux.com
COMMENT=	TUI library for modern terminal emulators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libqrcodegen.so:graphics/qr-code-generator
BUILD_DEPENDS=	${LOCALBASE}/include/doctest/doctest.h:devel/doctest

USES=		cmake compiler:c++17-lang localbase \
		ncurses:port pkgconfig python:run shebangfix
USE_GITHUB=	yes
SHEBANG_FILES=	src/pydemo/notcurses-pydemo
GH_ACCOUNT=	dankamongmen
USE_LDCONFIG=	yes

LDFLAGS+=	-lc

CMAKE_OFF=	USE_PANDOC USE_TESTS USE_PYTHON

ABIVERSION=	1

PLIST_SUB=	REL_VER=${DISTVERSION} ABI_VER=${ABIVERSION}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
