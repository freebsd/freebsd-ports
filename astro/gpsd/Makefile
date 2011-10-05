# New ports collection makefile for:	gpsd
# Date created:				Jan, 10. 2006
# Whom:					Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	gpsd
PORTVERSION=	3.1
CATEGORIES=	astro geography
MASTER_SITES=	SAVANNAH

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Daemon that monitors one or more GPSes attached to a host computer

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt

USE_GNOME=	pkgconfig
USE_SCONS=	yes
USE_RC_SUBR=	gpsd
USE_PYTHON=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	gps-${PORTVERSION}.egg-info
MAKE_JOBS_SAFE=	yes

SCONS_BUILDENV=	${SCONS_ENV}
SCONS_ARGS=	prefix="${PREFIX}" mandir="/man" pkgconfigdir="/libdata/pkgconfig"

MAN1=	cgps.1 gegps.1 gps.1 gpscat.1 gpsctl.1 gpsdecode.1 \
	gpsfake.1  gpspipe.1 gpsprof.1 xgps.1 xgpsspeed.1 \
	gpsmon.1 lcdgps.1
MAN3=	libgps.3 libgpsd.3 libgpsmm.3 libQgpsmm.3
MAN5=	srec.5 gpsd_json.5
MAN8=	gpsd.8 gpsdctl.8
MANCOMPRESSED=	no

OPTIONS=	AIVDM "Aivdm support" on \
		ASHTECH "Ashtech support" on \
		CPPBIND "Build C++ bindings" on \
		DBUS "DBUS support" off \
		EARTHMATE "DeLorme EarthMate Zodiac support" on \
		EVERMORE "Evermore binary support" on \
		FV18 "San Jose Navigation FV-18 support" on \
		GARMIN "Garmin kernel driver support" on \
		GARMINTXT "Garmin Simple Text support" on \
		GEOSTAR "Geostar Protocol support" on \
		GPSCLOCK "GPSclock support" on \
		GTK2 "Install py-gtk2 (required for xgps & xgpsspeed)" off \
		IP6 "IPv6 support" on \
		ITRAX "iTrax support" on \
		MTK "MTK-3301 support" on \
		NAVCOM "Navcom support" on \
		NETFEED "Build support for handling TCP/IP data sources" on \
		NCURSES "Build with ncurses(3)" off \
		NMEA "NMEA support" on \
		NTPSHM "NTP time hinting support" on \
		NTRIP "NTRIP support" on \
		OCEANSERVER "Oceanserver support" on \
		OLDPROTO "Old (pre-JSON) protocol support in client lib" on \
		ONCORE "Motorola OnCore chipset support" on \
		PASSTHROUGH "Build support for passing through JSON" on \
		PPS "PPS time syncing support" on \
		PPSONCTS "PPS pulse on CTS rather than DCD" off \
		PROFILING "Profiling support" off \
		RECONFIGURE "Allow gpsd to change device settings" on \
		RTCM104V2 "rtcm104v2 support" on \
		RTCM104V3 "rtcm104v3 support" on \
		SHMEXPORT "Enable export via shared memory" on \
		SIRF "SiRF chipset support" on \
		SOCKEXPORT "Enable export over sockets" on \
		SUPERSTARII "SuperStarII support" on \
		TIMING "Build latency timing support" on \
		TNT "True North Technologies support" on \
		TRIPMATE "DeLorme TripMate support" on \
		TSIP "Trimble TSIP support" on \
		QTBIND "build QT bindings" off \
		UBX "UBX protocol support" on \
		USB "libusb support for USB devices" on

.include <bsd.port.options.mk>

# Requires libusb.h available in 8.x
.if ${OSVERSION} < 800069
WITHOUT_USB=	yes
.endif

# Options related to GPS protocols
.if defined(WITHOUT_NMEA)
SCONS_ARGS+=	nmea=no
.endif

.if defined(WITHOUT_ASHTECH)
SCONS_ARGS+=	ashtech=no
.endif

.if defined(WITHOUT_EARTHMATE)
SCONS_ARGS+=	earthmate=no
.endif

.if defined(WITHOUT_EVERMORE)
SCONS_ARGS+=	evermore=no
.endif

.if defined(WITHOUT_FV18)
SCONS_ARGS+=	fv18=no
.endif

.if defined(WITHOUT_GARMIN)
SCONS_ARGS+=	garmin=no
.endif

.if defined(WITHOUT_GARMINTXT)
SCONS_ARGS+=	garmintxt=no
.endif

