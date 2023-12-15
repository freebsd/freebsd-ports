PORTNAME=	inko
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.2
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

CARGO_CRATES=	addr2line-0.21.0 \
		adler-1.0.2 \
		aho-corasick-1.1.2 \
		autocfg-1.1.0 \
		backtrace-0.3.69 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		blake2-0.10.6 \
		block-buffer-0.10.4 \
		bstr-0.2.17 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		concurrent-queue-2.3.0 \
		console-0.15.7 \
		crossbeam-queue-0.3.8 \
		crossbeam-utils-0.8.16 \
		crypto-common-0.1.6 \
		digest-0.10.7 \
		either-1.9.0 \
		encode_unicode-0.3.6 \
		errno-0.3.7 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		getopts-0.2.21 \
		getrandom-0.2.11 \
		gimli-0.28.0 \
		inkwell-0.1.1 \
		inkwell_internals-0.7.0 \
		lazy_static-1.4.0 \
		libc-0.2.150 \
		linux-raw-sys-0.4.11 \
		llvm-sys-150.1.2 \
		lock_api-0.4.11 \
		log-0.4.20 \
		memchr-2.6.4 \
		miniz_oxide-0.7.1 \
		object-0.32.1 \
		once_cell-1.18.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		pin-project-lite-0.2.13 \
		polling-2.8.0 \
		ppv-lite86-0.2.17 \
		proc-macro2-1.0.69 \
		quote-1.0.33 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.4.1 \
		regex-1.10.2 \
		regex-automata-0.1.10 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		rustc-demangle-0.1.23 \
		rustix-0.38.24 \
		scopeguard-1.2.0 \
		semver-1.0.20 \
		similar-2.3.0 \
		similar-asserts-1.5.0 \
		smallvec-1.11.2 \
		socket2-0.5.5 \
		subtle-2.5.0 \
		syn-1.0.109 \
		typenum-1.17.0 \
		unicode-ident-1.0.12 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.11 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		windows-sys-0.45.0 \
		windows-sys-0.48.0 \
		windows-targets-0.42.2 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.48.5

do-install:
	# executable
	${INSTALL_PROGRAM} ${WRKDIR}/target/*-freebsd/release/inko ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# runtime library
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/inko/runtime
	${INSTALL_DATA} ${WRKDIR}/target/*-freebsd/release/libinko.a ${STAGEDIR}${PREFIX}/lib/inko/runtime
	# standard library
	cd ${WRKSRC}/std/src && ${COPYTREE_SHARE} std ${STAGEDIR}${PREFIX}/lib/inko

.include <bsd.port.mk>
