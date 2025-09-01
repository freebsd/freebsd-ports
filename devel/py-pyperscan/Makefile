PORTNAME=	pyperscan
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	10
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

CARGO_CRATES=	aho-corasick-1.1.2 \
		autocfg-1.1.0 \
		bindgen-0.69.1 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		cc-1.0.83 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		clang-sys-1.6.1 \
		cmake-0.1.50 \
		either-1.9.0 \
		errno-0.3.8 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.3 \
		foreign-types-shared-0.3.1 \
		glob-0.3.1 \
		home-0.5.5 \
		indoc-1.0.9 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.151 \
		libloading-0.7.4 \
		linux-raw-sys-0.4.12 \
		lock_api-0.4.11 \
		log-0.4.20 \
		memchr-2.6.4 \
		memoffset-0.8.0 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		once_cell-1.19.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		peeking_take_while-0.1.2 \
		prettyplease-0.2.15 \
		proc-macro2-1.0.70 \
		pyo3-0.18.3 \
		pyo3-build-config-0.18.3 \
		pyo3-ffi-0.18.3 \
		pyo3-macros-0.18.3 \
		pyo3-macros-backend-0.18.3 \
		quote-1.0.33 \
		redox_syscall-0.4.1 \
		regex-1.10.2 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		rustc-hash-1.1.0 \
		rustix-0.38.28 \
		scopeguard-1.2.0 \
		shlex-1.2.0 \
		smallvec-1.11.2 \
		syn-1.0.109 \
		syn-2.0.40 \
		target-lexicon-0.12.12 \
		thiserror-1.0.50 \
		thiserror-impl-1.0.50 \
		unicode-ident-1.0.12 \
		unindent-0.1.11 \
		which-4.4.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.0 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.0 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.0 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.0 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.0 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.0 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.0 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.0

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	FREEBSD_LOCALBASE=${LOCALBASE} \
		PATH=${FILESDIR}:${PATH}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
