PORTNAME=	amber
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.9
PORTREVISION=	9
CATEGORIES=	devel
PKGNAMESUFFIX=	-code-search-replace-tool

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code search/replace tool
WWW=		https://github.com/dalance/amber

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	dalance

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base-x-0.2.8 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.11 \
		bumpalo-3.4.0 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		const_fn-0.4.5 \
		constant_time_eq-0.1.5 \
		crossbeam-0.8.0 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.1 \
		crossbeam-queue-0.3.1 \
		crossbeam-utils-0.8.1 \
		ctrlc-3.1.8 \
		dirs-3.0.1 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.5 \
		dirs-sys-next-0.1.2 \
		discard-1.0.4 \
		filetime-0.2.14 \
		getch-0.2.1 \
		getrandom-0.1.16 \
		getrandom-0.2.1 \
		glob-0.3.0 \
		heck-0.3.2 \
		hermit-abi-0.1.17 \
		itoa-0.4.7 \
		lazy_static-1.4.0 \
		libc-0.2.89 \
		log-0.4.13 \
		memchr-2.3.4 \
		memmap-0.7.0 \
		memoffset-0.6.1 \
		nix-0.20.0 \
		num_cpus-1.13.0 \
		ppv-lite86-0.2.10 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.24 \
		quote-1.0.8 \
		rand-0.8.3 \
		rand_chacha-0.3.0 \
		rand_core-0.6.1 \
		rand_hc-0.3.0 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.4 \
		redox_users-0.3.5 \
		redox_users-0.4.0 \
		regex-1.4.5 \
		regex-syntax-0.6.22 \
		remove_dir_all-0.5.3 \
		rlibc-1.0.0 \
		rust-argon2-0.8.3 \
		rustc-serialize-0.3.24 \
		rustc_version-0.2.3 \
		rustversion-1.0.4 \
		ryu-1.0.5 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.125 \
		serde_derive-1.0.125 \
		serde_json-1.0.61 \
		sha1-0.6.0 \
		standback-0.2.15 \
		stdweb-0.4.20 \
		stdweb-derive-0.5.3 \
		stdweb-internal-macros-0.2.9 \
		stdweb-internal-runtime-0.1.5 \
		strsim-0.8.0 \
		structopt-0.3.21 \
		structopt-derive-0.4.14 \
		syn-1.0.60 \
		tempfile-3.2.0 \
		term-0.7.0 \
		termios-0.2.2 \
		termios-0.3.3 \
		textwrap-0.11.0 \
		time-0.2.26 \
		time-macros-0.1.1 \
		time-macros-impl-0.1.1 \
		toml-0.5.8 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.1+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.69 \
		wasm-bindgen-backend-0.2.69 \
		wasm-bindgen-macro-0.2.69 \
		wasm-bindgen-macro-support-0.2.69 \
		wasm-bindgen-shared-0.2.69 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/ambr \
		bin/ambs

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ambr \
		${STAGEDIR}${PREFIX}/bin/ambs

.include <bsd.port.mk>
