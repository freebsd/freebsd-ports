# $FreeBSD$

PORTNAME=	apitrace
DISTVERSION=	7.1-455
DISTVERSIONSUFFIX=	-g7c76b90
CATEGORIES=	devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Tools for tracing OpenGL and other graphics APIs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake:outsource compiler:c++11-lang pkgconfig python:2.7 shebangfix
USE_GITHUB=	yes
USE_XORG=	x11

SHEBANG_FILES=	scripts/*.py

OPTIONS_DEFINE=	QT5 DOCS
OPTIONS_DEFAULT=	QT5
OPTIONS_SUB=	yes

QT5_CMAKE_BOOL=	ENABLE_GUI
QT5_USE=	qt5=core,gui,network,widgets,buildtools_build,qmake_build

post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt

post-install-QT5-on:
	${INSTALL_DATA} ${FILESDIR}/qapitrace.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
