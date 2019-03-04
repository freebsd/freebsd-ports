# Created by: Bartek Rutkowski <ports@robakdesign.com>
# $FreeBSD$

PORTNAME=	click
PORTVERSION=	6.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	6

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python package for creating command line interfaces

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -p no:warnings

.include <bsd.port.mk>
