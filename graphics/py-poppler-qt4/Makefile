# $FreeBSD$

PORTNAME=	poppler-qt4
PORTVERSION=	0.16.3
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	python-poppler-qt4
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Python bindings for poppler-qt4

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	sip:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=0:${PORTSDIR}/textproc/py-qt4-xml
LIB_DEPENDS=	poppler-qt4:${PORTSDIR}/graphics/poppler-qt4
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=0:${PORTSDIR}/textproc/py-qt4-xml

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGNAME=	python_poppler_qt4

.include <bsd.port.mk>
