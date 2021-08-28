PORTNAME=	kak-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	10.0.0
PORTREVISION=	2
CATEGORIES=	editors

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Kakoune Language Server Protocol Client

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	kakoune>=2018.10.27:editors/kakoune

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ul

CARGO_CRATES=	adler32-1.2.0 \
		aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		arc-swap-1.2.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.11 \
		boxfnonce-0.1.1 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		constant_time_eq-0.1.5 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.4.4 \
		crossbeam-channel-0.5.0 \
		crossbeam-utils-0.7.2 \
		crossbeam-utils-0.8.1 \
		daemonize-0.4.1 \
		dirs-2.0.2 \
		dirs-sys-0.3.5 \
		either-1.6.1 \
		enum_primitive-0.1.1 \
		form_urlencoded-1.0.0 \
		futures-0.1.30 \
		getrandom-0.1.16 \
		glob-0.3.0 \
		hermit-abi-0.1.18 \
		idna-0.2.0 \
		itertools-0.9.0 \
		itoa-0.4.7 \
		jsonrpc-core-14.2.0 \
		lazy_static-1.4.0 \
		libc-0.2.85 \
		libflate-1.0.3 \
		libflate_lz77-1.0.0 \
		log-0.4.14 \
		lsp-types-0.89.1 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.4 \
		num-integer-0.1.44 \
		num-traits-0.1.43 \
		num-traits-0.2.14 \
		once_cell-1.5.2 \
		percent-encoding-2.1.0 \
		ppv-lite86-0.2.10 \
		proc-macro2-1.0.24 \
		quote-1.0.8 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		regex-1.4.3 \
		regex-syntax-0.6.22 \
		rle-decode-fast-1.0.1 \
		ropey-1.2.0 \
		rust-argon2-0.8.3 \
		ryu-1.0.5 \
		serde-1.0.123 \
		serde_derive-1.0.123 \
		serde_json-1.0.61 \
		serde_repr-0.1.6 \
		slog-2.7.0 \
		slog-async-2.6.0 \
		slog-kvfilter-0.7.0 \
		slog-scope-4.4.0 \
		slog-stdlog-4.1.0 \
		slog-term-2.6.0 \
		sloggers-1.0.1 \
		smallvec-1.6.1 \
		strsim-0.8.0 \
		syn-1.0.60 \
		take_mut-0.2.2 \
		term-0.6.1 \
		textwrap-0.11.0 \
		thread_local-1.1.2 \
		time-0.1.44 \
		tinyvec-1.1.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		trackable-1.0.0 \
		trackable_derive-1.0.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.16 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.2.0 \
		vec_map-0.8.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		whoami-0.8.2 \
		winapi-0.3.9 \
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
