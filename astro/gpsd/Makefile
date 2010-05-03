# New ports collection makefile for:	gpsd
# Date created:				Jan, 10. 2006
# Whom:					Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	gpsd
PORTVERSION=	2.90
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Daemon that monitors one or more GPSes attached to a host computer

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt

USE_RC_SUBR=	gpsd
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

MAN1=	cgps.1 cgpxlogger.1 gps.1 gpscat.1 gpsctl.1 gpsfake.1 \
	gpspipe.1 gpsprof.1 xgps.1 xgpsspeed.1 gpsdecode.1 gpsmon.1 \
	lcdgps.1
MAN3=	libgps.3 libgpsd.3 libgpsmm.3
MAN5=	rtcm-104.5 srec.5
MAN8=	gpsd.8
MANCOMPRESSED=	no

OPTIONS=	XGPS "Build xgps and xgpsspeed (require X)" off \
		NMEA "NMEA support" on \
		SIRF "SiRF chipset support" on \
		SUPERSTARII "SuperStarII support" off \
		TSIP "Trimble TSIP support" on \
		FV18 "San Jose Navigation FV-18 support" on \
		TRIPMATE "DeLorme TripMate support" on \
		EARTHMATE "DeLorme EarthMate Zodiac support" on \
		ITRAX "iTrax support" on \
		ASHTECH "Ashtech support" on \
		NAVCOM "Navcom support" on \
		GARMIN "Garmin kernel driver support" on \
		GARMINTXT "Garmin Simple Text support" off \
		TNT "True North Technologies support" off \
		OCEANSERVER "Oceanserver support" off \
		UBX "UBX protocol support" on \
		EVERMORE "Evermore binary support" on \
		MKT3301 "MKT-3301 support" on \
		GPSCLOCK "GPSclock support" on \
		RTCM104V2 "rtcm104v2 support" on \
		RTCM104V3 "rtcm104v3 support" on \
		NTRIP "NTRIP support" on \
		PROFILING "Profiling support" off \
		NTPSHM "TP time hinting support" on \
		PPS "PPS time syncing support" off \
		DBUS "DBUS support" off

USE_PYTHON=	yes

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-message
CONFIGURE_ARGS+=--disable-garmin

.if defined(WITH_XGPS)
CONFIGURE_ENV+=	CFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lm"
CONFIGURE_ARGS+=--with-x
USE_MOTIF=	yes
USE_XORG=	x11 xpm xaw7
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.endif

.if defined(WITHOUT_NMEA)
CONFIGURE_ARGS+=--disable-nmea
.endif

.if defined(WITHOUT_SIRF)
CONFIGURE_ARGS+=--disable-sirf
.endif

.if defined(WITH_SUPERSTARII)
CONFIGURE_ARGS+=	--enable-superstar2
.endif

.if defined(WITHOUT_TSIP)
CONFIGURE_ARGS+=--disable-tsip
.endif

.if defined(WITHOUT_FV18)
CONFIGURE_ARGS+=--disable-fv18
.endif

.if defined(WITHOUT_TRIPMATE)
CONFIGURE_ARGS+=--disable-tripmate
.endif

.if defined(WITHOUT_EARTHMATE)
CONFIGURE_ARGS+=--disable-earthmate
.endif

.if defined(WITHOUT_ITRAX)
CONFIGURE_ARGS+=--disable-itrax
.endif

.if defined(WITHOUT_ASHTECH)
CONFIGURE_ARGS+=--disable-ashtech
.endif

.if defined(WITHOUT_NAVCOM)
CONFIGURE_ARGS+=--disable-navcom
.endif

.if defined(WITHOUT_GARMIN)
CONFIGURE_ARGS+=--disable-garmin
.endif

.if defined(WITH_GARMINTXT)
CONFIGURE_ARGS+=--enable-garmintxt
.endif

.if defined(WITH_TNT)
CONFIGURE_ARGS+=--enable-tnt
.endif

.if defined(WITH_OCEANSERVER)
CONFIGURE_ARGS+=--enable-oceanserver
.endif

.if defined(WITHOUT_UBX)
CONFIGURE_ARGS+=--disable-ubx
.endif

.if defined(WITHOUT_EVERMORE)
CONFIGURE_ARGS+=--disable-evermore
.endif

.if defined(WITHOUT_MKT3301)
CONFIGURE_ARGS+=--disable-mkt3301
.endif

.if defined(WITHOUT_GPSCLOCK)
CONFIGURE_ARGS+=--disable-gpscloclk
.endif

.if defined(WITHOUT_RTCM104V2)
CONFIGURE_ARGS+=--disable-rtcm104v2
.endif

.if defined(WITHOUT_RTCM104V3)
CONFIGURE_ARGS+=--disable-rtcm104v3
.endif

.if defined(WITHOUT_NTRIP)
CONFIGURE_ARGS+=--disable-ntrip
.endif

.if defined(WITH_PROFILING)
CONFIGURE_ARGS+=--enable-profiling
.endif

.if defined(WITHOUT_NTPSHM)
CONFIGURE_ARGS+=--disable-ntpshm
.endif

.if defined(WITH_PPS)
CONFIGURE_ARGS+=--enable-pps
.endif

.if defined(WITH_DBUS)
CONFIGURE_ARGS+=--enable-dbus
.endif

post-patch:
	@${REINPLACE_CMD} -e '/XMLTO/d' ${WRKSRC}/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
