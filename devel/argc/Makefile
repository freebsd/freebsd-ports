PORTNAME=	argc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
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

CARGO_CRATES=	aho-corasick-0.7.19 \
		anyhow-1.0.65 \
		assert_cmd-2.0.4 \
		assert_fs-1.0.7 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		cfg-if-1.0.0 \
		clap-4.0.2 \
		clap_lex-0.3.0 \
		console-0.15.1 \
		convert_case-0.5.0 \
		crossbeam-utils-0.8.11 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.8.0 \
		encode_unicode-0.3.6 \
		fastrand-1.8.0 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		globset-0.4.9 \
		globwalk-0.8.1 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		ignore-0.4.18 \
		indexmap-1.9.1 \
		insta-1.20.0 \
		instant-0.1.12 \
		itertools-0.10.5 \
		lazy_static-1.4.0 \
		libc-0.2.133 \
		linked-hash-map-0.5.6 \
		log-0.4.17 \
		memchr-2.5.0 \
		minimal-lexical-0.2.1 \
		nom-7.1.1 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.15 \
		once_cell-1.15.0 \
		os_str_bytes-6.3.0 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		redox_syscall-0.2.16 \
		regex-1.6.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.27 \
		remove_dir_all-0.5.3 \
		same-file-1.0.6 \
		similar-2.2.0 \
		strsim-0.10.0 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		termtree-0.2.4 \
		thread_local-1.1.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
