PORTNAME=	pylyzer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.51
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Static code analyzer & language server for Python
WWW=		https://mtshiba.github.io/pylyzer/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		git:devel/git

USES=		cargo python
USE_PYTHON=	pep517 noflavors autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	mtshiba

CARGO_CRATES=	Inflector-0.11.4 \
		addr2line-0.21.0 \
		adler-1.0.2 \
		anyhow-1.0.75 \
		autocfg-1.1.0 \
		backtrace-0.3.69 \
		backtrace-on-stack-overflow-0.3.0 \
		base64-0.13.1 \
		bitflags-1.3.2 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		convert_case-0.4.0 \
		crunchy-0.2.2 \
		derive_more-0.99.17 \
		either-1.9.0 \
		els-0.1.39 \
		embed-doc-image-0.1.4 \
		erg_common-0.6.27 \
		erg_compiler-0.6.27 \
		erg_parser-0.6.27 \
		erg_proc_macros-0.6.27 \
		form_urlencoded-1.2.1 \
		gimli-0.28.1 \
		idna-0.5.0 \
		is-macro-0.2.2 \
		itertools-0.10.5 \
		itertools-0.11.0 \
		itoa-1.0.10 \
		lalrpop-util-0.20.0 \
		libc-0.2.150 \
		lock_api-0.4.11 \
		log-0.4.20 \
		lsp-types-0.93.2 \
		malachite-0.4.4 \
		malachite-base-0.4.4 \
		malachite-bigint-0.1.1 \
		malachite-nz-0.4.4 \
		malachite-q-0.4.4 \
		memchr-2.6.4 \
		memoffset-0.6.5 \
		miniz_oxide-0.7.1 \
		molc-0.2.7 \
		nix-0.23.2 \
		num-integer-0.1.45 \
		num-traits-0.2.17 \
		object-0.32.1 \
		once_cell-1.19.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		paste-1.0.14 \
		percent-encoding-2.3.1 \
		phf-0.11.2 \
		phf_codegen-0.11.2 \
		phf_generator-0.11.2 \
		phf_shared-0.11.2 \
		pmutil-0.5.3 \
		proc-macro2-1.0.70 \
		quote-1.0.33 \
		rand-0.8.5 \
		rand_core-0.6.4 \
		redox_syscall-0.4.1 \
		rustc-demangle-0.1.23 \
		rustc-hash-1.1.0 \
		rustc_version-0.4.0 \
		rustpython-ast-0.3.0 \
		rustpython-parser-0.3.0 \
		rustpython-parser-core-0.3.0 \
		rustpython-parser-vendored-0.3.0 \
		ryu-1.0.15 \
		scopeguard-1.2.0 \
		semver-1.0.20 \
		serde-1.0.193 \
		serde_derive-1.0.193 \
		serde_json-1.0.108 \
		serde_repr-0.1.17 \
		siphasher-0.3.11 \
		smallvec-1.11.2 \
		static_assertions-1.1.0 \
		syn-1.0.109 \
		syn-2.0.39 \
		thread_local-1.1.7 \
		tiny-keccak-2.0.2 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-emoji-char-0.9.0 \
		unic-ucd-ident-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicode-bidi-0.3.14 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.22 \
		unicode-xid-0.2.4 \
		unicode_names2-0.6.0 \
		url-2.5.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pylyzer

.include <bsd.port.mk>
