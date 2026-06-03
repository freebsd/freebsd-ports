PORTNAME=	types-python-dateutil
DISTVERSION=	2.9.0.20260402
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	types_python_dateutil-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Typing stubs for python-dateutil
WWW=		https://github.com/python/typeshed

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
