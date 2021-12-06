# Created by: Ade Lovett <ade@FreeBSD.org>

PORTNAME=	librsvg
PORTVERSION=	2.40.21
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libcroco-0.6.so:textproc/libcroco

USES=		cpe gmake gnome libtool localbase pathfix pkgconfig tar:xz

CONFLICTS_INSTALL=	librsvg2-rust
# librsvg2 2.42+ needs rust to build, which is not available on all
# FreeBSD archs. So limit pure C version 2.40.x.
PORTSCOUT=	limit:^2\.40\.

OPTIONS_DEFINE=		DOCS VAPI
OPTIONS_DEFAULT=	DOCS VAPI
OPTIONS_SUB=		yes

DOCS_CONFIGURE_ENABLE=	grk-doc-html

VAPI_BUILD_DEPENDS=	valac:lang/vala
VAPI_CONFIGURE_ON=	--enable-vala=yes
VAPI_CONFIGURE_OFF=	--enable-vala=no

USE_GNOME=	cairo gnomeprefix gdkpixbuf2 introspection:build \
		libxml2 pango
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-Bsymbolic

DOCSDIR?=	${PREFIX}/share/doc
GNOME_HTML_DIR=	${DOCSDIR}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|GTK3_REQUIRED=3.[0-9][0-9].[0-9]|GTK3_REQUIRED=9.90.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
