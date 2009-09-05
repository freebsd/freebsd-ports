# New ports collection makefile for:	ardour
# Date created:		2006-12-04
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	ardour
PORTVERSION=	2.8.2
CATEGORIES=	audio
MASTER_SITES=	http://releases.ardour.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trasz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Ardour - a digital audio workstation

LIB_DEPENDS=	lrdf.2:${PORTSDIR}/textproc/liblrdf \
		raptor.2:${PORTSDIR}/textproc/raptor \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		jack.0:${PORTSDIR}/audio/jack \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		boost_date_time.4:${PORTSDIR}/devel/boost-libs \
		gnomecanvasmm-2.6:${PORTSDIR}/graphics/libgnomecanvasmm26 \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		lo.7:${PORTSDIR}/audio/liblo \
		SoundTouch.0:${PORTSDIR}/audio/soundtouch \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		fftw3:${PORTSDIR}/math/fftw3 \
		aubio.3:${PORTSDIR}/audio/aubio
BUILD_DEPENDS=	jackit>=0.109.2:${PORTSDIR}/audio/jack

# Between 0.109.0 and earlier versions there was an api change in JACK.
# However, the library version number was not changed.  The line above
# is supposed to work around that.

USE_SCONS=	yes
SCONS_ENV+=	SYSLIBS=yes PREFIX=${PREFIX} NLS=yes
CFLAGS+=	-I${LOCALBASE}/include
USE_BZIP2=	yes
USE_GNOME=	gtk20 libxslt libgnomecanvas intltool
USE_GETTEXT=	yes
USE_LDCONFIG=	${PREFIX}/lib/ardour2 ${PREFIX}/lib/ardour2/surfaces
TEMPLATESDIR=	${PREFIX}/share/ardour2/templates
PLIST_SUB=	DISTVERSION=${DISTVERSION}
OPTIONS=	OPTIMIZED_CFLAGS "Builds with compiler optimizations" on \
		VST "Enable VST plugins support" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		needs posix_memalign()
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.endif

.if ${ARCH} == "amd64"
BROKEN=		does not compile
.endif

.if defined(WITH_VST)
SCONS_ENV+=	VST=yes
BUILD_DEPENDS+=	winegcc:${PORTSDIR}/emulators/wine \
		unzip:${PORTSDIR}/archivers/unzip \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS+=	wine.1:${PORTSDIR}/emulators/wine

PLIST_SUB+=	NO_VST="@comment "
PLIST_SUB+=	VST=""
.else
PLIST_SUB+=	NO_VST=""
PLIST_SUB+=	VST="@comment "
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not install
.endif

# Upstream uses these flags by default.
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fomit-frame-pointer -ffast-math -fstrength-reduce

.if ${ARCH} == "amd64"
SCONS_ENV+=	DIST_TARGET=x86_64
SCONS_ENV+=	FPU_OPTIMIZATION=1
.elif ${MACHINE_CPU:Msse}
SCONS_ENV+=	DIST_TARGET=i686
SCONS_ENV+=	FPU_OPTIMIZATION=1
.else
SCONS_ENV+=	DIST_TARGET=i386
SCONS_ENV+=	FPU_OPTIMIZATION=0
.endif

.else
SCONS_ENV+=	FPU_OPTIMIZATION=0
.endif

CFLAGS:=	${CFLAGS:N-fno-strict-aliasing}

post-patch:
	${REINPLACE_CMD} -e "s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/SConstruct
	${REINPLACE_CMD} -e "s|alsa_pcm|oss|g" ${WRKSRC}/templates/*.template

post-install:
	${CHOWN} -R 0:0 ${PREFIX}/lib/ardour2/
	${CHMOD} -R a+rX ${PREFIX}/lib/ardour2/
	${CHOWN} -R 0:0 ${PREFIX}/etc/ardour2/
	${CHMOD} -R a+rX ${PREFIX}/etc/ardour2/
	${CHOWN} -R 0:0 ${PREFIX}/share/ardour2/
	${CHMOD} -R a+rX ${PREFIX}/share/ardour2/
	${MKDIR} ${TEMPLATESDIR}
	${INSTALL_DATA} ${WRKSRC}/templates/*.template ${TEMPLATESDIR}/

.include <bsd.port.post.mk>
