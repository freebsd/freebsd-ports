PORTNAME=	protobuf-py
PORTVERSION=	0.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	protobuf_py-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Idiomatic Protocol Buffers for Python
WWW=		https://protobufpy.com/ \
		https://github.com/bufbuild/protobuf-py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf-py-ext>=${PORTVERSION}<${PORTVERSION}_99:devel/py-protobuf-py-ext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf-py-pure>=${PORTVERSION}<${PORTVERSION}_99:devel/py-protobuf-py-pure@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
