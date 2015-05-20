# Created by: Anton Karpov <toxa@toxahost.ru>
# $FreeBSD$

PORTNAME=	gpsd
PORTVERSION=	3.14
PORTREVISION=	2
CATEGORIES=	astro geography
MASTER_SITES=	SAVANNAH

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Daemon that monitors one or more GPSes attached to a host computer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt

USES=		cpe pathfix pkgconfig python scons
CPE_VENDOR=	gpsd_project
USE_RC_SUBR=	gpsd

MAKE_ARGS=	prefix="${PREFIX}" mandir="man" pkgconfig="libdata/pkgconfig"
MAKE_ENV=	DESTDIR="${STAGEDIR}"

OPTIONS_DEFINE=	AIVDM ASHTECH CPPBIND DBUS EARTHMATE EVERMORE FURY FV18 GARMIN \
		GARMINTXT GEOSTAR GPSCLOCK IPV6 ITRAX MTK NAVCOM NCURSES \
		NETFEED NMEA0183 NTP NTPSHM NTRIP OCEANSERVER ONCORE \
		PASSTHROUGH PPS PROFILING RECONFIGURE RTCM104V2 RTCM104V3 \
		SHMEXPORT SIRF SOCKEXPORT SUPERSTARII TIMING TNT TRIPMATE \
		TSIP QTBIND UBLOX USB
OPTIONS_DEFAULT= AIVDM ASHTECH CPPBIND EARTHMATE EVERMORE FURY FV18 GARMIN \
		GARMINTXT GEOSTAR GPSCLOCK ITRAX NAVCOM NCURSES NETFEED \
		NMEA0183 NTP NTPSHM NTRIP OCEANSERVER ONCORE PASSTHROUGH \
		RECONFIGURE RTCM104V2 RTCM104V3 SHMEXPORT SIRF SOCKEXPORT \
		SUPERSTARII TIMING TNT TRIPMATE TSIP UBLOX USB

AIVDM_DESC=		Aivdm support
ASHTECH_DESC=		Ashtech support
CPPBIND_DESC=		Build C++ bindings
EARTHMATE_DESC=		DeLorme EarthMate Zodiac support
EVERMORE_DESC=		Evermore binary support
FURY_DESC=		Jackson Labs Fury and Firefly support
FV18_DESC=		San Jose Navigation FV-18 support
GARMIN_DESC=		Garmin kernel driver support
GARMINTXT_DESC=		Garmin Simple Text support
GEOSTAR_DESC=		Geostar Protocol support
GPSCLOCK_DESC=		GPSclock support
ITRAX_DESC=		iTrax support
MTK_DESC=		MTK-3301 support
NAVCOM_DESC=		Navcom support
NCURSES_DESC=		Build with ncurses
NETFEED_DESC=		Build support for handling TCP/IP data sources
NMEA0183_DESC=		NMEA0183 support
NTP_DESC=		NTP time hinting support
NTPSHM_DESC=		NTP time hinting support via shared memory
NTRIP_DESC=		NTRIP support
OCEANSERVER_DESC=	Oceanserver support
ONCORE_DESC=		Motorola OnCore chipset support
PASSTHROUGH_DESC=	Build support for passing through JSON
PPS_DESC=		PPS time syncing support
PROFILING_DESC=		Profiling support
RECONFIGURE_DESC=	Allow gpsd to change device settings
RTCM104V2_DESC=		rtcm104v2 support
RTCM104V3_DESC=		rtcm104v3 support
SHMEXPORT_DESC=		Enable export via shared memory
SIRF_DESC=		SiRF chipset support
SOCKEXPORT_DESC=	Enable export over sockets
SUPERSTARII_DESC=	SuperStarII support
TIMING_DESC=		Build latency timing support
TNT_DESC=		True North Technologies support
TRIPMATE_DESC=		DeLorme TripMate support
TSIP_DESC=		Trimble TSIP support
QTBIND_DESC=		build QT bindings
UBLOX_DESC=		u-blox protocol support
USB_DESC=		libusb support for USB devices

.include <bsd.port.options.mk>

# Options related to GPS protocols
.if ! ${PORT_OPTIONS:MNMEA0183}
MAKE_ARGS+=	nmea0183=no
.endif

.if ! ${PORT_OPTIONS:MASHTECH}
MAKE_ARGS+=	ashtech=no
.endif

.if ! ${PORT_OPTIONS:MEARTHMATE}
MAKE_ARGS+=	earthmate=no
.endif

.if ! ${PORT_OPTIONS:MEVERMORE}
MAKE_ARGS+=	evermore=no
.endif

.if ! ${PORT_OPTIONS:MFURY}
MAKE_ARGS+=	fury=no
.endif

.if ! ${PORT_OPTIONS:MFV18}
MAKE_ARGS+=	fv18=no
.endif

