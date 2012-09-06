# $FreeBSD$

PORTNAME=	poppler-qt4
PORTVERSION=	0.16.2
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	python-poppler-qt4
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Python bindings for poppler-qt4

BUILD_DEPENDS=	${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtXml.so:${PORTSDIR}/textproc/py-qt4-xml
LIB_DEPENDS=	poppler-qt4:${PORTSDIR}/graphics/poppler-qt4
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	python_poppler_qt4-${PORTVERSION}-py${PYTHON_VER}.egg-info

PLIST_FILES=	${PYTHON_SITELIBDIR:S;${PREFIX}/;;}/popplerqt4.so

.include <bsd.port.mk>
