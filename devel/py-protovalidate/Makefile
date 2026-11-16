PORTNAME=	protovalidate
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	protovalidate-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Protocol Buffer Validation for Python
WWW=		https://protovalidate.com/ \
		https://github.com/bufbuild/protovalidate-py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: static assertion failed due to requirement 'alignof(cel::Value) <= alignof(__max_align_t)'

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.12<2.0:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf-py>=0.6.0:devel/py-protobuf-py@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

.include <bsd.port.mk>
