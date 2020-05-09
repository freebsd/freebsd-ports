# $FreeBSD$

PORTNAME=	dtool
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	devel

MAINTAINER=	vulcan@wired.sh
COMMENT=	Command-line tool collection to assist development

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	guoxbin

CARGO_CRATES=	aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		anyhow-1.0.26 \
		arrayref-0.3.5 \
		arrayvec-0.4.12 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-0.1.7 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bs58-0.3.0 \
		bstr-0.2.9 \
		build_const-0.2.1 \
		bumpalo-3.2.0 \
		byte-tools-0.3.1 \
		byteorder-1.3.2 \
		cc-1.0.41 \
		cfg-if-0.1.10 \
		chrono-0.4.10 \
		clap-2.33.0 \
		clear_on_drop-0.2.3 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.5 \
		crc-1.8.1 \
		crossbeam-utils-0.6.6 \
		csv-1.1.2 \
		csv-core-0.1.6 \
		curve25519-dalek-1.2.3 \
		digest-0.8.1 \
		dirs-1.0.5 \
		dtoa-0.4.4 \
		ecdsa-0.3.0 \
		elliptic-curve-0.2.0 \
		encode_unicode-0.3.6 \
		entities-1.0.1 \
		escaper-0.1.0 \
		failure-0.1.6 \
		fake-simd-0.1.2 \
		fuchsia-cprng-0.1.1 \
		gcc-0.3.55 \
		generic-array-0.12.3 \
		getrandom-0.1.14 \
		heck-0.3.1 \
		hermit-abi-0.1.6 \
		hex-0.4.0 \
		indexmap-1.3.1 \
		itoa-0.4.4 \
		js-sys-0.3.35 \
		keccak-0.1.0 \
		lazy_static-1.4.0 \
		libc-0.2.66 \
		linked-hash-map-0.5.2 \
		log-0.4.8 \
		madato-0.5.3 \
		md5-0.7.0 \
		memchr-2.3.0 \
		merlin-1.3.0 \
		nodrop-0.1.14 \
		nom-4.2.3 \
		num-integer-0.1.42 \
		num-traits-0.2.11 \
		opaque-debug-0.2.3 \
		parity-codec-3.5.4 \
		prettytable-rs-0.8.0 \
		proc-macro2-1.0.8 \
		quote-1.0.2 \
		rand-0.3.23 \
		rand-0.4.6 \
		rand-0.5.6 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.3 \
		regex-1.3.3 \
		regex-automata-0.1.8 \
		regex-syntax-0.6.13 \
		ring-fork-dtool-0.16.13 \
		ripemd160-0.8.0 \
		rust-argon2-0.6.1 \
		rust-crypto-0.2.36 \
		rustc-serialize-0.3.24 \
		ryu-1.0.2 \
		schnorrkel-0.8.5 \
		secp256k1-0.15.5 \
		serde-1.0.104 \
		serde_derive-1.0.104 \
		serde_test-1.0.104 \
		serde_yaml-0.7.5 \
		sha2-0.8.1 \
		sha3-0.8.2 \
		signatory-0.17.1 \
		signatory-secp256k1-0.17.0 \
		signature-1.0.0-pre.1 \
		signature_derive-1.0.0-pre.0 \
		sourcefile-0.1.4 \
		spin-0.5.2 \
		strsim-0.8.0 \
		subtle-2.2.2 \
		subtle-encoding-0.4.1 \
		syn-1.0.14 \
		synstructure-0.12.3 \
		term-0.5.2 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.42 \
		typenum-1.11.2 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		untrusted-0.7.0 \
		urlencoding-1.0.0 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.58 \
		wasm-bindgen-backend-0.2.58 \
		wasm-bindgen-macro-0.2.58 \
		wasm-bindgen-macro-support-0.2.58 \
		wasm-bindgen-shared-0.2.58 \
		wasm-bindgen-webidl-0.2.58 \
		web-sys-0.3.35 \
		weedle-0.10.0 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.3 \
		yogcrypt-0.0.0 \
		zeroize-0.9.3 \
		zeroize-1.1.0 \
		zeroize_derive-1.0.0

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=	DOCS

DOCS=		docs/Usage.md README.md

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
