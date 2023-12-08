PORTNAME=	maturin
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Build and publish crates with pyo3, rust-cpython and cffi bindings
WWW=		https://github.com/PyO3/maturin

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/license-apache
LICENSE_FILE_MIT=	${WRKSRC}/license-mit

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>=1.4.0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.36.2:devel/py-wheel@${PY_FLAVOR}

USES=		cargo python
USE_GITHUB=	yes
GH_ACCOUNT=	PyO3
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

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR}
.endif

post-patch:
	@${RM} ${WRKSRC}/pyproject.toml
	${REINPLACE_CMD} 's|%%PYTHON_VER%%|${PYTHON_VER}|' ${WRKSRC}/maturin/__init__.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/maturin

.include <bsd.port.post.mk>
