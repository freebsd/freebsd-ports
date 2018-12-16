# $FreeBSD$

PORTNAME=	dbussupport
CATEGORIES=	devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt event loop support for dbus-python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.8:devel/py-dbus@${PY_FLAVOR} \
		${PY_ENUM34}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.8:devel/py-dbus@${PY_FLAVOR} \
		${PY_ENUM34}

CONFIGURE_ARGS=	--enable QtCore
PYQT_DIST=	yes

USES=		pkgconfig python pyqt:5 qt:5
USE_PYQT=	sip_build
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core buildtools_build qmake_build

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--debug --trace

BUILD_WRKSRC=	${WRKSRC}/dbus
INSTALL_WRKSRC=	${WRKSRC}/dbus

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/dbus/mainloop/pyqt5.so

.include <bsd.port.mk>
