# New ports collection makefile for:	gpsd
# Date created:				Jan, 10. 2006
# Whom:					Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	gpsd
PORTVERSION=	2.32
CATEGORIES=	astro
MASTER_SITES=	http://download.berlios.de/${PORTNAME}/

MAINTAINER=	toxa@toxahost.ru
COMMENT=	Daemon that monitors one or more GPSes attached to a host computer

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
MAN1=	gps.1 gpsfake.1 gpsflash.1 gpspipe.1 gpsprof.1 rtcmdecode.1 sirfmon.1
MAN3=	libgps.3 libgpsd.3 libgpsmm.3
MAN5=	rtcm-104.5 srec.5
MAN8=	gpsd.8
MANCOMPRESSED=	no

OPTIONS=	XGPS "Build xgps and xgpsspeed (require X)" off \
		NMEA "NMEA support" on \
		SIRFII "SiRF-II chipset support" on \
		TSIP "Trimble TSIP support" on \
		FV18 "San Jose Navigation FV-18 support" on \
		TRIPMATE "DeLorme TripMate support" on \
		EARTHMATE "DeLorme EarthMate Zodiac support" on \
		ITRAX "iTrax support" on \
		ITALK "iTalk support" on \
		TNT "True North Technologies support" off \
		EVERMORE "Evermore binary support" on \
		RTCM104 "rtcm104 support" on \
		NTPSHM "TP time hinting support" on \
		PPS "PPS time syncing support" off \
		DBUS "DBUS support" off

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-message
CONFIGURE_ARGS+=--disable-garmin

INSTALLS_SHLIB=	yes

.if defined(WITH_XGPS)
CONFIGURE_ARGS+=--with-x
USE_XLIB=yes
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.endif

.if defined(WITHOUT_NMEA)
CONFIGURE_ARGS+=--disable-nmea
.endif

.if defined(WITHOUT_SIRFII)
CONFIGURE_ARGS+=--disable-sirfII
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

.if defined(WITHOUT_ITALK)
CONFIGURE_ARGS+=--disable-italk
.endif

.if defined(WITH_TNT)
CONFIGURE_ARGS+=--enable-tnt
.endif

.if defined(WITHOUT_EVERMORE)
CONFIGURE_ARGS+=--disable-evermore
.endif

.if defined(WITHOUT_RTCM104)
CONFIGURE_ARGS+=--disable-rtcm104
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
