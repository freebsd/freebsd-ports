# $FreeBSD$

PORTNAME=	kak-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	5.10.0
PORTREVISION=	1
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
		aho-corasick-0.6.8 \
		ansi_term-0.11.0 \
		argon2rs-0.2.5 \
		arrayvec-0.4.7 \
		atty-0.2.11 \
		backtrace-0.3.9 \
		backtrace-sys-0.1.24 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		build_const-0.2.1 \
		byteorder-1.2.6 \
		cc-1.0.25 \
		cfg-if-0.1.6 \
		chrono-0.4.6 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		crc-1.8.1 \
		crossbeam-0.2.12 \
		crossbeam-channel-0.2.6 \
		crossbeam-epoch-0.6.0 \
		crossbeam-utils-0.5.0 \
		daemonize-0.3.0 \
		dirs-1.0.4 \
		either-1.5.0 \
		enum_primitive-0.1.1 \
		failure-0.1.3 \
		failure_derive-0.1.3 \
		fnv-1.0.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.25 \
		glob-0.2.11 \
		handlebars-0.32.4 \
		idna-0.1.5 \
		isatty-0.1.9 \
		itertools-0.7.8 \
		itoa-0.4.3 \
		jsonrpc-core-8.0.1 \
		languageserver-types-0.51.0 \
		lazy_static-0.2.11 \
		lazy_static-1.1.0 \
		libc-0.2.43 \
		libflate-0.1.18 \
		lock_api-0.1.4 \
		log-0.3.9 \
		log-0.4.5 \
		matches-0.1.8 \
		memchr-2.1.0 \
		memoffset-0.2.1 \
		nodrop-0.1.12 \
		num-derive-0.2.3 \
		num-integer-0.1.39 \
		num-traits-0.1.43 \
		num-traits-0.2.6 \
		owning_ref-0.3.3 \
		parking_lot-0.6.4 \
		parking_lot_core-0.3.1 \
		percent-encoding-1.0.1 \
		pest-1.0.6 \
		pest_derive-1.0.8 \
		proc-macro2-0.4.20 \
		quick-error-1.2.2 \
		quote-0.3.15 \
		quote-0.6.8 \
		rand-0.4.3 \
		rand-0.5.5 \
		rand_core-0.2.2 \
		rand_core-0.3.0 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		redox_users-0.2.0 \
		regex-0.2.11 \
		regex-1.0.5 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.2 \
		rustc-demangle-0.1.9 \
		rustc_version-0.2.3 \
		ryu-0.2.6 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.80 \
		serde_derive-1.0.80 \
		serde_json-1.0.32 \
		slog-2.4.1 \
		slog-async-2.3.0 \
		slog-kvfilter-0.7.0 \
		slog-scope-4.0.1 \
		slog-stdlog-3.0.2 \
		slog-term-2.4.0 \
		sloggers-0.3.1 \
		smallvec-0.6.5 \
		stable_deref_trait-1.1.1 \
		strsim-0.7.0 \
		syn-0.11.11 \
		syn-0.15.13 \
		synom-0.11.3 \
		synstructure-0.10.0 \
		take_mut-0.2.2 \
		term-0.5.1 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		time-0.1.40 \
		toml-0.4.8 \
		trackable-0.2.20 \
		trackable_derive-0.1.1 \
		ucd-util-0.1.1 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-width-0.1.5 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		url-1.7.1 \
		url_serde-0.2.0 \
		utf8-ranges-1.0.1 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		void-1.0.2 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/kak-lsp \
		"@sample ${ETCDIR}/kak-lsp.toml.sample"
PORTDOCS=	README.asciidoc
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kak-lsp
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/kak-lsp.toml ${STAGEDIR}${ETCDIR}/kak-lsp.toml.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.asciidoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
