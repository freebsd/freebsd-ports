# $FreeBSD$

PORTNAME=	designerplugin
PORTREVISION=	1
CATEGORIES=	devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtDesigner plugin

BUILD_WRKSRC=	${WRKSRC}/designer
INSTALL_WRKSRC=	${WRKSRC}/designer
DESTDIRNAME=	INSTALL_ROOT

CONFIGURE_ARGS=	--enable QtDesigner
PYQT_DIST=	yes

USES=		python pyqt:5
USE_GL=		gl
USE_PYQT=	sip_build
USE_PYTHON=	flavors
USE_QT5=	core designer gui xml widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--debug --trace

PLIST_FILES=	%%QT_PLUGINDIR%%/designer/libpyqt5.so

.include <bsd.port.mk>
