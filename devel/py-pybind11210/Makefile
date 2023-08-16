PORTNAME=	pybind11
PORTVERSION=	2.10.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	210

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Seamless operability between C++11 and Python
WWW=		https://github.com/pybind/pybind11

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.10\.

.include <bsd.port.mk>
