# $FreeBSD$

PORTNAME=	scikit-bio
PORTVERSION=	0.5.6
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data structures, algorithms, educational resources for bioinformatics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}CacheControl>=0.11.5:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.2:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hdmedians>=0.13:math/py-hdmedians@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=3.2.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.10.2:devel/py-lockfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=4.0.3:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.0.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.19.1:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
