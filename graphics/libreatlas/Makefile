# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	libreatlas
PORTVERSION=	1.0.0a
PORTREVISION=	19
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Open Source Geography Education application

LICENSE=	GPLv3

LIB_DEPENDS=	libmspack.so:${PORTSDIR}/archivers/libmspack \
		libspatialite.so:${PORTSDIR}/databases/spatialite \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libgeos.so:${PORTSDIR}/graphics/geos \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libgeotiff.so:${PORTSDIR}/graphics/libgeotiff \
		librasterlite.so:${PORTSDIR}/graphics/librasterlite \
		libpng.so:${PORTSDIR}/graphics/png \
		libproj.so:${PORTSDIR}/graphics/proj \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfreexl.so:${PORTSDIR}/textproc/freexl \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USES=		gettext gmake iconv jpeg pkgconfig
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender xxf86vm
USE_GNOME=	atk gdkpixbuf2 glib20 gtk20 pango
USE_WX=		2.8
WANT_UNICODE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lgeos_c

PLIST_FILES=	bin/LibreAtlas

DESKTOP_ENTRIES="LibreAtlas" "${COMMENT}" "" "LibreAtlas" \
		"Graphics;Viewer;" true

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|$${WX_CONFIG}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
