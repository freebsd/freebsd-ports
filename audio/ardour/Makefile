# Created by: Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	ardour
PORTVERSION=	2.8.14
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multichannel digital audio workstation

LICENSE=	GPLv2

LIB_DEPENDS=	liblo.so:${PORTSDIR}/audio/liblo \
		liblrdf.so:${PORTSDIR}/textproc/liblrdf \
		libaubio.so:${PORTSDIR}/audio/aubio \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		libgnomecanvasmm-2.6.so:${PORTSDIR}/graphics/libgnomecanvasmm26

USE_BZIP2=	yes
USES=		gettext pkgconfig
USE_SCONS=	yes
SCONS_ENV+=	SYSLIBS=yes PREFIX=${PREFIX} NLS=yes
CFLAGS+=	-I${LOCALBASE}/include
USE_GNOME=	libxslt
USE_LDCONFIG=	${PREFIX}/lib/ardour2 ${PREFIX}/lib/ardour2/surfaces

RESTRICTED=	Redistribution of the VST PlugIns SDK is not allowed

PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS VST
VST_DESC=	VST plugins support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVST}
SCONS_ENV+=	VST=yes
BUILD_DEPENDS+=	winegcc:${PORTSDIR}/emulators/wine \
		unzip:${PORTSDIR}/archivers/unzip \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS+=	libwine.so:${PORTSDIR}/emulators/wine

PLIST_SUB+=	NO_VST="@comment "
PLIST_SUB+=	VST=""
.else
PLIST_SUB+=	NO_VST=""
PLIST_SUB+=	VST="@comment "
.endif

# Upstream uses these flags by default
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fomit-frame-pointer -ffast-math -fstrength-reduce
.  if ${ARCH} == "amd64"
SCONS_ENV+=	DIST_TARGET=x86_64
SCONS_ENV+=	FPU_OPTIMIZATION=1
.  elif ${MACHINE_CPU:Msse}
SCONS_ENV+=	DIST_TARGET=i686
SCONS_ENV+=	FPU_OPTIMIZATION=1
.  else
SCONS_ENV+=	DIST_TARGET=i386
SCONS_ENV+=	FPU_OPTIMIZATION=0
.  endif
.else
SCONS_ENV+=	FPU_OPTIMIZATION=0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}|' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|alsa_pcm|oss|g' ${WRKSRC}/templates/*.template

pre-build:
	@${MKDIR} ${STAGEDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ardour2/templates
	${INSTALL_DATA} ${WRKSRC}/templates/*.template \
		${STAGEDIR}${PREFIX}/share/ardour2/templates

.include <bsd.port.mk>
