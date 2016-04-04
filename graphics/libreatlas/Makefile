# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	libreatlas
PORTVERSION=	1.0.0a
PORTREVISION=	20
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Open Source Geography Education application

LICENSE=	GPLv3

LIB_DEPENDS=	libmspack.so:archivers/libmspack \
		libspatialite.so:databases/spatialite \
		libsqlite3.so:databases/sqlite3 \
		libpthread-stubs.so:devel/libpthread-stubs \
		libpcre.so:devel/pcre \
		libcairo.so:graphics/cairo \
		libgeos.so:graphics/geos \
		libjbig.so:graphics/jbigkit \
		libgeotiff.so:graphics/libgeotiff \
		librasterlite.so:graphics/librasterlite \
		libpng.so:graphics/png \
		libproj.so:graphics/proj \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfreexl.so:textproc/freexl \
		libfontconfig.so:x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USES=		gettext gmake iconv jpeg pkgconfig
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender xxf86vm
USE_GNOME=	atk gdkpixbuf2 glib20 gtk20 pango
USE_WX=		2.8
WX_UNICODE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lgeos_c -lsqlite3

PLIST_FILES=	bin/LibreAtlas

DESKTOP_ENTRIES="LibreAtlas" "${COMMENT}" "" "LibreAtlas" \
		"Graphics;Viewer;" true

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|$${WX_CONFIG}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
