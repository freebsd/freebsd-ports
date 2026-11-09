PORTNAME=	protobuf-py-pure
PORTVERSION=	0.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	protobuf_py_pure-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Python implementation of protobuf-py, idiomatic Protocol Buffers for Python
WWW=		https://protobufpy.com/ \
		https://github.com/bufbuild/protobuf-py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SOURCE_DATE_EPOCH=315532800 # 1980-01-01 00:00:00 UTC
NO_ARCH=	yes

.include <bsd.port.mk>
