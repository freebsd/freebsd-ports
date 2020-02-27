# Created by: Christoph Mallon <christoph.mallon@gmx.de>
# $FreeBSD$

PORTNAME=	ja2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.1
PORTREVISION=	13
CATEGORIES=	games

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Port of "Jagged Alliance 2" using SDL

LICENSE=		PD SFI-SCLA
LICENSE_COMB=		multi
LICENSE_NAME_SFI-SCLA=	Strategy First Inc. Source Code License Agreement
LICENSE_FILE_SFI-SCLA=	${WRKSRC}/SFI\ Source\ Code\ license\ agreement.txt
LICENSE_PERMS_SFI-SCLA=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept

# Ignore this if you feel adventurous
ONLY_FOR_ARCHS=		aarch64 amd64 arm armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	Needs a little endian environment

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libfltk.so:x11-toolkits/fltk

USES=		cargo cmake:noninja pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	ja2-stracciatella
GH_PROJECT=	ja2-stracciatella
USE_LDCONFIG=	yes
USE_SDL=	sdl2

CMAKE_ARGS=	-DEXTRA_DATA_DIR:PATH="${DATADIR}"
CMAKE_OFF=	WITH_UNITTESTS
LDFLAGS+=	-Wl,--as-needed
MAKE_ENV=	${CARGO_ENV}

CARGO_CARGOTOML=	${WRKSRC}/rust/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC}/rust/Cargo.lock
CARGO_TARGET_DIR=	${WRKSRC}/rust
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_CRATES=	aho-corasick-0.5.3 \
		fuchsia-cprng-0.1.1 \
		getopts-0.2.18 \
		itoa-0.4.3 \
		kernel32-sys-0.2.2 \
		libc-0.2.51 \
		memchr-0.1.11 \
		proc-macro2-0.4.27 \
		quote-0.6.11 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rdrand-0.4.0 \
		regex-0.1.80 \
		regex-syntax-0.3.9 \
		remove_dir_all-0.5.1 \
		ryu-0.2.7 \
		serde-1.0.90 \
		serde_derive-1.0.90 \
		serde_json-1.0.39 \
		shell32-sys-0.1.2 \
		syn-0.15.30 \
		tempdir-0.3.7 \
		thread-id-2.0.0 \
		thread_local-0.2.7 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		user32-sys-0.2.0 \
		utf8-ranges-0.1.3 \
		winapi-0.2.8 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

post-patch:
	@${REINPLACE_CMD} -e 's|/some/place/where/the/data/is|${DATADIR}|' \
		${WRKSRC}/rust/src/stracciatella.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ja2 \
		${STAGEDIR}${PREFIX}/bin/ja2-launcher \
		${STAGEDIR}${PREFIX}/lib/libstracciatella.so

.include <bsd.port.mk>
