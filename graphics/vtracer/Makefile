PORTNAME=	vtracer
DISTVERSION=	0.6.15
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Raster to Vector Graphics Converter
WWW=		https://www.visioncortex.org/vtracer/ \
		https://github.com/visioncortex/vtracer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	visioncortex

CARGO_CRATES=	adler-1.0.2 \
		adler32-1.2.0 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		autocfg-1.5.1 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		bitflags-2.13.1 \
		bumpalo-3.20.3 \
		bytemuck-1.25.2 \
		byteorder-1.5.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.4 \
		clap-2.34.0 \
		color_quant-1.1.0 \
		console_error_panic_hook-0.1.7 \
		console_log-0.2.2 \
		crc32fast-1.5.0 \
		crossbeam-deque-0.8.7 \
		crossbeam-epoch-0.9.20 \
		crossbeam-utils-0.8.22 \
		deflate-0.8.6 \
		either-1.17.0 \
		fastrand-2.5.0 \
		flo_curves-0.3.1 \
		futures-core-0.3.33 \
		futures-task-0.3.33 \
		futures-util-0.3.33 \
		getrandom-0.4.3 \
		gif-0.11.4 \
		hermit-abi-0.1.19 \
		image-0.23.14 \
		indoc-1.0.9 \
		itertools-0.8.2 \
		itoa-1.0.18 \
		jpeg-decoder-0.1.22 \
		js-sys-0.3.103 \
		libc-0.2.189 \
		lock_api-0.4.14 \
		log-0.4.33 \
		memchr-2.8.3 \
		memoffset-0.9.1 \
		miniz_oxide-0.3.7 \
		miniz_oxide-0.4.4 \
		num-integer-0.1.46 \
		num-iter-0.1.46 \
		num-rational-0.3.2 \
		num-traits-0.2.19 \
		once_cell-1.21.4 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		pin-project-lite-0.2.17 \
		png-0.16.8 \
		proc-macro2-1.0.107 \
		pyo3-0.19.2 \
		pyo3-build-config-0.19.2 \
		pyo3-ffi-0.19.2 \
		pyo3-macros-0.19.2 \
		pyo3-macros-backend-0.19.2 \
		quote-1.0.47 \
		r-efi-6.0.0 \
		rayon-1.12.0 \
		rayon-core-1.13.0 \
		redox_syscall-0.5.18 \
		roots-0.0.6 \
		rustversion-1.0.23 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.2.0 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		serde_json-1.0.151 \
		slab-0.4.12 \
		smallvec-1.15.2 \
		strsim-0.8.0 \
		syn-1.0.109 \
		syn-2.0.119 \
		syn-3.0.3 \
		target-lexicon-0.12.16 \
		textwrap-0.11.0 \
		tiff-0.6.1 \
		unicode-ident-1.0.24 \
		unicode-width-0.1.14 \
		unindent-0.1.11 \
		vec_map-0.8.2 \
		visioncortex-0.8.10 \
		wasm-bindgen-0.2.126 \
		wasm-bindgen-macro-0.2.126 \
		wasm-bindgen-macro-support-0.2.126 \
		wasm-bindgen-shared-0.2.126 \
		web-sys-0.3.103 \
		weezl-0.1.12 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-link-0.2.1 \
		zmij-1.0.23

PLIST_FILES=	bin/${PORTNAME}

do-install:
	# binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
