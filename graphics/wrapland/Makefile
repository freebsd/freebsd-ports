PORTNAME=	wrapland
DISTVERSIONPREFIX=	${PORTNAME}@
DISTVERSION=	0.527.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt/C++ library wrapping libwayland
WWW=		https://gitlab.com/kwinft/wrapland

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.22:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland
TEST_DEPENDS=	${qt-testlib_PORT:T}>0:${qt-testlib_PORT}

USES=		cmake:testing gl kde:5 pkgconfig qt:5
USE_GITLAB=	yes
USE_GL=		egl
USE_KDE=	ecm:build
USE_LDCONFIG=	yes
USE_QT=		qmake:build buildtools:build concurrent core gui
GL_ACCOUNT=	kwinft
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_USE=		QT=help:build
DOXYGEN_CMAKE_BOOL=	BUILD_QCH

.include <bsd.port.mk>
