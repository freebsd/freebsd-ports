PORTNAME=	thrift
PORTVERSION=	0.25.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
DIST_SUBDIR=	python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for the Apache Thrift RPC system
WWW=		https://thrift.apache.org/ \
		https://thrift.apache.org/docs/ \
		https://github.com/apache/thrift/tree/master/lib/py \
		https://github.com/apache/thrift

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

CPE_VENDOR=	apache

OPTIONS_DEFINE=	TORNADO TWISTED
TORNADO_DESC=	Tornado support
TWISTED_DESC=	Twisted support

TORNADO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=6.3.0:www/py-tornado@${PY_FLAVOR}
TWISTED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=24.3.0:devel/py-twisted@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zope.interface>=6.1:devel/py-zope.interface@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
