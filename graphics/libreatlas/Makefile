# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	libreatlas
PORTVERSION=	1.0.0a
PORTREVISION=	24
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Open Source Geography Education application

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libmspack.so:archivers/libmspack \
		libspatialite.so:databases/spatialite \
		libsqlite3.so:databases/sqlite3 \
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
USES=		compiler:c++11-lang gettext gmake gnome iconv jpeg pathfix \
		pkgconfig xorg
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender xxf86vm
USE_GNOME=	atk gdkpixbuf2 glib20 gtk20 pango
USE_WX=		2.8

CPPFLAGS+=	-I${LOCALBASE}/include -DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lgeos_c -lsqlite3

PLIST_FILES=	bin/LibreAtlas

DESKTOP_ENTRIES="LibreAtlas" "${COMMENT}" "" "LibreAtlas" \
		"Graphics;Viewer;" true

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|$${WX_CONFIG}|' ${WRKSRC}/configure

.include <bsd.port.mk>
