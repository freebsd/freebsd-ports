# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	libreatlas
PORTVERSION=	1.0.0a
PORTREVISION=	6
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Open Source Geography Education application

LIB_DEPENDS=	mspack:${PORTSDIR}/archivers/libmspack \
		spatialite:${PORTSDIR}/databases/spatialite \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		geos:${PORTSDIR}/graphics/geos \
		jbig:${PORTSDIR}/graphics/jbigkit \
		jpeg:${PORTSDIR}/graphics/jpeg \
		geotiff:${PORTSDIR}/graphics/libgeotiff \
		rasterlite:${PORTSDIR}/graphics/librasterlite \
		png15:${PORTSDIR}/graphics/png \
		proj:${PORTSDIR}/graphics/proj \
		tiff:${PORTSDIR}/graphics/tiff \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		freexl:${PORTSDIR}/textproc/freexl \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USES=		pkgconfig gettext gmake iconv
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender xxf86vm
USE_GNOME=	atk gdkpixbuf2 glib20 gtk20 pango
USE_WX=		2.8
WANT_UNICODE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/LibreAtlas

DESKTOP_ENTRIES="LibreAtlas" "${COMMENT}" "" "LibreAtlas" \
		"Graphics;Viewer;" true

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|$${WX_CONFIG}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
