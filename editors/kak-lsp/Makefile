PORTNAME=	kak-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.0
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Kakoune Language Server Protocol Client

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	kakoune>=2018.10.27:editors/kakoune

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ul

CARGO_CRATES=	adler32-1.1.0 \
		aho-corasick-0.7.13 \
		ansi_term-0.11.0 \
		arc-swap-0.4.7 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		boxfnonce-0.1.1 \
		cfg-if-0.1.10 \
		chrono-0.4.13 \
		clap-2.33.1 \
		constant_time_eq-0.1.5 \
		crc32fast-1.2.0 \
		crossbeam-0.7.3 \
		crossbeam-channel-0.4.2 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.7.2 \
		daemonize-0.4.1 \
		dirs-2.0.2 \
		dirs-sys-0.3.5 \
		either-1.5.3 \
		enum_primitive-0.1.1 \
		futures-0.1.29 \
		getrandom-0.1.14 \
		glob-0.3.0 \
		hermit-abi-0.1.15 \
		idna-0.2.0 \
		itertools-0.9.0 \
		itoa-0.4.6 \
		jsonrpc-core-14.2.0 \
		lazy_static-1.4.0 \
		libc-0.2.73 \
		libflate-1.0.2 \
		libflate_lz77-1.0.0 \
		log-0.4.11 \
		lsp-types-0.80.0 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memoffset-0.5.5 \
		num-integer-0.1.43 \
		num-traits-0.1.43 \
		num-traits-0.2.12 \
		percent-encoding-2.1.0 \
		ppv-lite86-0.2.8 \
		proc-macro2-1.0.19 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		redox_users-0.3.4 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		rle-decode-fast-1.0.1 \
		ropey-1.2.0 \
		rust-argon2-0.7.0 \
		ryu-1.0.5 \
		scopeguard-1.1.0 \
		serde-1.0.114 \
		serde_derive-1.0.114 \
		serde_json-1.0.56 \
		serde_repr-0.1.6 \
		slog-2.5.2 \
		slog-async-2.5.0 \
		slog-kvfilter-0.7.0 \
		slog-scope-4.3.0 \
		slog-stdlog-4.0.0 \
		slog-term-2.6.0 \
		sloggers-1.0.1 \
		smallvec-1.4.1 \
		strsim-0.8.0 \
		syn-1.0.35 \
		take_mut-0.2.2 \
		term-0.6.1 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.43 \
		tinyvec-0.3.3 \
		toml-0.5.6 \
		trackable-1.0.0 \
		trackable_derive-1.0.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.1.1 \
		vec_map-0.8.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
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
