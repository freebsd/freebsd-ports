PORTNAME=	libcst
PORTVERSION=	1.8.2
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
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cargo dos2unix python
USE_PYTHON=	autoplist concurrent pep517

BINARY_ALIAS=	python3=${PYTHON_CMD}
CARGO_BUILD=	no
CARGO_CARGOLOCK=${WRKSRC}/native/Cargo.lock
CARGO_CARGOTOML=${WRKSRC}/native/Cargo.toml
CARGO_INSTALL=	no

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}libcst03

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyyaml>=5.2:devel/py-pyyaml@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyyaml-ft>=8.0.0:devel/py-pyyaml-ft@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
