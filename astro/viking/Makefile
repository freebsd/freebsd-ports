# New ports collection makefile for:	viking
# Date created: 			29 April 2008
# Whom: 				David Le Brun <david@trucs.org>
#
# $FreeBSD$
#

PORTNAME=	viking
PORTVERSION=	1.3
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to manage GPS data (tracks, waypoints, etc)

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	gpsbabel:${PORTSDIR}/astro/gpsbabel

OPTIONS=	GEOTAG	"Enable Geotag support"		on \
		GPSD	"Enable realtime GPS tracking"	off

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

.if defined(WITH_GEOTAG)
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
.else
CONFIGURE_ARGS+=	--disable-geotag
.endif

.if defined(WITH_GPSD)
LIB_DEPENDS+=	gps.20:${PORTSDIR}/astro/gpsd
.else
CONFIGURE_ARGS+=	--disable-realtime-gps-tracking
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/s| -g | |' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
