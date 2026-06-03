PORTNAME=	inko
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
PORTREVISION=	1
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for building concurrent software
WWW=		https://inko-lang.org/ \
		https://github.com/inko-lang/inko

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc # build fails on non-64-bit architectures: Inko requires a 64-bits architecture

LIB_DEPENDS=	libffi.so:devel/libffi \
		libzstd.so:archivers/zstd

USES=		cargo llvm:18,lib localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	inko-lang

MAKE_ENV=	LLVM_SYS_181_PREFIX=${LLVM_PREFIX} \
		INKO_RT=${PREFIX}/lib/inko/runtime \
		INKO_STD=${PREFIX}/lib/inko

CARGO_CRATES=	addr2line-0.25.1 \
		adler2-2.0.1 \
		anyhow-1.0.102 \
		arrayref-0.3.9 \
		arrayvec-0.7.6 \
		atomic-wait-1.1.0 \
		backtrace-0.3.76 \
		base64-0.22.1 \
		bitflags-2.11.1 \
		blake3-1.8.4 \
		bstr-1.12.1 \
		bytes-1.11.1 \
		cc-1.2.60 \
		cesu8-1.1.0 \
		cfg-if-1.0.4 \
		combine-4.6.7 \
		console-0.15.11 \
		constant_time_eq-0.4.2 \
		core-foundation-0.10.1 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.3.0 \
		crc32fast-1.5.0 \
		encode_unicode-1.0.0 \
		equivalent-1.0.2 \
		filetime-0.2.27 \
		find-msvc-tools-0.1.9 \
		flate2-1.1.9 \
		fnv-1.0.7 \
		getopts-0.2.24 \
		getrandom-0.2.17 \
		getrandom-0.3.4 \
		gimli-0.32.3 \
		graviola-0.2.1 \
		hashbrown-0.17.0 \
		http-1.4.0 \
		httparse-1.10.1 \
		indexmap-2.14.0 \
		inkwell-0.8.0 \
		inkwell_internals-0.13.0 \
		itoa-1.0.18 \
		jni-0.21.1 \
		jni-sys-0.3.1 \
		jni-sys-0.4.1 \
		jni-sys-macros-0.4.1 \
		lazy_static-1.5.0 \
		libc-0.2.185 \
		libredox-0.1.16 \
		libz-rs-sys-0.5.5 \
		llvm-sys-181.3.0 \
		log-0.4.29 \
		memchr-2.8.0 \
		miniz_oxide-0.8.9 \
		object-0.37.3 \
		once_cell-1.21.4 \
		openssl-probe-0.2.1 \
		percent-encoding-2.3.2 \
		plain-0.2.3 \
		proc-macro2-1.0.106 \
		quote-1.0.45 \
		r-efi-5.3.0 \
		redox_syscall-0.7.4 \
		regex-automata-0.4.14 \
		regex-lite-0.1.9 \
		ring-0.17.14 \
		rustc-demangle-0.1.27 \
		rustls-0.23.38 \
		rustls-graviola-0.2.1 \
		rustls-native-certs-0.8.3 \
		rustls-pki-types-1.14.0 \
		rustls-platform-verifier-0.6.2 \
		rustls-platform-verifier-android-0.1.1 \
		rustls-webpki-0.103.12 \
		same-file-1.0.6 \
		schannel-0.1.29 \
		security-framework-3.7.0 \
		security-framework-sys-2.17.0 \
		semver-1.0.28 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		shlex-1.3.0 \
		simd-adler32-0.3.9 \
		similar-2.7.0 \
		similar-asserts-1.7.0 \
		subtle-2.6.1 \
		syn-2.0.117 \
		tar-0.4.45 \
		thiserror-1.0.69 \
		thiserror-2.0.18 \
		thiserror-impl-1.0.69 \
		thiserror-impl-2.0.18 \
		unicode-ident-1.0.24 \
		unicode-segmentation-1.13.2 \
		unicode-width-0.2.2 \
		untrusted-0.9.0 \
		ureq-3.3.0 \
		ureq-proto-0.6.0 \
		utf8-zero-0.8.1 \
		walkdir-2.5.0 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasip2-1.0.2+wasi-0.2.9 \
		webpki-root-certs-1.0.6 \
		winapi-util-0.1.11 \
		windows-link-0.2.1 \
		windows-sys-0.42.0 \
		windows-sys-0.45.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-sys-0.61.2 \
		windows-targets-0.42.2 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.52.6 \
		wit-bindgen-0.51.0 \
		zeroize-1.8.2 \
		zlib-rs-0.5.5

do-install:
	# executable
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/inko ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# runtime library
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/inko/runtime
	${INSTALL_DATA} ${WRKDIR}/target/release/libinko.a ${STAGEDIR}${PREFIX}/lib/inko/runtime
	# standard library
	cd ${WRKSRC}/std/src && ${COPYTREE_SHARE} std ${STAGEDIR}${PREFIX}/lib/inko

# tests as of 0.20.0: 211 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.01s

.include <bsd.port.mk>
