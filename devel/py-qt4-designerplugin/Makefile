# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	designerplugin
PORTEPOCH=	1
CATEGORIES=	devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtDesigner plugin

BUILD_WRKSRC=	${WRKSRC}/designer
INSTALL_WRKSRC=	${WRKSRC}/designer
DESTDIRNAME=	INSTALL_ROOT

CONFIGURE_ARGS=	--enable QtDesigner
PYQT_DIST=	yes

USES=		python pyqt:4
USE_PYQT=	sip_build
USE_QT4=	corelib designer gui script xml moc_build qmake_build

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--debug --trace

PLIST_FILES=	%%QT_PLUGINDIR%%/designer/libpyqt4.so

.include <bsd.port.mk>
