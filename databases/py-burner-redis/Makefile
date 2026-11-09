PORTNAME=	burner-redis
DISTVERSION=	0.1.7
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embedded, in-process Redis-compatible database
WWW=		https://github.com/PrefectHQ/burner-redis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist pep517 pytest

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}

CARGO_CRATES=	autocfg-1.5.0 \
		bitflags-2.11.0 \
		block-buffer-0.10.4 \
		bstr-1.12.1 \
		bytes-1.11.1 \
		cc-1.2.60 \
		cfg-if-1.0.4 \
		cpufeatures-0.2.17 \
		crypto-common-0.1.7 \
		digest-0.10.7 \
		either-1.15.0 \
		env_home-0.1.0 \
		errno-0.3.14 \
		find-msvc-tools-0.1.9 \
		futures-channel-0.3.32 \
		futures-core-0.3.32 \
		futures-macro-0.3.32 \
		futures-task-0.3.32 \
		futures-util-0.3.32 \
		generic-array-0.14.7 \
		hashbrown-0.15.5 \
		heck-0.5.0 \
		home-0.5.11 \
		indexmap-2.9.0 \
		indoc-2.0.6 \
		libc-0.2.182 \
		linux-raw-sys-0.12.1 \
		lock_api-0.4.14 \
		lua-src-547.0.0 \
		luajit-src-210.5.12+a4f56a4 \
		memchr-2.8.0 \
		mlua-0.10.5 \
		mlua-sys-0.6.8 \
		num-traits-0.2.19 \
		once_cell-1.21.4 \
		ordered-float-5.3.0 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		pin-project-lite-0.2.17 \
		pkg-config-0.3.32 \
		portable-atomic-1.13.1 \
		proc-macro2-1.0.106 \
		pyo3-0.28.3 \
		pyo3-async-runtimes-0.28.0 \
		pyo3-build-config-0.28.3 \
		pyo3-ffi-0.28.3 \
		pyo3-macros-0.28.3 \
		pyo3-macros-backend-0.28.3 \
		quote-1.0.45 \
		redox_syscall-0.5.18 \
		rmp-0.8.15 \
		rmp-serde-1.3.1 \
		rustc-hash-2.1.2 \
		rustix-1.1.4 \
		rustversion-1.0.22 \
		scopeguard-1.2.0 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		sha1-0.10.6 \
		shlex-1.3.0 \
		slab-0.4.12 \
		smallvec-1.15.1 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		thiserror-2.0.18 \
		thiserror-impl-2.0.18 \
		tokio-1.51.1 \
		tokio-macros-2.7.0 \
		typenum-1.19.0 \
		unicode-ident-1.0.24 \
		version_check-0.9.5 \
		which-7.0.3 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		winsafe-0.0.19

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/burner_redis/*.so

# tests as of 0.1.7: 590 passed in 24.13s

.include <bsd.port.mk>
