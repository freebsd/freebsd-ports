PORTNAME=	pytweening
DISTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A collection of tweening or easing functions
WWW=		https://github.com/asweigart/pytweening

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist pep517

DOS2UNIX_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
