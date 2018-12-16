# $FreeBSD$

PORTNAME=	designerplugin
CATEGORIES=	devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtDesigner plugin

BUILD_DEPENDS=	${PY_ENUM34}
RUN_DEPENDS=	${PY_ENUM34}

BUILD_WRKSRC=	${WRKSRC}/designer
INSTALL_WRKSRC=	${WRKSRC}/designer
DESTDIRNAME=	INSTALL_ROOT

CONFIGURE_ARGS=	--enable QtDesigner

PYQT_DIST=	yes

USES=		python pyqt:5 qt:5
USE_GL=		gl
USE_PYQT=	sip_build
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core designer gui xml widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--debug --trace

PLIST_FILES=	${PYQT_DESIGNERDIR}/libpyqt5.so

.include <bsd.port.mk>
