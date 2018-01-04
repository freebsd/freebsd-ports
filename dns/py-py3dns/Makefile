# Created by: Mark Linimon <linimon@lonesome.com>
# $FreeBSD$

PORTNAME=	py3dns
PORTVERSION=	3.1.1
DISTVERSIONSUFFIX=	a
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python 3 DNS library

LICENSE=	CNRI
LICENSE_NAME=	CNRI LICENSE AGREEMENT
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:3.3+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-test:
	cd ${WRKSRC}/ && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