.if defined(WITHOUT_GEOSTAR)
SCONS_ARGS+=	geostar=no
.endif

.if defined(WITHOUT_ITRAX)
SCONS_ARGS+=	itrax=no
.endif

.if defined(WITHOUT_MTK)
SCONS_ARGS+=	mtk3301=no
.endif

.if defined(WITHOUT_NAVCOM)
SCONS_ARGS+=	navcom=no
.endif

.if defined(WITHOUT_ONCORE)
SCONS_ARGS+=	oncore=no
.endif

.if defined(WITHOUT_SIRF)
SCONS_ARGS+=	sirf=no
.endif

.if defined(WITHOUT_SUPERSTARII)
SCONS_ARGS+=	superstar2=no
.endif

.if defined(WITHOUT_TNT)
SCONS_ARGS+=	tnt=no
.endif

.if defined(WITHOUT_TRIPMATE)
SCONS_ARGS+=	tripmate=no
.endif

.if defined(WITHOUT_TSIP)
SCONS_ARGS+=	tsip=no
.endif

.if defined(WITHOUT_UBX)
SCONS_ARGS+=	ubx=no
.endif

# Options related to Non-GPS protocols
.if defined(WITHOUT_AIVDM)
SCONS_ARGS+=	aivdm=no
.endif

.if defined(WITHOUT_GPSCLOCK)
SCONS_ARGS+=	gpsclock=no
.endif

.if defined(WITHOUT_NTRIP)
SCONS_ARGS+=	ntrip=no
.endif

.if defined(WITHOUT_OCEANSERVER)
SCONS_ARGS+=	oceanserver=no
.endif

.if defined(WITHOUT_RTCM104V2)
SCONS_ARGS+=	rtcm104v2=no
.endif

.if defined(WITHOUT_RTCM104V3)
SCONS_ARGS+=	rtcm104v3=no
.endif

# Time service
.if defined(WITHOUT_NTPSHM)
SCONS_ARGS+=	ntpshm=no
.endif

.if defined(WITHOUT_PPS)
SCONS_ARGS+=	pps=no
.endif

.if defined(WITH_PPSONCTS)
SCONS_ARGS+=	pps_on_cts=yes
.endif

# Export methods
.if defined(WITHOUT_SOCKEXPORT)
SCONS_ARGS+=	socket_export=no
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus:${PORTSDIR}/devel/dbus \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
SCONS_ARGS+=	dbus_export=yes
.endif

.if defined(WITHOUT_SHMEXPORT)
SCONS_ARGS+=	shm_export=no
.endif

# Communication
.if defined(WITHOUT_USB)
SCONS_ARGS+=	usb=no
.endif

.if defined(WITHOUT_IPV6)
SCONS_ARGS+=	ipv6=no
.endif

.if defined(WITHOUT_NETFEED)
SCONS_ARGS+=	netfeed=no
.endif

.if defined(WITHOUT_PASSTHROUGH)
SCONS_ARGS+=	passthrough=no
.endif

# Other daemon options
.if defined(WITHOUT_TIMING)
SCONS_ARGS+=	timing=no
.endif

# Client-side options
.if defined(WITHOUT_OLDPROTO)
SCONS_ARGS+=	oldstyle=no
.endif

.if defined(WITH_QTBIND)
USE_QT_VER=	4
QT_COMPONENTS=	network
SCONS_ARGS+=	libQgpsmm=yes
PLIST_SUB+=	QTBIND=""
.else
SCONS_ARGS+=	libQgpsmm=no
PLIST_SUB+=	QTBIND="@comment "
.endif

.if defined(WITHOUT_RECONFIGURE)
SCONS_ARGS+=	reconfigure=no
.endif

.if defined(WITHOUT_CPPBIND)
SCONS_ARGS+=	libgpsmm=no
.endif

.if defined(WITHOUT_NCURSES)
SCONS_ARGS+=	ncurses=no
PLIST_SUB+=	CURSES="@comment "
.else
PLIST_SUB+=	CURSES=""
.endif

# Build control
.if defined(WITH_PROFILING)
SCONS_ARGS+=	profiling=yes
.endif

# generates .py[co] files for installed modules
# if that's not done, ${PYTHON_SITELIBDIR}/gps will be polluted
# with these files when module is imported from root user
post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/gps -name "*.py" -exec \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py {} \;
	@${SETENV} PYTHONOPTIMIZE=yes \
		${FIND} ${PYTHON_SITELIBDIR}/gps -name "*.py" -exec \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py {} \;

.include <bsd.port.mk>
