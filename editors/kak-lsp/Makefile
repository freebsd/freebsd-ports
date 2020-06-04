# $FreeBSD$

PORTNAME=	kak-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	8.0.0
PORTREVISION=	2
CATEGORIES=	editors

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Kakoune Language Server Protocol Client

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	kakoune>=2018.10.27:editors/kakoune

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ul

CARGO_CRATES=	adler32-1.0.4 \
		aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		arc-swap-0.4.4 \
		arrayref-0.3.5 \
		arrayvec-0.5.1 \
		atty-0.2.13 \
		autocfg-0.1.7 \
		autocfg-1.0.0 \
		backtrace-0.3.40 \
		backtrace-sys-0.1.32 \
		base64-0.10.1 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.9 \
		boxfnonce-0.1.1 \
		byteorder-1.3.2 \
		c2-chacha-0.2.3 \
		cc-1.0.48 \
		cfg-if-0.1.10 \
		chrono-0.4.10 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.4 \
		crc32fast-1.2.0 \
		crossbeam-0.2.12 \
		crossbeam-channel-0.4.2 \
		crossbeam-utils-0.6.6 \
		crossbeam-utils-0.7.2 \
		daemonize-0.4.1 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		either-1.5.3 \
		enum_primitive-0.1.1 \
		failure-0.1.6 \
		failure_derive-0.1.6 \
		fuchsia-cprng-0.1.1 \
		futures-0.1.29 \
		getrandom-0.1.13 \
		glob-0.3.0 \
		idna-0.2.0 \
		itertools-0.9.0 \
		itoa-0.4.4 \
		jsonrpc-core-14.1.0 \
		lazy_static-1.4.0 \
		libc-0.2.69 \
		libflate-0.1.27 \
		log-0.3.9 \
		log-0.4.8 \
		lsp-types-0.73.0 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.2.1 \
		num-integer-0.1.41 \
		num-traits-0.1.43 \
		num-traits-0.2.10 \
		percent-encoding-2.1.0 \
		ppv-lite86-0.2.6 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.6 \
		quote-0.6.13 \
		quote-1.0.2 \
		rand-0.7.3 \
		rand_chacha-0.2.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_os-0.1.3 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.1 \
		regex-1.3.7 \
		regex-syntax-0.6.17 \
		rle-decode-fast-1.0.1 \
		ropey-1.1.0 \
		rust-argon2-0.5.1 \
		rustc-demangle-0.1.16 \
		ryu-1.0.2 \
		serde-1.0.106 \
		serde_derive-1.0.106 \
		serde_json-1.0.51 \
		serde_repr-0.1.5 \
		slog-2.5.2 \
		slog-async-2.3.0 \
		slog-kvfilter-0.7.0 \
		slog-scope-4.3.0 \
		slog-stdlog-3.0.5 \
		slog-term-2.4.2 \
		sloggers-0.3.5 \
		smallvec-0.6.13 \
		smallvec-1.1.0 \
		strsim-0.8.0 \
		syn-0.15.44 \
		syn-1.0.11 \
		synstructure-0.12.3 \
		take_mut-0.2.2 \
		term-0.6.1 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		thread_local-1.0.1 \
		time-0.1.42 \
		toml-0.5.6 \
		trackable-0.2.23 \
		trackable_derive-0.1.2 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.11 \
		unicode-width-0.1.7 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		url-2.1.1 \
		vec_map-0.8.1 \
		wasi-0.7.0 \
		whoami-0.8.1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

SUB_FILES=	pkg-message

PLIST_FILES=	bin/kak-lsp \
		"@sample ${ETCDIR}/kak-lsp.toml.sample"
PORTDOCS=	README.asciidoc

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kak-lsp
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/kak-lsp.toml ${STAGEDIR}${ETCDIR}/kak-lsp.toml.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.asciidoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
