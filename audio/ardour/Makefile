# Created by: Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	ardour
PORTVERSION=	2.8.16
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multichannel digital audio workstation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to build

LIB_DEPENDS=	liblo.so:audio/liblo \
		liblrdf.so:textproc/liblrdf \
		libjack.so:audio/jack \
		libaubio.so:audio/aubio \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libboost_date_time.so:devel/boost-libs \
		libgnomecanvasmm-2.6.so:graphics/libgnomecanvasmm26

USES=		cpe gettext scons pkgconfig tar:bzip2
MAKE_ARGS+=	SYSLIBS=yes PREFIX=${PREFIX} NLS=yes
CFLAGS+=	-I${LOCALBASE}/include -DHAVE_AUBIO4
USE_GNOME=	libxslt
USE_LDCONFIG=	${PREFIX}/lib/ardour2 ${PREFIX}/lib/ardour2/surfaces

PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS VST
VST_DESC=	VST plugins support

BROKEN_powerpc64=	Does not build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVST}
MAKE_ARGS+=	VST=yes
LIB_DEPENDS+=	libwine.so:emulators/wine
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
MAKE_ARGS+=	DIST_TARGET=x86_64
MAKE_ARGS+=	FPU_OPTIMIZATION=1
.  elif ${MACHINE_CPU:Msse}
MAKE_ARGS+=	DIST_TARGET=i686
MAKE_ARGS+=	FPU_OPTIMIZATION=1
.  else
MAKE_ARGS+=	DIST_TARGET=i386
MAKE_ARGS+=	FPU_OPTIMIZATION=0
.  endif
.else
MAKE_ARGS+=	FPU_OPTIMIZATION=0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}|' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|alsa_pcm|oss|g' ${WRKSRC}/templates/*.template
	@${REINPLACE_CMD} -e 's|std::pair<double|std::pair<const double|' \
		${WRKSRC}/gtk2_ardour/tempo_lines.h

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ardour2/templates
	${INSTALL_DATA} ${WRKSRC}/templates/*.template \
		${STAGEDIR}${PREFIX}/share/ardour2/templates

.include <bsd.port.mk>
