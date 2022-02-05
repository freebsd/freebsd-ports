PORTNAME=	lewton
DISTVERSION=	0.10.2
PORTREVISION=	5
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	05f96f6e6976.patch:-p1 # https://github.com/RustAudio/lewton/pull/97

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Rust vorbis decoder

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c

USES=		cargo
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	RustAudio
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

CARGO_CRATES=	al-sys-0.6.1 \
		alto-3.0.4 \
		autocfg-1.0.0 \
		byteorder-1.3.2 \
		bytes-0.4.12 \
		cc-1.0.50 \
		cfg-if-0.1.10 \
		cmake-0.1.42 \
		curl-0.4.25 \
		curl-sys-0.4.25 \
		fuchsia-cprng-0.1.1 \
		futures-0.1.29 \
		gcc-0.3.55 \
		iovec-0.1.4 \
		lazy_static-0.2.11 \
		lazy_static-1.4.0 \
		libc-0.2.66 \
		libloading-0.5.2 \
		libz-sys-1.0.25 \
		log-0.4.8 \
		maybe-uninit-2.0.0 \
		ogg-0.8.0 \
		ogg-sys-0.0.9 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.54 \
		owning_ref-0.3.3 \
		parking_lot-0.4.8 \
		parking_lot_core-0.2.14 \
		pkg-config-0.3.17 \
		proc-macro2-1.0.8 \
		quote-1.0.2 \
		rand-0.3.23 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		rental-0.5.5 \
		rental-impl-0.5.5 \
		rustc-serialize-0.3.24 \
		schannel-0.1.16 \
		sha2-0.1.2 \
		smallvec-0.6.13 \
		socket2-0.3.11 \
		stable_deref_trait-1.1.1 \
		syn-1.0.14 \
		test-assets-0.2.0 \
		tinyvec-1.0.1 \
		tinyvec_macros-0.1.0 \
		tokio-io-0.1.12 \
		unicode-xid-0.2.0 \
		vcpkg-0.2.8 \
		vorbis-0.1.0 \
		vorbis-encoder-0.1.4 \
		vorbis-sys-0.0.8 \
		vorbisfile-sys-0.0.8 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

do-build:
	@${CARGO_CARGO_RUN} cbuild \
		--verbose \
		--verbose \
		${CARGO_BUILD_ARGS}

do-install:
	@${CARGO_CARGO_RUN} cinstall \
		--verbose \
		--verbose \
		--destdir "${STAGEDIR}" \
		--prefix "${PREFIX}" \
		${CARGO_INSTALL_ARGS}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
