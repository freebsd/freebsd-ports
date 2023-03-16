PORTNAME=	argc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
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
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.8.1 \
		encode_unicode-0.3.6 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		fastrand-1.9.0 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
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
		lazy_static-1.4.0 \
		libc-0.2.140 \
		linked-hash-map-0.5.6 \
		linux-raw-sys-0.1.4 \
		log-0.4.17 \
		memchr-2.5.0 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.15 \
		once_cell-1.17.1 \
		os_str_bytes-6.4.1 \
		predicates-2.1.5 \
		predicates-core-1.0.5 \
		predicates-tree-1.0.7 \
		redox_syscall-0.2.16 \
		regex-1.7.1 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		rustix-0.36.9 \
		same-file-1.0.6 \
		serde-1.0.155 \
		similar-2.2.1 \
		strsim-0.10.0 \
		tempfile-3.4.0 \
		termcolor-1.2.0 \
		termtree-0.4.0 \
		thread_local-1.1.7 \
		unicode-segmentation-1.10.1 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
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
