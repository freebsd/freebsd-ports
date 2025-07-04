PORTNAME=	svgbob
DISTVERSION=	0.7.1
PORTREVISION=	20
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert ASCII diagrams to SVG
WWW=		https://github.com/ivanceras/svgbob

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ivanceras

WRKSRC_SUBDIR=	packages/svgbob_cli

CARGO_CRATES=	ansi_term-0.12.1 \
		approx-0.5.1 \
		arrayvec-0.7.2 \
		async-trait-0.1.68 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		axum-0.4.8 \
		axum-core-0.1.2 \
		bitflags-1.3.2 \
		bumpalo-3.12.0 \
		bytemuck-1.13.1 \
		bytes-1.4.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		doc-comment-0.3.3 \
		downcast-rs-1.2.0 \
		either-1.8.1 \
		fnv-1.0.7 \
		form_urlencoded-1.1.0 \
		futures-channel-0.3.28 \
		futures-core-0.3.28 \
		futures-sink-0.3.28 \
		futures-task-0.3.28 \
		futures-util-0.3.28 \
		getrandom-0.2.9 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		hermit-abi-0.2.6 \
		http-0.2.9 \
		http-body-0.4.5 \
		http-range-header-0.3.0 \
		httparse-1.8.0 \
		httpdate-1.0.2 \
		hyper-0.14.26 \
		indexmap-1.9.3 \
		itertools-0.10.5 \
		itoa-1.0.6 \
		js-sys-0.3.61 \
		json-0.12.4 \
		jss-0.5.1 \
		lazy_static-1.4.0 \
		libc-0.2.141 \
		libm-0.2.6 \
		lock_api-0.4.9 \
		log-0.4.17 \
		matchit-0.4.6 \
		matrixmultiply-0.3.2 \
		memchr-2.5.0 \
		mime-0.3.17 \
		mio-0.8.6 \
		mt-dom-0.22.0 \
		nalgebra-0.30.1 \
		nalgebra-macros-0.1.0 \
		num-complex-0.4.3 \
		num-derive-0.3.3 \
		num-integer-0.1.45 \
		num-rational-0.4.1 \
		num-traits-0.2.15 \
		num_cpus-1.15.0 \
		once_cell-1.17.1 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.7 \
		parry2d-0.8.0 \
		paste-1.0.12 \
		percent-encoding-2.2.0 \
		phf-0.10.1 \
		phf_generator-0.10.0 \
		phf_macros-0.10.0 \
		phf_shared-0.10.0 \
		pin-project-1.0.12 \
		pin-project-internal-1.0.12 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pom-3.2.0 \
		ppv-lite86-0.2.17 \
		proc-macro-hack-0.5.20+deprecated \
		proc-macro2-1.0.56 \
		quote-1.0.26 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rawpointer-0.2.1 \
		redox_syscall-0.2.16 \
		rustc-hash-1.1.0 \
		ryu-1.0.13 \
		safe_arch-0.6.0 \
		sauron-0.52.0 \
		sauron-core-0.52.0 \
		scopeguard-1.1.0 \
		serde-1.0.160 \
		serde_json-1.0.96 \
		serde_urlencoded-0.7.1 \
		signal-hook-registry-1.4.1 \
		simba-0.7.3 \
		siphasher-0.3.10 \
		slab-0.4.8 \
		smallvec-1.10.0 \
		socket2-0.4.9 \
		strsim-0.8.0 \
		syn-1.0.109 \
		syn-2.0.15 \
		sync_wrapper-0.1.2 \
		textwrap-0.11.0 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		tokio-1.27.0 \
		tokio-macros-2.0.0 \
		tokio-util-0.7.7 \
		tower-0.4.13 \
		tower-http-0.2.5 \
		tower-layer-0.3.2 \
		tower-service-0.3.2 \
		tracing-0.1.37 \
		tracing-core-0.1.30 \
		try-lock-0.2.4 \
		typenum-1.16.0 \
		unicode-ident-1.0.8 \
		unicode-width-0.1.10 \
		vec_map-0.8.2 \
		want-0.3.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.84 \
		wasm-bindgen-backend-0.2.84 \
		wasm-bindgen-futures-0.4.34 \
		wasm-bindgen-macro-0.2.84 \
		wasm-bindgen-macro-support-0.2.84 \
		wasm-bindgen-shared-0.2.84 \
		web-sys-0.3.61 \
		wide-0.7.8 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.2 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_msvc-0.42.2 \
		windows_i686_gnu-0.42.2 \
		windows_i686_msvc-0.42.2 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_msvc-0.42.2

PLIST_FILES=	bin/svgbob_cli

.include <bsd.port.mk>
