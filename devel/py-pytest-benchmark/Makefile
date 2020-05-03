# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytest-benchmark
PORTVERSION=	3.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	pytest fixture for benchmarking code

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py-cpuinfo>=0:sysutils/py-cpuinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3.8:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
