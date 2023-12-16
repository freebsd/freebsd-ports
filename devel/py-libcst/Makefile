PORTNAME=	libcst
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Concrete syntax tree with AST-like properties
WWW=		https://github.com/Instagram/LibCST

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>=0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=5.2:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4.2:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-inspect>=0.4.0:devel/py-typing-inspect@${PY_FLAVOR}

USES=		cargo dos2unix python
USE_PYTHON=	autoplist concurrent pep517

BINARY_ALIAS=	python3=${PYTHON_CMD}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_CARGOLOCK=${WRKSRC}/native/Cargo.lock
CARGO_CARGOTOML=${WRKSRC}/native/Cargo.toml

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}libcst03

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
