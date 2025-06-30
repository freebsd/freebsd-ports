PORTNAME=	foxtrotgps
PORTVERSION=	1.2.2
PORTREVISION=	7
CATEGORIES=	astro geography
MASTER_SITES=	http://www.foxtrotgps.org/releases/

MAINTAINER=	crwhipp@gmail.com
COMMENT=	Lightweight opensource gps moving map application
WWW=		https://www.foxtrotgps.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexif.so:graphics/libexif \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgps.so:astro/gpsd \
		libsoup-2.4.so:devel/libsoup

USES=		compiler:c++11-lang gettext gmake gnome pkgconfig python \
		shebangfix sqlite:3
USE_GNOME=	cairo gtk20 intltool libglade2 libxml2
GLIB_SCHEMAS=	org.foxtrotgps.gschema.xml

SHEBANG_FILES=	contrib/convert2gpx \
		contrib/convert2osm \
		contrib/georss2foxtrotgps-poi\
		contrib/gpx2osm \
		contrib/osb2foxtrot \
		contrib/poi2osm

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-schemas-install
CONFIGURE_ENV=	DATADIRNAME=share

INFO=		foxtrotgps

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
