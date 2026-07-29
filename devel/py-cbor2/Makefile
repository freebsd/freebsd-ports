PORTNAME=	cbor2
DISTVERSION=	6.1.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pure Python CBOR (de)serializer with extensive tag support
WWW=		https://pypi.org/project/cbor2/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	requires 64-bit architecture

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=7:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		cpe cargo python
CPE_VENDOR=	agronholm
USE_PYTHON=	autoplist concurrent pep517 pytest

CARGO_CARGOLOCK=${WRKSRC}/rust/Cargo.lock
CARGO_CARGOTOML=${WRKSRC}/rust/Cargo.toml
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_SRC_SUBDIR=	rust

post-patch:
	@${REINPLACE_CMD} '/license-files/d; s|^license = "MIT"|license = { text = "MIT" }|; s|77|63|g' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
