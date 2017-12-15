# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codecov
PORTVERSION=	2.0.10
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Hosted coverage reports for Github, Bitbucket and Gitlab

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.9:www/py-requests@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ddt>0:devel/py-ddt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-python

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v tests/test.py

.include <bsd.port.mk>
