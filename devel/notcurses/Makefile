# $FreeBSD$

PORTNAME=	notcurses
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	devel

MAINTAINER=	nickblack@linux.com
COMMENT=	TUI library for modern terminal emulators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libqrcodegen.so:graphics/qr-code-generator

USES=		cmake compiler:c++17-lang localbase ncurses:port pkgconfig python:run shebangfix
SHEBANG_FILES=	src/pydemo/notcurses-pydemo
USE_GITHUB=	yes
GH_ACCOUNT=	dankamongmen
USE_LDCONFIG=	yes

CMAKE_OFF=	USE_PANDOC USE_TESTS USE_PYTHON

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
