# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	envisage
PORTVERSION=	4.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Enthought extensible application framework

LICENSE=	BSD3CLAUSE PSFL LGPL20
LICENSE_COMB=	multi
# See image_LICENSE.txt files for per file license information

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apptools>0:devel/py-apptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traits>=4.5.0:devel/py-traits@${PY_FLAVOR}
# Above requirements are defined in setup.py

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	${PYTHON_CMD} -m unittest discover -v envisage

.include <bsd.port.mk>