.if ! ${PORT_OPTIONS:MGARMIN}
MAKE_ARGS+=	garmin=no
.endif

.if ! ${PORT_OPTIONS:MGARMINTXT}
MAKE_ARGS+=	garmintxt=no
.endif

.if ! ${PORT_OPTIONS:MGEOSTAR}
MAKE_ARGS+=	geostar=no
.endif

.if ! ${PORT_OPTIONS:MITRAX}
MAKE_ARGS+=	itrax=no
.endif

.if ! ${PORT_OPTIONS:MMTK}
MAKE_ARGS+=	mtk3301=no
.endif

.if ! ${PORT_OPTIONS:MNAVCOM}
MAKE_ARGS+=	navcom=no
.endif

.if ! ${PORT_OPTIONS:MONCORE}
MAKE_ARGS+=	oncore=no
.endif

.if ! ${PORT_OPTIONS:MSIRF}
MAKE_ARGS+=	sirf=no
.endif

.if ! ${PORT_OPTIONS:MSUPERSTARII}
MAKE_ARGS+=	superstar2=no
.endif

.if ! ${PORT_OPTIONS:MTNT}
MAKE_ARGS+=	tnt=no
.endif

.if ! ${PORT_OPTIONS:MTRIPMATE}
MAKE_ARGS+=	tripmate=no
.endif

.if ! ${PORT_OPTIONS:MTSIP}
MAKE_ARGS+=	tsip=no
.endif

.if ! ${PORT_OPTIONS:MUBLOX}
MAKE_ARGS+=	ublox=no
.endif

# Options related to Non-GPS protocols
.if ! ${PORT_OPTIONS:MAIVDM}
MAKE_ARGS+=	aivdm=no
.endif

.if ! ${PORT_OPTIONS:MGPSCLOCK}
MAKE_ARGS+=	gpsclock=no
.endif

.if ! ${PORT_OPTIONS:MNTRIP}
MAKE_ARGS+=	ntrip=no
.endif

.if ! ${PORT_OPTIONS:MOCEANSERVER}
MAKE_ARGS+=	oceanserver=no
.endif

.if ! ${PORT_OPTIONS:MRTCM104V2}
MAKE_ARGS+=	rtcm104v2=no
.endif

.if ! ${PORT_OPTIONS:MRTCM104V3}
MAKE_ARGS+=	rtcm104v3=no
.endif

# Time service
.if ! ${PORT_OPTIONS:MNTP}
MAKE_ARGS+=	ntp=no
.endif

.if ! ${PORT_OPTIONS:MNTPSHM}
MAKE_ARGS+=	ntpshm=no
.endif

.if ! ${PORT_OPTIONS:MPPS}
MAKE_ARGS+=	pps=no
.else
.	if ! ${PORT_OPTIONS:MNTPSHM}
IGNORE=		PPS requires NTPSHM
.	endif
.endif

# Export methods
.if ! ${PORT_OPTIONS:MSOCKEXPORT}
MAKE_ARGS+=	socket_export=no
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-1.so:${PORTSDIR}/devel/dbus
MAKE_ARGS+=	dbus_export=yes
.endif

.if ! ${PORT_OPTIONS:MSHMEXPORT}
MAKE_ARGS+=	shm_export=no
.endif

# Communication
.if ! ${PORT_OPTIONS:MUSB}
MAKE_ARGS+=	usb=no
.endif

.if ! ${PORT_OPTIONS:MIPV6}
MAKE_ARGS+=	ipv6=no
.endif

.if ! ${PORT_OPTIONS:MNETFEED}
MAKE_ARGS+=	netfeed=no
.endif

.if ! ${PORT_OPTIONS:MPASSTHROUGH}
MAKE_ARGS+=	passthrough=no
.endif

# Other daemon options
.if ! ${PORT_OPTIONS:MTIMING}
MAKE_ARGS+=	timing=no
.endif

# Client-side options
.if ! ${PORT_OPTIONS:MNCURSES}
MAKE_ARGS+=	ncurses=no
.endif

.if ${PORT_OPTIONS:MQTBIND}
USE_QT4=	network
MAKE_ARGS+=	qt=yes
PLIST_SUB+=	QTBIND=""
.else
MAKE_ARGS+=	qt=no
PLIST_SUB+=	QTBIND="@comment "
.endif

.if ! ${PORT_OPTIONS:MRECONFIGURE}
MAKE_ARGS+=	reconfigure=no
.endif

.if ! ${PORT_OPTIONS:MCPPBIND}
MAKE_ARGS+=	libgpsmm=no
.endif

# Build control
.if ${PORT_OPTIONS:MPROFILING}
MAKE_ARGS+=	profiling=yes
.endif

# generates .py[co] files for installed modules
# if that's not done, ${PYTHON_SITELIBDIR}/gps will be polluted
# with these files when module is imported from root user
post-install:
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
