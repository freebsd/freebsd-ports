PORTNAME=	inko
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1
PORTREVISION=	2
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for building concurrent software
WWW=		https://inko-lang.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		cargo llvm:15 localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	inko-lang

MAKE_ENV=	LLVM_SYS_150_PREFIX=${LLVM_PREFIX} \
		INKO_RT=${PREFIX}/lib/inko/runtime \
		INKO_STD=${PREFIX}/lib/inko

CARGO_CRATES=	addr2line-0.19.0 \
		adler-1.0.2 \
		aho-corasick-1.0.1 \
		autocfg-1.1.0 \
		backtrace-0.3.67 \
		bitflags-1.3.2 \
		bitflags-2.3.3 \
		blake2-0.10.6 \
		block-buffer-0.10.4 \
		bstr-0.2.17 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		concurrent-queue-2.2.0 \
		console-0.15.6 \
		crossbeam-queue-0.3.8 \
		crossbeam-utils-0.8.15 \
		crypto-common-0.1.6 \
		digest-0.10.6 \
		either-1.8.1 \
		encode_unicode-0.3.6 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		getopts-0.2.21 \
		getrandom-0.2.9 \
		gimli-0.27.2 \
		inkwell-0.1.1 \
		inkwell_internals-0.7.0 \
		lazy_static-1.4.0 \
		libc-0.2.147 \
		linux-raw-sys-0.4.3 \
		llvm-sys-150.1.2 \
		lock_api-0.4.9 \
		log-0.4.17 \
		memchr-2.5.0 \
		miniz_oxide-0.6.2 \
		object-0.30.3 \
		once_cell-1.17.1 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.7 \
		pin-project-lite-0.2.9 \
		polling-2.8.0 \
		ppv-lite86-0.2.17 \
		proc-macro2-1.0.58 \
		quote-1.0.27 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.2.16 \
		regex-1.8.1 \
		regex-automata-0.1.10 \
		regex-syntax-0.7.1 \
		rustc-demangle-0.1.23 \
		rustix-0.38.1 \
		scopeguard-1.1.0 \
		semver-1.0.17 \
		similar-2.2.1 \
		similar-asserts-1.4.2 \
		smallvec-1.10.0 \
		socket2-0.5.3 \
		subtle-2.4.1 \
		syn-1.0.109 \
		typenum-1.16.0 \
		unicode-ident-1.0.8 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.10 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		windows-sys-0.45.0 \
		windows-sys-0.48.0 \
		windows-targets-0.42.2 \
		windows-targets-0.48.0 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.48.0

do-install:
	# executable
	${INSTALL_PROGRAM} ${WRKDIR}/target/*-freebsd/release/inko ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# runtime library
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/inko/runtime
	${INSTALL_DATA} ${WRKDIR}/target/*-freebsd/release/libinko.a ${STAGEDIR}${PREFIX}/lib/inko/runtime
	# standard library
	cd ${WRKSRC}/std/src && ${COPYTREE_SHARE} std ${STAGEDIR}${PREFIX}/lib/inko

.include <bsd.port.mk>
