# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	zynaddsubfx
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	ZynAddSubFX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A realtime software synthesizer

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		fftw3:${PORTSDIR}/math/fftw3 \
		expat.6:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	${LOCALBASE}/include/mxml.h:${PORTSDIR}/textproc/mxml

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_BZIP2=	yes
USE_GMAKE=	yes
CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	ALSAMIDI GUI
OPTIONS_DEFAULT=	GUI
ALSAMIDI_DESC=		midi input through ALSA
OPTIONS_RADIO=	OUTPUT
OPTIONS_RADIO_OUTPUT=	JACK PORTAUDIO
OUTPUT_DESC=	Audio output type

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSAMIDI}
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	portaudio.0:${PORTSDIR}/audio/portaudio
.endif

.if !defined(WITHOUT_GUI)
LIB_DEPENDS+=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64: invokes i386 asm
.endif

post-patch:
	${REINPLACE_CMD} -e \
		's|CXXFLAGS= -O2 -Wall -g -fPIC|CXXFLAGS=${CXXFLAGS}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		's|LIBS= -lm  -lmxml -lz|LIBS= -lm  -lmxml -lz -L${LOCALBASE}/lib|g' \
		${WRKSRC}/Makefile

.if ! ${PORT_OPTIONS:MALSAMIDI}
	${REINPLACE_CMD} -e 's|LINUX_MIDIIN=ALSA|LINUX_MIDIIN=OSS|g' \
		${WRKSRC}/Makefile.inc
.endif
.if ${PORT_OPTIONS:MJACK}
	${REINPLACE_CMD} -e 's|LINUX_AUDIOOUT=OSS|LINUX_AUDIOOUT=OSS_AND_JACK|g' \
		${WRKSRC}/Makefile.inc
.endif
.if ${PORT_OPTIONS:MPORTAUDIO}
	${REINPLACE_CMD} -e 's|LINUX_AUDIOOUT=OSS|LINUX_AUDIOOUT=PA|g' \
		${WRKSRC}/Makefile.inc
.endif
.if ! ${PORT_OPTIONS:MGUI}
	${REINPLACE_CMD} -e 's|DISABLE_GUI=NO|DISABLE_GUI=YES|g' \
		${WRKSRC}/Makefile.inc
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/zynaddsubfx ${PREFIX}/bin
		${MKDIR} ${DATADIR}
		${MKDIR} ${DATADIR}/banks
		cd ${WRKDIR}/${DISTNAME}/banks && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/banks/{} \;
		cd ${WRKDIR}/${DISTNAME}/banks && ${FIND} . -type f \
			-exec ${INSTALL_DATA} {} ${DATADIR}/banks/{} \;

.include <bsd.port.mk>
