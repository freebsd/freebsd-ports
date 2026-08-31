PORTNAME=	protobuf-py-ext
PORTVERSION=	0.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	protobuf_py_ext-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Native extension for protobuf-py
WWW=		https://protobufpy.com/ \
		https://github.com/bufbuild/protobuf-py/tree/main/packages/protobuf-py-ext \
		https://github.com/bufbuild/protobuf-py

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.12<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
WRKSRC=		${WRKDIR}/protobuf_py_ext-${PORTVERSION}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
