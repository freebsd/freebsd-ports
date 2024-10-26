PORTNAME=	inko
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for building concurrent software
WWW=		https://inko-lang.org/ \
		https://github.com/inko-lang/inko

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc # build fails on non-64-bit architectures: Inko requires a 64-bits architecture

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		cargo llvm:17,lib localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	inko-lang

MAKE_ENV=	LLVM_SYS_170_PREFIX=${LLVM_PREFIX} \
		INKO_RT=${PREFIX}/lib/inko/runtime \
		INKO_STD=${PREFIX}/lib/inko

CARGO_CRATES=	addr2line-0.22.0 \
		adler-1.0.2 \
		anyhow-1.0.86 \
		arrayref-0.3.7 \
		arrayvec-0.7.4 \
		autocfg-1.3.0 \
		backtrace-0.3.73 \
		base64-0.22.1 \
		bitflags-1.3.2 \
		bitflags-2.6.0 \
		blake3-1.5.1 \
		bstr-0.2.17 \
		cc-1.1.0 \
		cfg-if-1.0.0 \
		console-0.15.8 \
		constant_time_eq-0.3.0 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.6 \
		crc32fast-1.4.2 \
		crossbeam-queue-0.3.11 \
		crossbeam-utils-0.8.20 \
		either-1.13.0 \
		encode_unicode-0.3.6 \
		errno-0.3.9 \
		filetime-0.2.23 \
		flate2-1.0.30 \
		fnv-1.0.7 \
		form_urlencoded-1.2.1 \
		getopts-0.2.21 \
		getrandom-0.2.15 \
		gimli-0.29.0 \
		idna-0.5.0 \
		inkwell-0.4.0 \
		inkwell_internals-0.9.0 \
		lazy_static-1.5.0 \
		libc-0.2.155 \
		linux-raw-sys-0.4.14 \
		llvm-sys-170.1.1 \
		log-0.4.22 \
		memchr-2.7.4 \
		miniz_oxide-0.7.4 \
		num-bigint-0.4.6 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		object-0.36.1 \
		once_cell-1.19.0 \
		openssl-probe-0.1.5 \
		percent-encoding-2.3.1 \
		ppv-lite86-0.2.17 \
		proc-macro2-1.0.86 \
		quote-1.0.36 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.4.1 \
		regex-automata-0.1.10 \
		regex-lite-0.1.6 \
		ring-0.17.8 \
		rustc-demangle-0.1.24 \
		rustix-0.38.34 \
		rustls-0.23.11 \
		rustls-native-certs-0.7.1 \
		rustls-pemfile-2.1.2 \
		rustls-pki-types-1.7.0 \
		rustls-webpki-0.102.5 \
		schannel-0.1.23 \
		security-framework-2.11.0 \
		security-framework-sys-2.11.0 \
		semver-1.0.23 \
		similar-2.5.0 \
		similar-asserts-1.5.0 \
		socket2-0.5.7 \
		spin-0.9.8 \
		subtle-2.6.1 \
		syn-2.0.70 \
		tar-0.4.41 \
		thiserror-1.0.61 \
		thiserror-impl-1.0.61 \
		tinyvec-1.8.0 \
		tinyvec_macros-0.1.1 \
		unicode-bidi-0.3.15 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.23 \
		unicode-segmentation-1.11.0 \
		unicode-width-0.1.13 \
		untrusted-0.9.0 \
		ureq-2.10.0 \
		url-2.5.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		webpki-roots-0.26.3 \
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
		zeroize-1.8.1

do-install:
	# executable
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/inko ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# runtime library
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/inko/runtime
	${INSTALL_DATA} ${WRKDIR}/target/release/libinko.a ${STAGEDIR}${PREFIX}/lib/inko/runtime
	# standard library
	cd ${WRKSRC}/std/src && ${COPYTREE_SHARE} std ${STAGEDIR}${PREFIX}/lib/inko

.include <bsd.port.mk>
