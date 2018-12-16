# $FreeBSD$

PORTNAME=	qt5
PORTVERSION=	${PYQT5_VERSION}
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt 5 toolkit (meta port)

USES=		metaport python pyqt:5
USE_PYTHON=	concurrent flavors py3kplist

# Keep these synchronized with _USE_PYQT_ALL / _USE_PYQT5_ONLY in Mk/Use/pyqt.mk
OPTIONS_DEFINE=	core dbus dbussupport demo designer \
		designerplugin gui multimedia multimediawidgets \
		network opengl printsupport qml qscintilla2 quickwidgets \
		sql serialport svg test webchannel webengine webkit \
		webkitwidgets widgets xml xmlpatterns
OPTIONS_DEFAULT=${OPTIONS_DEFINE:Nwebengine}

.for opt in ${OPTIONS_DEFINE}
${opt}_USE=	PYQT=${opt}_run
${opt}_DESC=	${py-${opt}_DESC}
.endfor

.include <bsd.port.mk>
