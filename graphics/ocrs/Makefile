PORTNAME=	ocrs
DISTVERSIONPREFIX=	ocrs-cli-v
DISTVERSION=	0.10.3
PORTREVISION=	2
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

CARGO_CRATES=	adler2-2.0.0 \
		anyhow-1.0.98 \
		autocfg-1.1.0 \
		base64-0.22.1 \
		bitflags-1.3.2 \
		bumpalo-3.14.0 \
		bytemuck-1.14.0 \
		byteorder-lite-0.1.0 \
		bytes-1.10.0 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		crc32fast-1.3.2 \
		crossbeam-deque-0.8.4 \
		crossbeam-epoch-0.9.17 \
		crossbeam-utils-0.8.18 \
		either-1.9.0 \
		fastrand-2.3.0 \
		fdeflate-0.3.3 \
		flatbuffers-24.3.25 \
		flate2-1.0.35 \
		fnv-1.0.7 \
		form_urlencoded-1.2.1 \
		getrandom-0.2.11 \
		hermit-abi-0.3.9 \
		home-0.5.11 \
		http-1.2.0 \
		httparse-1.10.0 \
		idna-1.0.3 \
		idna_adapter-1.0.0 \
		image-0.25.5 \
		image-webp-0.2.0 \
		itoa-1.0.10 \
		lexopt-0.3.0 \
		libc-0.2.151 \
		log-0.4.25 \
		memchr-2.7.4 \
		miniz_oxide-0.8.0 \
		num-traits-0.2.17 \
		num_cpus-1.16.0 \
		once_cell-1.19.0 \
		percent-encoding-2.3.1 \
		png-0.17.16 \
		proc-macro2-1.0.89 \
		quick-error-2.0.1 \
		quote-1.0.35 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		ring-0.17.7 \
		rten-0.18.0 \
		rten-imageproc-0.18.0 \
		rten-simd-0.18.0 \
		rten-tensor-0.18.0 \
		rten-vecmath-0.18.0 \
		rustc-hash-2.0.0 \
		rustc_version-0.4.0 \
		rustls-0.23.22 \
		rustls-pemfile-2.2.0 \
		rustls-pki-types-1.11.0 \
		rustls-webpki-0.102.8 \
		rustversion-1.0.19 \
		ryu-1.0.16 \
		semver-1.0.20 \
		serde-1.0.194 \
		serde_derive-1.0.194 \
		serde_json-1.0.140 \
		simd-adler32-0.3.7 \
		smallvec-1.13.2 \
		spin-0.9.8 \
		subtle-2.5.0 \
		syn-2.0.87 \
		thiserror-2.0.12 \
		thiserror-impl-2.0.12 \
		unicode-ident-1.0.12 \
		untrusted-0.9.0 \
		ureq-3.0.5 \
		ureq-proto-0.3.0 \
		url-2.5.4 \
		utf-8-0.7.6 \
		utf8_iter-1.0.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		webpki-roots-0.26.8 \
		windows-sys-0.48.0 \
		windows-sys-0.59.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.6 \
		zeroize-1.7.0 \
		zune-core-0.4.12 \
		zune-jpeg-0.4.13

PLIST_FILES=	bin/${PORTNAME}

do-install:
	# binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
