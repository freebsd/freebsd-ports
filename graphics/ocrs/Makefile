PORTNAME=	ocrs
DISTVERSIONPREFIX=	ocrs-cli-v
DISTVERSION=	0.8.1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust CLI tool for OCR
WWW=		https://github.com/robertknight/ocrs

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT.txt

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	robertknight

CARGO_CRATES=	adler-1.0.2 \
		anyhow-1.0.86 \
		autocfg-1.1.0 \
		base64-0.22.1 \
		bitflags-1.3.2 \
		bumpalo-3.14.0 \
		bytemuck-1.14.0 \
		byteorder-1.5.0 \
		byteorder-lite-0.1.0 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		crc32fast-1.3.2 \
		crossbeam-deque-0.8.4 \
		crossbeam-epoch-0.9.17 \
		crossbeam-utils-0.8.18 \
		either-1.9.0 \
		fastrand-2.1.0 \
		fdeflate-0.3.3 \
		flatbuffers-24.3.25 \
		flate2-1.0.28 \
		form_urlencoded-1.2.1 \
		getrandom-0.2.11 \
		hermit-abi-0.3.9 \
		home-0.5.9 \
		idna-0.5.0 \
		image-0.25.1 \
		image-webp-0.1.2 \
		itoa-1.0.10 \
		lexopt-0.3.0 \
		libc-0.2.151 \
		libm-0.2.8 \
		log-0.4.20 \
		memchr-2.7.4 \
		miniz_oxide-0.7.1 \
		num-traits-0.2.17 \
		num_cpus-1.16.0 \
		once_cell-1.19.0 \
		percent-encoding-2.3.1 \
		png-0.17.13 \
		proc-macro2-1.0.74 \
		quote-1.0.35 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		ring-0.17.7 \
		rten-0.13.1 \
		rten-imageproc-0.13.1 \
		rten-simd-0.11.0 \
		rten-tensor-0.13.1 \
		rten-vecmath-0.11.0 \
		rustc-hash-2.0.0 \
		rustc_version-0.4.0 \
		rustls-0.22.4 \
		rustls-pki-types-1.5.0 \
		rustls-webpki-0.102.3 \
		ryu-1.0.16 \
		semver-1.0.20 \
		serde-1.0.194 \
		serde_derive-1.0.194 \
		serde_json-1.0.122 \
		simd-adler32-0.3.7 \
		smallvec-1.11.2 \
		spin-0.9.8 \
		subtle-2.5.0 \
		syn-2.0.46 \
		thiserror-1.0.63 \
		thiserror-impl-1.0.63 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		unicode-bidi-0.3.14 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.22 \
		untrusted-0.9.0 \
		ureq-2.9.7 \
		url-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.93 \
		wasm-bindgen-backend-0.2.93 \
		wasm-bindgen-macro-0.2.93 \
		wasm-bindgen-macro-support-0.2.93 \
		wasm-bindgen-shared-0.2.93 \
		webpki-roots-0.26.1 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.0 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.0 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.0 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.0 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.0 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.0 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.0 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.0 \
		zeroize-1.7.0 \
		zune-core-0.4.12 \
		zune-jpeg-0.4.11

PLIST_FILES=	bin/${PORTNAME}

do-install:
	# binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/*/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
