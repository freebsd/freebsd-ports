# $FreeBSD$

PORTNAME=	poppler-qt4
PORTVERSION=	0.18.1
PORTREVISION=	12
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Python bindings for the Poppler-Qt4 PDF rendering library

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libpoppler-qt4.so:graphics/poppler-qt4

USES=		compiler:c++11-lang pkgconfig pyqt:4 python
USE_PYQT=	gui xml sip_build
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
