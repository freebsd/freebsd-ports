# New ports collection makefile for:	viking
# Date created: 			29 April 2008
# Whom: 				David Le Brun <david@trucs.org>
#
# $FreeBSD$
#

PORTNAME=	viking
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	david@trucs.org
COMMENT=	Program to manage GPS data (tracks, waypoints, etc)

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	gpsbabel:${PORTSDIR}/astro/gpsbabel

USE_PERL5_RUN=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CPPFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	GPSD	"Enable realtime GPS tracking"	off

.include <bsd.port.pre.mk>

.if defined(WITH_GPSD)
LIB_DEPENDS+=	gps.18:${PORTSDIR}/astro/gpsd
.else
CONFIGURE_ARGS+=	--disable-realtime-gps-tracking
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
