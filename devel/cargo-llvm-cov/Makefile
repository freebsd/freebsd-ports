PORTNAME=	cargo-llvm-cov
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust: Cargo subcommand to easily use LLVM source-based code coverage
WWW=		https://github.com/taiki-e/cargo-llvm-cov

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	taiki-e

CARGO_CRATES=	aho-corasick-1.1.5 \
		anyhow-1.0.104 \
		autocfg-1.5.1 \
		bitflags-2.13.2 \
		bstr-1.13.1 \
		build-context-0.1.4 \
		camino-1.2.5 \
		cargo-config2-0.1.45 \
		cfg-if-1.0.4 \
		duct-1.1.2 \
		errno-0.3.14 \
		fastrand-2.5.0 \
		filetime-0.2.29 \
		fs-err-3.3.1 \
		glob-0.3.4 \
		itoa-1.0.18 \
		lcov2cobertura-1.0.9 \
		lexopt-0.3.2 \
		libc-0.2.189 \
		linux-raw-sys-0.12.1 \
		memchr-2.8.3 \
		normpath-1.5.1 \
		once_cell-1.21.4 \
		opener-0.8.5 \
		os_pipe-1.2.3 \
		proc-macro2-1.0.107 \
		quick-xml-0.39.4 \
		quote-1.0.47 \
		regex-1.13.1 \
		regex-automata-0.4.18 \
		regex-syntax-0.8.11 \
		rustc-demangle-0.1.28 \
		rustix-1.1.4 \
		rustversion-1.0.23 \
		ruzstd-0.9.0 \
		same-file-1.0.6 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		serde_json-1.0.151 \
		serde_spanned-1.1.1 \
		shared_child-1.1.2 \
		shared_thread-0.2.1 \
		shell-escape-0.1.5 \
		syn-3.0.5 \
		tar-0.4.46 \
		tempfile-3.27.0 \
		termcolor-1.4.1 \
		toml-1.1.6+spec-1.1.0 \
		toml_datetime-1.1.1+spec-1.1.0 \
		toml_parser-1.1.3+spec-1.1.0 \
		unicode-ident-1.0.24 \
		walkdir-2.5.0 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		winnow-1.0.4 \
		xattr-1.6.1 \
		zmij-1.0.23 \
		test-helper@git+https://github.com/taiki-e/test-helper.git?rev=82e3b012a49fb16587e165986674290ef682a5b0\#82e3b012a49fb16587e165986674290ef682a5b0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
