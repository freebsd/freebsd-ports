# Created by: Fukang Chen <loader@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glob2
PORTVERSION=	0.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Glob that captures patterns and supports recursive wildcards

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	distutils concurrent autoplist

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest test.py)

.include <bsd.port.mk>
