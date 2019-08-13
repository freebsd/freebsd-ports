# $FreeBSD$

PORTNAME=	voluptuous
PORTVERSION=	0.11.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python data validation library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && nosetests-${PYTHON_VER}

.include <bsd.port.mk>
