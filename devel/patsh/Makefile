PORTNAME=	patsh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	18
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line tool for patching shell scripts inspired by resholve
WWW=		https://github.com/nix-community/patsh

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	nix-community

CARGO_CRATES=	aho-corasick-1.0.4 \
		anstream-0.3.2 \
		anstyle-1.0.1 \
		anstyle-parse-0.2.1 \
		anstyle-query-1.0.0 \
		anstyle-wincon-1.0.2 \
		anyhow-1.0.75 \
		assert_cmd-2.0.12 \
		bitflags-1.3.2 \
		bitflags-2.4.0 \
		bstr-1.6.0 \
		cc-1.0.82 \
		cfg-if-1.0.0 \
		clap-4.3.22 \
		clap_builder-4.3.22 \
		clap_derive-4.3.12 \
		clap_lex-0.5.0 \
		colorchoice-1.0.0 \
		difflib-0.4.0 \
		dissimilar-1.0.7 \
		doc-comment-0.3.3 \
		either-1.9.0 \
		errno-0.3.2 \
		errno-dragonfly-0.1.2 \
		expect-test-1.4.1 \
		fastrand-2.0.0 \
		heck-0.4.1 \
		hermit-abi-0.3.2 \
		io-lifetimes-1.0.11 \
		is-terminal-0.4.9 \
		is_executable-1.0.1 \
		itertools-0.10.5 \
		libc-0.2.147 \
		linux-raw-sys-0.3.8 \
		linux-raw-sys-0.4.5 \
		memchr-2.5.0 \
		once_cell-1.18.0 \
		predicates-3.0.3 \
		predicates-core-1.0.6 \
		predicates-tree-1.0.9 \
		proc-macro2-1.0.66 \
		quote-1.0.33 \
		redox_syscall-0.3.5 \
		regex-1.9.3 \
		regex-automata-0.3.6 \
		regex-syntax-0.7.4 \
		rustix-0.37.23 \
		rustix-0.38.8 \
		serde-1.0.183 \
		shell-escape-0.1.5 \
		strsim-0.10.0 \
		syn-2.0.29 \
		tempfile-3.7.1 \
		terminal_size-0.2.6 \
		termtree-0.4.1 \
		tree-sitter-0.20.10 \
		tree-sitter-bash-0.20.0 \
		unicase-2.6.0 \
		unicode-ident-1.0.11 \
		unicode-width-0.1.10 \
		utf8parse-0.2.1 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.4 \
		windows_aarch64_gnullvm-0.48.4 \
		windows_aarch64_msvc-0.48.4 \
		windows_i686_gnu-0.48.4 \
		windows_i686_msvc-0.48.4 \
		windows_x86_64_gnu-0.48.4 \
		windows_x86_64_gnullvm-0.48.4 \
		windows_x86_64_msvc-0.48.4

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
