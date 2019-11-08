# Created by: Anton Karpov <toxa@toxahost.ru>
# $FreeBSD$

PORTNAME=	gpsd
PORTVERSION=	3.17
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	SAVANNAH

MAINTAINER=	z7dr6ut7gs@snkmail.com
COMMENT=	Daemon that monitors one or more GPSes attached to a host computer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe pathfix pkgconfig python:2.7 scons shebangfix
CPE_VENDOR=	gpsd_project
USE_PYTHON=	flavors
USE_RC_SUBR=	gpsd
SHEBANG_FILES=	*.py gps/*.py gegps xgps gpscat xgpsspeed gpsprof \
		gpsfake

MAKE_ARGS=	prefix="${PREFIX}" mandir="man" pkgconfig="libdata/pkgconfig" \
		manbuild=no target_python="${PYTHON_CMD}" qt=no
MAKE_ENV=	DESTDIR="${STAGEDIR}"
PLIST_SUB=	PYTHON_EGGINFO=gps-${PORTVERSION}.egg-info

OPTIONS_DEFINE=	AIVDM ASHTECH CPPBIND DBUS EARTHMATE EVERMORE FURY FV18 GARMIN \
		GARMINTXT GEOSTAR GPSCLOCK IPV6 ITRAX MTK NAVCOM NCURSES \
		NETFEED NMEA0183 NTP NTPSHM NTRIP OCEANSERVER ONCORE \
		PASSTHROUGH PPS PROFILING RECONFIGURE RTCM104V2 RTCM104V3 \
		SHMEXPORT SIRF SOCKEXPORT SUPERSTARII TIMING TNT TRIPMATE \
		TSIP UBLOX USB X11
OPTIONS_DEFAULT= AIVDM ASHTECH CPPBIND EARTHMATE EVERMORE FURY FV18 GARMIN \
		GARMINTXT GEOSTAR GPSCLOCK ITRAX NAVCOM NCURSES NETFEED \
		NMEA0183 NTP NTPSHM NTRIP OCEANSERVER ONCORE PASSTHROUGH \
		RECONFIGURE RTCM104V2 RTCM104V3 SHMEXPORT SIRF SOCKEXPORT \
		SUPERSTARII TIMING TNT TRIPMATE TSIP UBLOX USB X11
OPTIONS_SUB=	yes

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
UBLOX_DESC=		u-blox protocol support
USB_DESC=		libusb support for USB devices

# Options related to GPS protocols
NMEA0183_MAKE_ARGS_OFF=	nmea0183=no
ASHTECH_MAKE_ARGS_OFF=	ashtech=no
EARTHMATE_MAKE_ARGS_OFF=	earthmate=no
EVERMORE_MAKE_ARGS_OFF=	evermore=no
FURY_MAKE_ARGS_OFF=	fury=no
FV18_MAKE_ARGS_OFF=	fv18=no
GARMIN_MAKE_ARGS_OFF=	garmin=no
GARMINTXT_MAKE_ARGS_OFF=	garmintxt=no
GEOSTAR_MAKE_ARGS_OFF=	geostar=no
ITRAX_MAKE_ARGS_OFF=	itrax=no
MTK_MAKE_ARGS_OFF=	mtk3301=no
NAVCOM_MAKE_ARGS_OFF=	navcom=no
ONCORE_MAKE_ARGS_OFF=	oncore=no
SIRF_MAKE_ARGS_OFF=	sirf=no
SUPERSTARII_MAKE_ARGS_OFF=	superstar2=no
TNT_MAKE_ARGS_OFF=	tnt=no
TRIPMATE_MAKE_ARGS_OFF=	tripmate=no
TSIP_MAKE_ARGS_OFF=	tsip=no
UBLOX_MAKE_ARGS_OFF=	ublox=no

# Options related to Non-GPS protocols
AIVDM_MAKE_ARGS_OFF=	aivdm=no
GPSCLOCK_MAKE_ARGS_OFF=	gpsclock=no
NTRIP_MAKE_ARGS_OFF=	ntrip=no
OCEANSERVER_MAKE_ARGS_OFF=	oceanserver=no
RTCM104V2_MAKE_ARGS_OFF=	rtcm104v2=no
RTCM104V3_MAKE_ARGS_OFF=	rtcm104v3=no

# Time service
NTP_MAKE_ARGS_OFF=	ntp=no
NTPSHM_MAKE_ARGS_OFF=	ntpshm=no
PPS_MAKE_ARGS_OFF=	pps=no
PPS_IMPLIES=		NTPSHM

# Export methods
SOCKEXPORT_MAKE_ARGS_OFF=	socket_export=no
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MAKE_ARGS=		dbus_export=yes
DBUS_MAKE_ARGS_OFF=	dbus_export=no
SHMEXPORT_MAKE_ARGS_OFF=	shm_export=no

# Communication
USB_MAKE_ARGS_OFF=	usb=no
IPV6_MAKE_ARGS_OFF=	ipv6=no
NETFEED_MAKE_ARGS_OFF=	netfeed=no
PASSTHROUGH_MAKE_ARGS_OFF=	passthrough=no

# Other daemon options
TIMING_MAKE_ARGS_OFF=	timing=no

# Client-side options
NCURSES_MAKE_ARGS_OFF=	ncurses=no
NCURSES_USES=		ncurses
RECONFIGURE_MAKE_ARGS_OFF=	reconfigure=no
CPPBIND_MAKE_ARGS_OFF=	libgpsmm=no
X11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}gobject3>=0:devel/py-gobject3@${PY_FLAVOR}
#X11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}
X11_USES=	gnome
X11_USE=	GNOME=gtk30

# Build control
PROFILING_MAKE_ARGS=	profiling=yes

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
