PORTNAME=	inko
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
PORTREVISION=	4
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for building concurrent software
WWW=		https://inko-lang.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc # build fails on non-64-bit architectures: Inko requires a 64-bits architecture

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		cargo llvm:15 localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	inko-lang

MAKE_ENV=	LLVM_SYS_150_PREFIX=${LLVM_PREFIX} \
		INKO_RT=${PREFIX}/lib/inko/runtime \
		INKO_STD=${PREFIX}/lib/inko

CARGO_CRATES=	addr2line-0.21.0 \
		adler-1.0.2 \
		aho-corasick-1.1.2 \
		arrayref-0.3.7 \
		arrayvec-0.7.4 \
		autocfg-1.1.0 \
		backtrace-0.3.69 \
		base64-0.21.7 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		blake3-1.5.0 \
		bstr-0.2.17 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		concurrent-queue-2.4.0 \
		console-0.15.8 \
		constant_time_eq-0.3.0 \
		crc32fast-1.3.2 \
		crossbeam-queue-0.3.11 \
		crossbeam-utils-0.8.19 \
		either-1.9.0 \
		encode_unicode-0.3.6 \
		errno-0.3.8 \
		filetime-0.2.23 \
		flate2-1.0.28 \
		fnv-1.0.7 \
		form_urlencoded-1.2.1 \
		getopts-0.2.21 \
		getrandom-0.2.12 \
		gimli-0.28.1 \
		idna-0.5.0 \
		lazy_static-1.4.0 \
		libc-0.2.152 \
		linux-raw-sys-0.4.12 \
		llvm-sys-150.1.3 \
		log-0.4.20 \
		memchr-2.7.1 \
		miniz_oxide-0.7.1 \
		object-0.32.2 \
		once_cell-1.19.0 \
		percent-encoding-2.3.1 \
		pin-project-lite-0.2.13 \
		polling-2.8.0 \
		ppv-lite86-0.2.17 \
		proc-macro2-1.0.76 \
		quote-1.0.35 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.4.1 \
		regex-1.10.2 \
		regex-automata-0.1.10 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		ring-0.17.7 \
		rustc-demangle-0.1.23 \
		rustix-0.38.28 \
		rustls-0.21.10 \
		rustls-webpki-0.101.7 \
		sct-0.7.1 \
		semver-1.0.21 \
		similar-2.4.0 \
		similar-asserts-1.5.0 \
		socket2-0.5.5 \
		spin-0.9.8 \
		syn-2.0.48 \
		tar-0.4.40 \
		thiserror-1.0.56 \
		thiserror-impl-1.0.56 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		unicode-bidi-0.3.14 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.22 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.11 \
		untrusted-0.9.0 \
		ureq-2.9.1 \
		url-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		webpki-roots-0.25.3 \
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
		inkwell,inkwell_internals@git+https://github.com/TheDan64/inkwell.git?rev=c18e3e8\#c18e3e8f2bb408c3ec323dd80d08b3a24e7c5152

do-install:
	# executable
	${INSTALL_PROGRAM} ${WRKDIR}/target/*-freebsd/release/inko ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# runtime library
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/inko/runtime
	${INSTALL_DATA} ${WRKDIR}/target/*-freebsd/release/libinko.a ${STAGEDIR}${PREFIX}/lib/inko/runtime
	# standard library
	cd ${WRKSRC}/std/src && ${COPYTREE_SHARE} std ${STAGEDIR}${PREFIX}/lib/inko

.include <bsd.port.mk>
