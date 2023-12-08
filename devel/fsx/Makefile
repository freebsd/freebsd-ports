PORTNAME=	fsx
DISTVERSION=	0.1.0
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	File System eXerciser
WWW=		https://github.com/asomers/fsx-rs

LICENSE=	APSL-2.0
LICENSE_NAME=	Apple Public Source License 2.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USES=		cargo

CARGO_CRATES=	aho-corasick-0.7.20 \
		assert_cmd-2.0.7 \
		bitflags-1.3.2 \
		bstr-1.1.0 \
		cc-1.0.78 \
		cfg-if-1.0.0 \
		clap-4.0.32 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		const_panic-0.2.7 \
		ctor-0.1.26 \
		diff-0.1.13 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.8.0 \
		env_logger-0.10.0 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		fastrand-1.8.0 \
		getrandom-0.2.8 \
		heck-0.4.0 \
		hermit-abi-0.2.6 \
		humantime-2.1.0 \
		instant-0.1.12 \
		io-lifetimes-1.0.3 \
		is-terminal-0.4.2 \
		itertools-0.10.5 \
		konst_kernel-0.3.4 \
		libc-0.2.139 \
		linux-raw-sys-0.1.4 \
		log-0.4.17 \
		memchr-2.5.0 \
		nix-0.26.1 \
		once_cell-1.17.0 \
		os_str_bytes-6.4.1 \
		output_vt100-0.1.3 \
		ppv-lite86-0.2.17 \
		predicates-2.1.5 \
		predicates-core-1.0.5 \
		predicates-tree-1.0.7 \
		pretty_assertions-1.3.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.49 \
		quote-1.0.23 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.2.16 \
		regex-1.7.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		remove_dir_all-0.5.3 \
		ringbuffer-0.11.1 \
		rstest-0.11.0 \
		rustc_version-0.4.0 \
		rustix-0.36.6 \
		safemem-0.3.3 \
		semver-1.0.16 \
		serde-1.0.152 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.107 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		termtree-0.4.0 \
		unicode-ident-1.0.6 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0 \
		yansi-0.5.1

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
