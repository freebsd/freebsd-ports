# New ports collection makefile for:	musescore
# Date created:		28 Jul 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	musescore
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	SF/mscore/mscore/MuseScore-${PORTVERSION}
DISTNAME=	mscore-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free music composition & notation software

LIB_DEPENDS=	asound.2:${PORTSDIR}/audio/alsa-lib \
		sndfile.1:${PORTSDIR}/audio/libsndfile

CONFLICTS=	qtscriptgenerator-[0-9]*

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network svg xml script scripttools designer webkit \
		qmake_build moc_build uic_build linguist_build rcc_build
MAKE_JOBS_SAFE=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/mscore
CMAKE_OUTSOURCE=	yes

ALL_TARGET=	lrelease all

OPTIONS=	JACK "Jack support" on \
		PORTAUDIO "Portaudio support" on

.include <bsd.port.options.mk>

.if ${OSVERSION} < 802502 || ( ${OSVERSION} >= 900000 && ${OSVERSION} < 900027 )
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-log2
.endif

.if !defined(WITHOUT_JACK)
CMAKE_ARGS+=	-DBUILD_JACK:BOOL=ON
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CMAKE_ARGS+=	-DBUILD_JACK:BOOL=OFF
.endif

.if !defined(WITHOUT_PORTAUDIO)
LIB_DEPENDS+=	portaudio.2:${PORTSDIR}/audio/portaudio2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include/freetype2|${LOCALBASE}/include/freetype2|; \
		s|-lfreetype|${LOCALBASE}/lib/libfreetype.so|' \
		${WRKSRC}/mscore/mscore/CMakeLists.txt
	@${FIND} ${WRKSRC} -name CMakeLists.txt -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e \
		'/set(CMAKE_CXX_FLAGS/ { s|-g||; /$${CMAKE_CXX_FLAGS}/ ! s|"|&$${CMAKE_CXX_FLAGS} |; }'
.if defined(WITHOUT_PORTAUDIO)
	@${REINPLACE_CMD} -e '/PKGCONFIG.*portaudio/ d' ${WRKSRC}/mscore/CMakeLists.txt
.endif

post-install:
	@${ECHO}; ${CAT} ${PKGMESSAGE}; ${ECHO}

.include <bsd.port.mk>
