PORTNAME=	cargo-llvm-cov
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.11
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
		anyhow-1.0.86 \
		autocfg-1.3.0 \
		bitflags-1.3.2 \
		bitflags-2.6.0 \
		bstr-1.9.1 \
		byteorder-1.5.0 \
		camino-1.1.7 \
		cargo-config2-0.1.26 \
		cfg-if-1.0.0 \
		duct-0.13.7 \
		easy-ext-1.0.2 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		fastrand-2.1.0 \
		filetime-0.2.23 \
		fs-err-2.11.0 \
		glob-0.3.1 \
		hashbrown-0.14.5 \
		home-0.5.9 \
		indexmap-2.2.6 \
		is_executable-1.0.1 \
		itoa-1.0.11 \
		lcov2cobertura-1.0.5 \
		lexopt-0.3.0 \
		libc-0.2.155 \
		linux-raw-sys-0.4.14 \
		memchr-2.7.4 \
		normpath-1.2.0 \
		once_cell-1.19.0 \
		opener-0.7.1 \
		os_pipe-1.2.0 \
		proc-macro2-1.0.86 \
		quick-xml-0.31.0 \
		quote-1.0.36 \
		redox_syscall-0.4.1 \
		regex-1.10.5 \
		regex-automata-0.4.7 \
		regex-syntax-0.8.4 \
		rustc-demangle-0.1.24 \
		rustix-0.38.34 \
		rustversion-1.0.17 \
		ruzstd-0.7.0 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		serde-1.0.204 \
		serde_derive-1.0.204 \
		serde_json-1.0.120 \
		serde_spanned-0.6.6 \
		shared_child-1.0.0 \
		shell-escape-0.1.5 \
		syn-2.0.71 \
		tar-0.4.41 \
		tempfile-3.10.1 \
		termcolor-1.4.1 \
		toml_datetime-0.6.6 \
		toml_edit-0.22.16 \
		unicode-ident-1.0.12 \
		walkdir-2.5.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.8 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.6.14 \
		xattr-1.3.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
