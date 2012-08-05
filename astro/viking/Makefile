# New ports collection makefile for:	viking
# Date created: 			29 April 2008
# Whom: 				David Le Brun <david@trucs.org>
#
# $FreeBSD$
#

PORTNAME=	viking
PORTVERSION=	1.3.1
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to manage GPS data (tracks, waypoints, etc)

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		expat:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	gpsbabel:${PORTSDIR}/astro/gpsbabel

OPTIONS_DEFINE=	GEOTAR GPSD
OPTIONS_DEFAULT=	GEOTAG
GEOTAG_DESC=	Enable Geotag support
GPSD_DESC=	Enable realtime GPS tracking

USE_GNOME=	gnomedocutils gtk20
USE_PERL5_RUN=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEOTAG}
LIB_DEPENDS+=	exif:${PORTSDIR}/graphics/libexif
.else
CONFIGURE_ARGS+=	--disable-geotag
.endif

.if ${PORT_OPTIONS:MGPSD}
LIB_DEPENDS+=	gps:${PORTSDIR}/astro/gpsd
.else
CONFIGURE_ARGS+=	--disable-realtime-gps-tracking
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/s| -g | |' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
