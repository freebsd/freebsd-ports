# $FreeBSD$

PORTNAME=	dbussupport
PORTREVISION=	1
CATEGORIES=	devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt event loop support for dbus-python

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.8:devel/py-dbus@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.8:devel/py-dbus@${PY_FLAVOR}

CONFIGURE_ARGS=	--enable QtCore
PYQT_DIST=	yes

USES=		pkgconfig python pyqt:4 qt:4
USE_PYQT=	sip_build
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		corelib qmake_build moc_build

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--debug --trace

BUILD_WRKSRC=	${WRKSRC}/dbus
INSTALL_WRKSRC=	${WRKSRC}/dbus

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/dbus/mainloop/qt.so

.include <bsd.port.mk>
