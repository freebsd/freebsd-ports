# $FreeBSD$

PORTNAME=	cargo-c
DISTVERSION=	0.6.5
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Cargo C-ABI helpers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libcurl.so:ftp/curl \
		libssh2.so:security/libssh2

USES=		cargo ssl
PLIST_FILES=	bin/cargo-cbuild \
		bin/cargo-cinstall

CARGO_CRATES=	adler32-1.0.4 \
		aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		anyhow-1.0.28 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bitflags-1.2.1 \
		bitmaps-2.1.0 \
		bstr-0.2.12 \
		bytesize-1.0.0 \
		cargo-0.44.0 \
		cargo-platform-0.1.1 \
		cbindgen-0.14.2 \
		cc-1.0.52 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		commoncrypto-0.2.0 \
		commoncrypto-sys-0.2.0 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		crates-io-0.32.0 \
		crc32fast-1.2.0 \
		crossbeam-channel-0.4.2 \
		crossbeam-utils-0.7.2 \
		crypto-hash-0.3.4 \
		curl-0.4.29 \
		curl-sys-0.4.31+curl-7.70.0 \
		env_logger-0.7.1 \
		filetime-0.2.9 \
		flate2-1.0.14 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fs2-0.4.3 \
		fwdansi-1.1.0 \
		getrandom-0.1.14 \
		git2-0.13.5 \
		git2-curl-0.14.0 \
		glob-0.3.0 \
		globset-0.4.5 \
		heck-0.3.1 \
		hermit-abi-0.1.12 \
		hex-0.3.2 \
		hex-0.4.2 \
		home-0.5.3 \
		humantime-1.3.0 \
		humantime-2.0.0 \
		idna-0.2.0 \
		ignore-0.4.14 \
		im-rc-14.3.0 \
		itoa-0.4.5 \
		jobserver-0.1.21 \
		lazy_static-1.4.0 \
		lazycell-1.2.1 \
		libc-0.2.69 \
		libgit2-sys-0.12.5+1.0.0 \
		libnghttp2-sys-0.1.3 \
		libssh2-sys-0.2.17 \
		libz-sys-1.0.25 \
		log-0.4.8 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		miniz_oxide-0.3.6 \
		miow-0.3.3 \
		num_cpus-1.13.0 \
		opener-0.4.1 \
		openssl-0.10.29 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.55 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.17 \
		ppv-lite86-0.2.6 \
		proc-macro-error-1.0.2 \
		proc-macro-error-attr-1.0.2 \
		proc-macro2-1.0.12 \
		quick-error-1.2.3 \
		quote-1.0.4 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_xoshiro-0.4.0 \
		redox_syscall-0.1.56 \
		regex-1.3.7 \
		regex-syntax-0.6.17 \
		remove_dir_all-0.5.2 \
		rustc-workspace-hack-1.0.0 \
		rustfix-0.5.1 \
		ryu-1.0.4 \
		same-file-1.0.6 \
		schannel-0.1.18 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.106 \
		serde_derive-1.0.106 \
		serde_ignored-0.1.1 \
		serde_json-1.0.52 \
		shell-escape-0.1.4 \
		sized-chunks-0.5.3 \
		smallvec-1.4.0 \
		socket2-0.3.12 \
		strip-ansi-escapes-0.1.0 \
		strsim-0.8.0 \
		structopt-0.3.14 \
		structopt-derive-0.4.7 \
		syn-1.0.18 \
		syn-mid-0.5.0 \
		tar-0.4.26 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		toml-0.5.6 \
		typenum-1.12.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.12 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		url-2.1.1 \
		utf8parse-0.1.1 \
		vcpkg-0.2.8 \
		vec_map-0.8.1 \
		version_check-0.9.1 \
		vte-0.3.3 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

post-patch:
	@${REINPLACE_CMD} -e 's,libdir.join("pkgconfig,prefix.join("libdata/pkgconfig,' \
		${WRKSRC}/src/install_paths.rs

.include <bsd.port.mk>
