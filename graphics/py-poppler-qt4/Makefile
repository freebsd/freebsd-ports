# $FreeBSD$

PORTNAME=	poppler-qt4
PORTVERSION=	0.18.1
PORTREVISION=	8
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Python bindings for the Poppler-Qt4 PDF rendering library

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	sip:devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=0:textproc/py-qt4-xml
LIB_DEPENDS=	libpoppler-qt4.so:graphics/poppler-qt4
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=0:textproc/py-qt4-xml

USES=		pkgconfig python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
