# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librsvg
PORTVERSION=	2.45.5
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME \
		CRATESIO/libc/0.2.49:libc
PKGNAMESUFFIX=	2-rust
DISTFILES=	gnome2/${DISTNAME}${EXTRACT_SUFX} \
		rust/crates/libc-0.2.49.tar.gz:libc

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

LICENSE=	LGPL20

BUILD_DEPENDS=	${RUST_DEFAULT}>=1.27.0:lang/${RUST_DEFAULT} \
		valac:lang/vala
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libcroco-0.6.so:textproc/libcroco

USES=		gettext gmake gnome libtool pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 libxml2 pango gnomeprefix introspection:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vala \
		--disable-Bsymbolic \
		--disable-dependency-tracking \
		--disable-static
INSTALL_TARGET=	install-strip
# Make sure it uses the Rust toolchain from ports.
CONFIGURE_ENV=	CARGO=${LOCALBASE}/bin/cargo \
		RUSTC=${LOCALBASE}/bin/rustc
MAKE_ENV=	RUSTC=${LOCALBASE}/bin/rustc

CONFLICTS_INSTALL=	librsvg2

post-patch:
# Avoid dependency loop with gtk3 (it depends on librsvg2), do not build rsvg-view
	@${REINPLACE_CMD} -e 's|GTK3_REQUIRED=3.[0-9][0-9].[0-9]|GTK3_REQUIRED=9.90.0|g' \
		${WRKSRC}/configure
# Disable vendor checksums
	@${REINPLACE_CMD} -e 's/"files":{[^}]*}/"files":{}/' \
		${WRKSRC}/vendor/*/.cargo-checksum.json
# Replace vendored libc crate with libc-0.2.49 for tier 2 arch support
	${RM} -r ${WRKSRC}/vendor/libc
	${MV} ${WRKDIR}/libc-0.2.49 ${WRKSRC}/vendor/libc
	@${ECHO_CMD} '{"files":{}}' > ${WRKSRC}/vendor/libc/.cargo-checksum.json

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/cargo update

.include <bsd.port.mk>
