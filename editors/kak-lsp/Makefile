# $FreeBSD$

PORTNAME=	kak-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2.1
PORTREVISION=	7
CATEGORIES=	editors

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Kakoune Language Server Protocol Client

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	kakoune>=2018.10.27:editors/kakoune

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ul

CARGO_CRATES=	adler32-1.0.3 \
		aho-corasick-0.6.10 \
		aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		argon2rs-0.2.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.15 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		boxfnonce-0.1.1 \
		byteorder-1.3.1 \
		cc-1.0.35 \
		cfg-if-0.1.7 \
		chrono-0.4.6 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		crc32fast-1.2.0 \
		crossbeam-0.2.12 \
		crossbeam-0.6.0 \
		crossbeam-channel-0.2.6 \
		crossbeam-channel-0.3.8 \
		crossbeam-deque-0.6.3 \
		crossbeam-epoch-0.6.1 \
		crossbeam-epoch-0.7.1 \
		crossbeam-utils-0.5.0 \
		crossbeam-utils-0.6.5 \
		daemonize-0.4.1 \
		dirs-1.0.5 \
		either-1.5.2 \
		enum_primitive-0.1.1 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		futures-0.1.26 \
		glob-0.3.0 \
		idna-0.1.5 \
		isatty-0.1.9 \
		itertools-0.8.0 \
		itoa-0.4.3 \
		jsonrpc-core-8.0.1 \
		lazy_static-1.3.0 \
		libc-0.2.51 \
		libflate-0.1.22 \
		lock_api-0.1.5 \
		log-0.3.9 \
		log-0.4.6 \
		lsp-types-0.57.1 \
		matches-0.1.8 \
		memchr-2.2.0 \
		memoffset-0.2.1 \
		nodrop-0.1.13 \
		num-derive-0.2.4 \
		num-integer-0.1.39 \
		num-traits-0.1.43 \
		num-traits-0.2.6 \
		num_cpus-1.10.0 \
		numtoa-0.1.0 \
		owning_ref-0.4.0 \
		parking_lot-0.6.4 \
		parking_lot-0.7.1 \
		parking_lot_core-0.3.1 \
		parking_lot_core-0.4.0 \
		percent-encoding-1.0.1 \
		proc-macro2-0.4.27 \
		quote-0.6.12 \
		rand-0.5.6 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.3 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		redox_users-0.3.0 \
		regex-0.2.11 \
		regex-1.1.6 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.6 \
		ropey-1.0.0 \
		rustc-demangle-0.1.14 \
		rustc_version-0.2.3 \
		ryu-0.2.7 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.90 \
		serde_derive-1.0.90 \
		serde_json-1.0.39 \
		slog-2.4.1 \
		slog-async-2.3.0 \
		slog-kvfilter-0.7.0 \
		slog-scope-4.1.1 \
		slog-stdlog-3.0.2 \
		slog-term-2.4.0 \
		sloggers-0.3.2 \
		smallvec-0.6.9 \
		stable_deref_trait-1.1.1 \
		strsim-0.8.0 \
		syn-0.15.32 \
		synstructure-0.10.1 \
		take_mut-0.2.2 \
		term-0.5.2 \
		termion-1.5.2 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		toml-0.5.0 \
		trackable-0.2.21 \
		trackable_derive-0.1.2 \
		ucd-util-0.1.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		url-1.7.2 \
		url_serde-0.2.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		whoami-0.5.0 \
		winapi-0.3.7 \
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
