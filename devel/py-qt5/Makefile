# $FreeBSD$

PORTNAME=	qt5
PORTVERSION=	${PYQT5_VERSION}
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt 5 toolkit (meta port)

USES=		metaport python pyqt:5
USE_PYTHON=	flavors

OPTIONS_DEFINE=	core dbus dbussupport demo designer \
		designerplugin gui multimedia multimediawidgets \
		network opengl printsupport qml qscintilla2 sql \
		serialport svg test webkit webkitwidgets \
		widgets xml xmlpatterns
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

.for opt in ${OPTIONS_DEFINE}
${opt}_USE=	PYQT=${opt}_run
${opt}_DESC=	${py-${opt}_DESC}
.endfor

.include <bsd.port.mk>
