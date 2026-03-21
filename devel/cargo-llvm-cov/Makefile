PORTNAME=	cargo-llvm-cov
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.4
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

CARGO_CRATES=	aho-corasick-1.1.4 \
		anyhow-1.0.102 \
		autocfg-1.5.0 \
		bitflags-2.11.0 \
		bstr-1.12.1 \
		build-context-0.1.4 \
		camino-1.2.2 \
		cargo-config2-0.1.43 \
		cfg-if-1.0.4 \
		duct-1.1.1 \
		errno-0.3.14 \
		fastrand-2.3.0 \
		filetime-0.2.27 \
		fs-err-3.3.0 \
		glob-0.3.3 \
		itoa-1.0.17 \
		lcov2cobertura-1.0.9 \
		lexopt-0.3.2 \
		libc-0.2.183 \
		libredox-0.1.14 \
		linux-raw-sys-0.12.1 \
		memchr-2.8.0 \
		normpath-1.5.0 \
		once_cell-1.21.3 \
		opener-0.8.4 \
		os_pipe-1.2.3 \
		plain-0.2.3 \
		proc-macro2-1.0.106 \
		quick-xml-0.39.2 \
		quote-1.0.45 \
		redox_syscall-0.7.3 \
		regex-1.12.3 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.10 \
		rustc-demangle-0.1.27 \
		rustix-1.1.4 \
		rustversion-1.0.22 \
		ruzstd-0.8.2 \
		same-file-1.0.6 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		serde_spanned-1.0.4 \
		shared_child-1.1.1 \
		shared_thread-0.2.0 \
		shell-escape-0.1.5 \
		syn-2.0.117 \
		tar-0.4.44 \
		tempfile-3.27.0 \
		termcolor-1.4.1 \
		toml-1.0.6+spec-1.1.0 \
		toml_datetime-1.0.0+spec-1.1.0 \
		toml_parser-1.0.9+spec-1.1.0 \
		unicode-ident-1.0.24 \
		walkdir-2.5.0 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.60.2 \
		windows-sys-0.61.2 \
		windows-targets-0.53.5 \
		windows_aarch64_gnullvm-0.53.1 \
		windows_aarch64_msvc-0.53.1 \
		windows_i686_gnu-0.53.1 \
		windows_i686_gnullvm-0.53.1 \
		windows_i686_msvc-0.53.1 \
		windows_x86_64_gnu-0.53.1 \
		windows_x86_64_gnullvm-0.53.1 \
		windows_x86_64_msvc-0.53.1 \
		winnow-0.7.15 \
		xattr-1.6.1 \
		zmij-1.0.21 \
		test-helper@git+https://github.com/taiki-e/test-helper.git?rev=f38a7f5\#f38a7f5895cb5f562195c6116cffc139d712acf5

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
