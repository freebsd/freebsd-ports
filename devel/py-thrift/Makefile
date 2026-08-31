PORTNAME=	thrift
PORTVERSION=	0.24.0
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
DIST_SUBDIR=	python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the Apache Thrift RPC system
WWW=		https://thrift.apache.org/ \
		https://thrift.apache.org/docs/ \
		https://github.com/apache/thrift/tree/master/lib/py \
		https://github.com/apache/thrift

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

CPE_VENDOR=	apache

.include <bsd.port.mk>
