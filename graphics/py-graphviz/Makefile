# Created by: lbartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	0.8.3
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Simple Python interface for Graphviz

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	dot:graphics/graphviz
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${FLAVOR}

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} run-tests.py

.include <bsd.port.mk>
