PORTNAME=	cargo-llvm-cov
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
PORTREVISION=	0
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
		bstr-1.14.0 \
		build-context-0.1.4 \
		camino-1.2.6 \
		cargo-config2-0.1.45 \
		cfg-if-1.0.5 \
		duct-1.1.2 \
		errno-0.3.15 \
		fastrand-2.5.0 \
		filetime-0.2.30 \
		fs-err-3.3.2 \
		glob-0.3.4 \
		itoa-1.0.19 \
		lcov2cobertura-1.0.10 \
		lexopt-0.3.2 \
		libc-0.2.191 \
		linux-raw-sys-0.12.1 \
		memchr-2.8.3 \
		normpath-1.5.2 \
		once_cell-1.21.4 \
		opener-0.8.5 \
		os_pipe-1.2.3 \
		proc-macro2-1.0.107 \
		quick-xml-0.42.0 \
		quote-1.0.47 \
		regex-1.13.2 \
		regex-automata-0.4.19 \
		regex-syntax-0.8.12 \
		rustc-demangle-0.1.28 \
		rustix-1.1.6 \
		rustversion-1.0.23 \
		ruzstd-0.9.1 \
		same-file-1.0.6 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		serde_json-1.0.154 \
		serde_spanned-1.1.3 \
		shared_child-1.1.2 \
		shared_thread-0.2.1 \
		shell-escape-0.1.5 \
		syn-3.0.10 \
		tar-0.4.46 \
		tempfile-3.27.0 \
		termcolor-1.4.1 \
		toml-1.2.1+spec-1.1.0 \
		toml_datetime-1.1.3+spec-1.1.0 \
		toml_parser-1.1.5+spec-1.1.0 \
		unicode-ident-1.0.27 \
		walkdir-2.5.0 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		winnow-1.0.5 \
		xattr-1.7.0 \
		zmij-1.0.23 \
		test-helper@git+https://github.com/taiki-e/test-helper.git?rev=b931ac1a34794aede5b019c613e50157a35a7ec4\#b931ac1a34794aede5b019c613e50157a35a7ec4

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
