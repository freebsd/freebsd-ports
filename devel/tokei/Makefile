# $FreeBSD$

PORTNAME=	tokei
DISTVERSIONPREFIX=	v
DISTVERSION=	9.1.1
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Display statistics about your code

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENCE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENCE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	XAMPPRocky

CARGO_CRATES=	aho-corasick-0.6.10 \
		ansi_term-0.11.0 \
		argon2rs-0.2.5 \
		arrayref-0.3.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.14 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		block-buffer-0.3.3 \
		byte-tools-0.2.0 \
		byteorder-1.3.1 \
		cc-1.0.32 \
		cfg-if-0.1.7 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		crossbeam-channel-0.3.8 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		crossbeam-utils-0.6.5 \
		digest-0.7.6 \
		dirs-1.0.5 \
		dtoa-0.4.3 \
		either-1.5.1 \
		encoding_rs-0.8.17 \
		encoding_rs_io-0.1.5 \
		env_logger-0.6.1 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fake-simd-0.1.2 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		generic-array-0.9.0 \
		globset-0.4.2 \
		half-1.3.0 \
		handlebars-1.1.0 \
		hex-0.3.2 \
		humantime-1.2.0 \
		ignore-0.4.6 \
		itoa-0.4.3 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		libc-0.2.51 \
		linked-hash-map-0.5.2 \
		log-0.4.6 \
		maplit-1.0.1 \
		memchr-2.2.0 \
		memoffset-0.2.1 \
		nodrop-0.1.13 \
		num_cpus-1.10.0 \
		pest-2.1.0 \
		pest_derive-2.1.0 \
		pest_generator-2.1.0 \
		pest_meta-2.1.0 \
		proc-macro2-0.4.27 \
		quick-error-1.2.2 \
		quote-0.6.11 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_os-0.1.3 \
		rayon-1.0.3 \
		rayon-core-1.4.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		redox_users-0.3.0 \
		regex-1.1.2 \
		regex-syntax-0.6.5 \
		rustc-demangle-0.1.13 \
		ryu-0.2.7 \
		same-file-1.0.4 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		serde-1.0.89 \
		serde_cbor-0.9.0 \
		serde_derive-1.0.89 \
		serde_json-1.0.39 \
		serde_yaml-0.8.8 \
		sha-1-0.7.0 \
		smallvec-0.6.9 \
		strsim-0.7.0 \
		syn-0.15.29 \
		synstructure-0.10.1 \
		term_size-0.3.1 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		toml-0.5.0 \
		typenum-1.10.0 \
		ucd-trie-0.1.1 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		walkdir-2.2.7 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1 \
		yaml-rust-0.4.3
CARGO_FEATURES=	all # enable all output serialization formats
NO_TEST=	yes

PLIST_FILES=	bin/tokei

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tokei

.include <bsd.port.mk>
