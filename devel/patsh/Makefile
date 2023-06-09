PORTNAME=	patsh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line tool for patching shell scripts inspired by resholve
WWW=		https://github.com/nix-community/patsh

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	nix-community

CARGO_CRATES=	aho-corasick-0.7.20 \
		anyhow-1.0.66 \
		assert_cmd-2.0.7 \
		bitflags-1.3.2 \
		bstr-1.0.1 \
		cc-1.0.77 \
		cfg-if-1.0.0 \
		clap-4.0.29 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		difflib-0.4.0 \
		dissimilar-1.0.4 \
		doc-comment-0.3.3 \
		either-1.8.0 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		expect-test-1.4.0 \
		fastrand-1.8.0 \
		heck-0.4.0 \
		hermit-abi-0.2.6 \
		instant-0.1.12 \
		io-lifetimes-1.0.3 \
		is-terminal-0.4.1 \
		is_executable-1.0.1 \
		itertools-0.10.5 \
		libc-0.2.138 \
		linux-raw-sys-0.1.3 \
		memchr-2.5.0 \
		once_cell-1.16.0 \
		os_str_bytes-6.4.1 \
		predicates-2.1.4 \
		predicates-core-1.0.5 \
		predicates-tree-1.0.7 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.47 \
		quote-1.0.21 \
		redox_syscall-0.2.16 \
		regex-1.7.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		remove_dir_all-0.5.3 \
		rustix-0.36.4 \
		serde-1.0.148 \
		shell-escape-0.1.5 \
		strsim-0.10.0 \
		syn-1.0.105 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		terminal_size-0.2.3 \
		termtree-0.4.0 \
		tree-sitter-0.20.9 \
		unicase-2.6.0 \
		unicode-ident-1.0.5 \
		unicode-width-0.1.10 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
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
		tree-sitter-bash@git+https://github.com/tree-sitter/tree-sitter-bash\#4488aa41406547e478636a4fcfd24f5bbc3f2f74

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
