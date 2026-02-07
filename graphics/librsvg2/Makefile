PORTNAME=	librsvg
PORTVERSION=	2.40.21
PORTREVISION=	6
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files
WWW=		https://live.gnome.org/LibRsvg

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libcroco-0.6.so:textproc/libcroco

USES=		cpe gmake gnome libtool localbase pathfix pkgconfig tar:xz

USE_GNOME=	cairo gnomeprefix gdkpixbuf introspection:build \
		libxml2 pango
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
CONFIGURE_ARGS=	--disable-Bsymbolic

DOCSDIR?=	${PREFIX}/share/doc
GNOME_HTML_DIR=	${DOCSDIR}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

CONFLICTS_INSTALL=	librsvg2-rust
# librsvg2 2.42+ needs rust to build, which is not available on all
# FreeBSD archs. So limit pure C version 2.40.x.
PORTSCOUT=	limit:^2\.40\.

OPTIONS_DEFINE=		DOCS VAPI
OPTIONS_DEFAULT=	DOCS VAPI
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_CONFIGURE_ENABLE=	gtk-doc gtk-doc-html

VAPI_USES=		vala:build
VAPI_CONFIGURE_ON=	--enable-vala=yes
VAPI_CONFIGURE_OFF=	--enable-vala=no

post-patch:
	@${REINPLACE_CMD} -e 's|GTK3_REQUIRED=3.[0-9][0-9].[0-9]|GTK3_REQUIRED=9.90.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
