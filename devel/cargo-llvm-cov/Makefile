PORTNAME=	cargo-llvm-cov
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.18
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

CARGO_CRATES=	aho-corasick-1.1.3 \
		anyhow-1.0.98 \
		autocfg-1.5.0 \
		bitflags-2.9.1 \
		bstr-1.12.0 \
		camino-1.1.10 \
		cargo-config2-0.1.35 \
		cfg-if-1.0.1 \
		duct-1.0.0 \
		errno-0.3.13 \
		fastrand-2.3.0 \
		filetime-0.2.25 \
		fs-err-3.1.1 \
		glob-0.3.2 \
		itoa-1.0.15 \
		lcov2cobertura-1.0.6 \
		lexopt-0.3.1 \
		libc-0.2.174 \
		libredox-0.1.6 \
		linux-raw-sys-0.9.4 \
		memchr-2.7.5 \
		normpath-1.3.0 \
		once_cell-1.21.3 \
		opener-0.8.2 \
		os_pipe-1.2.2 \
		proc-macro2-1.0.95 \
		quick-xml-0.37.5 \
		quote-1.0.40 \
		redox_syscall-0.5.14 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rustc-demangle-0.1.25 \
		rustix-1.0.8 \
		rustversion-1.0.21 \
		ruzstd-0.8.1 \
		ryu-1.0.20 \
		same-file-1.0.6 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_json-1.0.141 \
		serde_spanned-1.0.0 \
		shared_child-1.1.1 \
		shared_thread-0.1.0 \
		shell-escape-0.1.5 \
		sigchld-0.2.4 \
		signal-hook-0.3.18 \
		signal-hook-registry-1.4.5 \
		syn-2.0.104 \
		tar-0.4.44 \
		tempfile-3.20.0 \
		termcolor-1.4.1 \
		toml-0.9.2 \
		toml_datetime-0.7.0 \
		toml_parser-1.0.1 \
		unicode-ident-1.0.18 \
		walkdir-2.5.0 \
		winapi-util-0.1.9 \
		windows-sys-0.59.0 \
		windows-sys-0.60.2 \
		windows-targets-0.52.6 \
		windows-targets-0.53.2 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_gnullvm-0.53.0 \
		windows_aarch64_msvc-0.52.6 \
		windows_aarch64_msvc-0.53.0 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnu-0.53.0 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_gnullvm-0.53.0 \
		windows_i686_msvc-0.52.6 \
		windows_i686_msvc-0.53.0 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnu-0.53.0 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_gnullvm-0.53.0 \
		windows_x86_64_msvc-0.52.6 \
		windows_x86_64_msvc-0.53.0 \
		winnow-0.7.12 \
		xattr-1.5.1 \
		test-helper@git+https://github.com/taiki-e/test-helper.git?rev=f38a7f5\#f38a7f5895cb5f562195c6116cffc139d712acf5

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
