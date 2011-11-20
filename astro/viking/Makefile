# New ports collection makefile for:	viking
# Date created: 			29 April 2008
# Whom: 				David Le Brun <david@trucs.org>
#
# $FreeBSD$
#

PORTNAME=	viking
PORTVERSION=	1.2.2
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to manage GPS data (tracks, waypoints, etc)

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	gpsbabel:${PORTSDIR}/astro/gpsbabel

OPTIONS=	GPSD	"Enable realtime GPS tracking"	off

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomedocutils gtk20 libglade2
USE_PERL5_RUN=	yes

.include <bsd.port.options.mk>

.if defined(WITH_GPSD)
LIB_DEPENDS+=	gps.20:${PORTSDIR}/astro/gpsd
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

post-patch:
	@${REINPLACE_CMD} -e 's|gps_poll|gps_read|g' ${WRKSRC}/configure

.include <bsd.port.mk>
