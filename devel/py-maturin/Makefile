PORTNAME=	maturin
DISTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
# Workaround to use both the PyPI tarball and the cargo crates.
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Build and publish crates with pyo3, rust-cpython and cffi bindings
WWW=		https://github.com/PyO3/maturin

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/license-apache
LICENSE_FILE_MIT=	${WRKSRC}/license-mit

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>=1.4.0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.36.2:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libzstd.so:archivers/zstd
RUN_DEPENDS=	${PY_TOMLI}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TARGET_DIR=	${WRKSRC}/target
MAKE_ENV=	${CARGO_ENV}
BINARY_ALIAS=	python3=${PYTHON_CMD}

# NB: There are two options in "pyproject.toml" (= "patchelf" + "zig") but both
#     seem to be a no-op on FreeBSD at the moment, so they were deliberately
#     not added.

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
CARGO_BUILD_ARGS=	--no-default-features \
			--features=upload,log,human-panic
.endif

post-patch:
	${REINPLACE_CMD} 's|%%PYTHON_VER%%|${PYTHON_VER}|' ${WRKSRC}/maturin/__init__.py

.include <bsd.port.mk>
