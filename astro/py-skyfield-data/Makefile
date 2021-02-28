# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	skyfield-data
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	astro python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Minimal data files to work with py-skyfield

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}skyfield>0:astro/py-skyfield@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	brunobord

USES=		python:3.7+
USE_PYTHON=	distutils

NO_ARCH=	yes

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
