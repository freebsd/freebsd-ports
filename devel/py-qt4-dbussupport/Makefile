# $FreeBSD$

PORTNAME=	dbussupport
PORTREVISION=	1
CATEGORIES=	devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, D-BUS module

CONFLICTS_INSTALL=	py*-qt4-dbus-4.9.1*

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.8:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.8:${PORTSDIR}/devel/py-dbus \
		${PKGNAMEPREFIX}core>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-core

CONFIGURE_ARGS=	--enable QtCore
PYQT4_DIST=	yes
USES=		pkgconfig
USE_QT4=	corelib qmake_build moc_build

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--debug --trace

BUILD_WRKSRC=	${WRKSRC}/dbus
INSTALL_WRKSRC=	${WRKSRC}/dbus

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/dbus/mainloop/qt.so

.include "${.CURDIR}/../py-qt4/bsd.pyqt.mk"
.include <bsd.port.mk>
