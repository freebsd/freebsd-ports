PORTNAME=	argc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easily parse command line arguments in bash
WWW=		https://github.com/sigoden/argc

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	sigoden

CARGO_CRATES=	aho-corasick-0.7.20 \
		anyhow-1.0.69 \
		assert_cmd-2.0.8 \
		assert_fs-1.0.10 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-1.3.0 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		clap-4.1.8 \
		clap_lex-0.3.2 \
		console-0.15.5 \
		convert_case-0.6.0 \
		ctrlc-3.2.5 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.8.1 \
		encode_unicode-0.3.6 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		fastrand-1.9.0 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		futures-0.3.27 \
		futures-channel-0.3.27 \
		futures-core-0.3.27 \
		futures-executor-0.3.27 \
		futures-io-0.3.27 \
		futures-macro-0.3.27 \
		futures-sink-0.3.27 \
		futures-task-0.3.27 \
		futures-timer-3.0.2 \
		futures-util-0.3.27 \
		globset-0.4.10 \
		globwalk-0.8.1 \
		hashbrown-0.12.3 \
		hermit-abi-0.3.1 \
		ignore-0.4.20 \
		indexmap-1.9.2 \
		insta-1.28.0 \
		instant-0.1.12 \
		io-lifetimes-1.0.6 \
		is-terminal-0.4.4 \
		itertools-0.10.5 \
		itoa-1.0.6 \
		lazy_static-1.4.0 \
		libc-0.2.140 \
		linked-hash-map-0.5.6 \
		linux-raw-sys-0.1.4 \
		log-0.4.17 \
		memchr-2.5.0 \
		minimal-lexical-0.2.1 \
		nix-0.26.2 \
		nom-7.1.3 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.15 \
		once_cell-1.17.1 \
		os_str_bytes-6.4.1 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		predicates-2.1.5 \
		predicates-core-1.0.5 \
		predicates-tree-1.0.7 \
		proc-macro2-1.0.54 \
		quote-1.0.26 \
		redox_syscall-0.2.16 \
		regex-1.7.1 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		rstest-0.15.0 \
		rstest_macros-0.14.0 \
		rustc_version-0.4.0 \
		rustix-0.36.9 \
		ryu-1.0.13 \
		same-file-1.0.6 \
		semver-1.0.17 \
		serde-1.0.158 \
		serde_derive-1.0.158 \
		serde_json-1.0.94 \
		shell-words-1.1.0 \
		similar-2.2.1 \
		slab-0.4.8 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.109 \
		syn-2.0.10 \
		tempfile-3.4.0 \
		termcolor-1.2.0 \
		termtree-0.4.0 \
		thread_local-1.1.7 \
		unicode-ident-1.0.8 \
		unicode-segmentation-1.10.1 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		which-4.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.1 \
		windows_aarch64_gnullvm-0.42.1 \
		windows_aarch64_msvc-0.42.1 \
		windows_i686_gnu-0.42.1 \
		windows_i686_msvc-0.42.1 \
		windows_x86_64_gnu-0.42.1 \
		windows_x86_64_gnullvm-0.42.1 \
		windows_x86_64_msvc-0.42.1 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
