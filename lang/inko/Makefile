PORTNAME=	inko
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.1
PORTREVISION=	5
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for building concurrent software
WWW=		https://inko-lang.org/ \
		https://github.com/inko-lang/inko

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc # build fails on non-64-bit architectures: Inko requires a 64-bits architecture

LIB_DEPENDS=	libffi.so:devel/libffi \
		libzstd.so:archivers/zstd

USES=		cargo llvm:17,lib localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	inko-lang

MAKE_ENV=	LLVM_SYS_170_PREFIX=${LLVM_PREFIX} \
		INKO_RT=${PREFIX}/lib/inko/runtime \
		INKO_STD=${PREFIX}/lib/inko

CARGO_CRATES=	addr2line-0.24.2 \
		adler2-2.0.0 \
		anyhow-1.0.93 \
		arrayref-0.3.9 \
		arrayvec-0.7.6 \
		autocfg-1.4.0 \
		backtrace-0.3.74 \
		base64-0.22.1 \
		bitflags-2.6.0 \
		blake3-1.5.4 \
		bstr-1.11.0 \
		byteorder-1.5.0 \
		cc-1.2.1 \
		cfg-if-1.0.0 \
		console-0.15.8 \
		constant_time_eq-0.3.1 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.7 \
		crc32fast-1.4.2 \
		crossbeam-queue-0.3.11 \
		crossbeam-utils-0.8.20 \
		displaydoc-0.2.5 \
		either-1.13.0 \
		encode_unicode-0.3.6 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		filetime-0.2.25 \
		flate2-1.0.35 \
		fnv-1.0.7 \
		form_urlencoded-1.2.1 \
		getopts-0.2.21 \
		getrandom-0.2.15 \
		gimli-0.31.1 \
		hashbrown-0.15.2 \
		icu_collections-1.5.0 \
		icu_locid-1.5.0 \
		icu_locid_transform-1.5.0 \
		icu_locid_transform_data-1.5.0 \
		icu_normalizer-1.5.0 \
		icu_normalizer_data-1.5.0 \
		icu_properties-1.5.1 \
		icu_properties_data-1.5.0 \
		icu_provider-1.5.0 \
		icu_provider_macros-1.5.0 \
		idna-1.0.3 \
		idna_adapter-1.2.0 \
		indexmap-2.6.0 \
		inkwell-0.5.0 \
		inkwell_internals-0.10.0 \
		lazy_static-1.5.0 \
		libc-0.2.166 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.14 \
		litemap-0.7.4 \
		llvm-sys-170.2.0 \
		log-0.4.22 \
		memchr-2.7.4 \
		miniz_oxide-0.8.0 \
		num-bigint-0.4.6 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		object-0.36.5 \
		once_cell-1.20.2 \
		openssl-probe-0.1.5 \
		percent-encoding-2.3.1 \
		ppv-lite86-0.2.20 \
		proc-macro2-1.0.92 \
		quote-1.0.37 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.5.7 \
		regex-automata-0.4.9 \
		regex-lite-0.1.6 \
		ring-0.17.8 \
		rustc-demangle-0.1.24 \
		rustix-0.38.41 \
		rustls-0.23.18 \
		rustls-native-certs-0.7.3 \
		rustls-pemfile-2.2.0 \
		rustls-pki-types-1.10.0 \
		rustls-webpki-0.102.8 \
		schannel-0.1.27 \
		security-framework-2.11.1 \
		security-framework-sys-2.12.1 \
		semver-1.0.23 \
		serde-1.0.215 \
		serde_derive-1.0.215 \
		shlex-1.3.0 \
		similar-2.6.0 \
		similar-asserts-1.6.0 \
		smallvec-1.13.2 \
		spin-0.9.8 \
		stable_deref_trait-1.2.0 \
		subtle-2.6.1 \
		syn-2.0.89 \
		synstructure-0.13.1 \
		tar-0.4.43 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		tinystr-0.7.6 \
		unicode-ident-1.0.14 \
		unicode-segmentation-1.12.0 \
		unicode-width-0.1.14 \
		unicode-width-0.2.0 \
		untrusted-0.9.0 \
		ureq-2.10.1 \
		url-2.5.4 \
		utf16_iter-1.0.5 \
		utf8_iter-1.0.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		webpki-roots-0.26.7 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		write16-1.0.0 \
		writeable-0.5.5 \
		yoke-0.7.5 \
		yoke-derive-0.7.5 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35 \
		zerofrom-0.1.5 \
		zerofrom-derive-0.1.5 \
		zeroize-1.8.1 \
		zerovec-0.10.4 \
		zerovec-derive-0.10.3

do-install:
	# executable
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/inko ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# runtime library
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/inko/runtime
	${INSTALL_DATA} ${WRKDIR}/target/release/libinko.a ${STAGEDIR}${PREFIX}/lib/inko/runtime
	# standard library
	cd ${WRKSRC}/std/src && ${COPYTREE_SHARE} std ${STAGEDIR}${PREFIX}/lib/inko

# tests as of 0.18.1: test result: ok. 206 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.03s

.include <bsd.port.mk>
