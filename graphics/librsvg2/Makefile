PORTNAME=	librsvg
PORTVERSION=	2.40.23
CATEGORIES=	graphics gnome
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files
WWW=		https://live.gnome.org/LibRsvg

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/share/gtk-doc/data/gtk-doc.make:textproc/gtk-doc
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libcroco-0.6.so:textproc/libcroco

USES=		autoreconf cpe gmake gnome libtool pathfix pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_TAGNAME=	${PORTNAME}-gtk-${PORTVERSION}
USE_GNOME=	cairo gnomeprefix gdkpixbuf introspection:build \
		libxml2 pango
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
CONFIGURE_ARGS=	--disable-Bsymbolic

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

CONFLICTS_INSTALL=	librsvg2-rust
# librsvg2 2.42+ needs rust to build, which is not available on all
# FreeBSD archs. So limit pure C version 2.40.x.
PORTSCOUT=	limit:^2\.40\.

OPTIONS_DEFINE=		VAPI
OPTIONS_DEFAULT=	VAPI
OPTIONS_SUB=		yes

VAPI_USES=		vala:build
VAPI_CONFIGURE_ON=	--enable-vala=yes
VAPI_CONFIGURE_OFF=	--enable-vala=no

post-patch:
	@${REINPLACE_CMD} -e '/^GTK3_REQUIRED/s|=3\.[0-9]|=9.9|' \
		${WRKSRC}/configure.ac

pre-test:
	@${LN} -sf librsvg/rsvg.h ${WRKSRC}

.include <bsd.port.mk>
