# $FreeBSD$

PORTNAME=	qtbuilder
PORTVERSION=	1.4.0 # ${QTBUILDER_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.io/packages/source/P/PyQt-builder/  # ${MASTER_SITES_QTBUILDER}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQt-builder-${PORTVERSION} # ${QTBUILDER_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The PEP 517 compliant PyQt build system

USES=		python
USE_PYTHON=	autoplist concurrent distutils flavors py3kplist
USE_PYQT=	#

NO_ARCH=	yes

.include <bsd.port.mk>
