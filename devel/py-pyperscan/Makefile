PORTNAME=	pyperscan
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Hyperscan, Intel's regex library
WWW=		https://vlaci.github.io/pyperscan/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0:devel/py-maturin@${PY_FLAVOR}
LIB_DEPENDS=	libhs.so:devel/hyperscan

USES=		cargo llvm localbase python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	vlaci

CARGO_CRATES=	aho-corasick-1.1.5 \
		bindgen-0.73.2 \
		bitflags-2.13.2 \
		cc-1.6.0 \
		cexpr-0.6.0 \
		cfg-if-1.0.5 \
		clang-sys-1.9.1 \
		cmake-0.1.58 \
		find-msvc-tools-0.1.14 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.4 \
		foreign-types-shared-0.3.1 \
		glob-0.3.4 \
		heck-0.5.0 \
		libc-0.2.190 \
		libloading-0.8.9 \
		log-0.4.34 \
		memchr-2.8.3 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		once_cell-1.21.4 \
		portable-atomic-1.15.0 \
		prettyplease-0.3.0 \
		proc-macro2-1.0.107 \
		pyo3-0.29.3 \
		pyo3-build-config-0.29.3 \
		pyo3-ffi-0.29.3 \
		pyo3-macros-0.29.3 \
		pyo3-macros-backend-0.29.3 \
		quote-1.0.47 \
		regex-1.13.1 \
		regex-automata-0.4.18 \
		regex-syntax-0.8.11 \
		rustc-hash-2.1.3 \
		shlex-2.0.1 \
		syn-2.0.119 \
		syn-3.0.6 \
		target-lexicon-0.13.5 \
		thiserror-2.0.21 \
		thiserror-impl-2.0.21 \
		unicode-ident-1.0.26 \
		windows-link-0.2.1

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	FREEBSD_LOCALBASE=${LOCALBASE} \
		PATH=${FILESDIR}:${PATH}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

# tests as of 0.4.0: 21 passed in 0.27s

.include <bsd.port.mk>
