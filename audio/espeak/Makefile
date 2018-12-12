# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	espeak
PORTVERSION=	1.48.04
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Software speech synthesizer

LICENSE=	GPLv3

CONFLICTS=	speak-1.[0-9]

USES=		gmake zip
USE_LDCONFIG=	yes
USE_CXXSTD=	gnu++98
CXXFLAGS+=	-I${LOCALBASE}/include

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	PORTAUDIO
OPTIONS_RADIO=	AUDIO_SYSTEM
OPTIONS_RADIO_AUDIO_SYSTEM=	PORTAUDIO PULSEAUDIO RUNTIME
RUNTIME_DESC=	Sound interface selected at runtime

PORTAUDIOLIB=	libportaudio.so:audio/portaudio
PULSEAUDIOLIB=	libpulse.so:audio/pulseaudio

PORTAUDIO_LIB_DEPENDS=	${PORTAUDIOLIB}
PULSEAUDIO_LIB_DEPENDS=	${PULSEAUDIOLIB}
RUNTIME_LIB_DEPENDS=	${PORTAUDIOLIB} \
			${PULSEAUDIOLIB}

PULSEAUDIO_USES=	compiler:c++0x
RUNTIME_USES=		compiler:c++0x

PULSEAUDIO_MAKE_ENV=	AUDIO="pulseaudio"
PORTAUDIO_MAKE_ENV=	AUDIO="portaudio"
RUNTIME_MAKE_ENV=	AUDIO="runtime"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Makefile ${WRKSRC}/src/speech.h
	@${MV} ${WRKSRC}/src/portaudio19.h ${WRKSRC}/src/portaudio.h
.if ${ARCH} == sparc64	# cf. http://seclists.org/tcpdump/2012/q4/112
	@${REINPLACE_CMD} -e 's|-fpic|-fPIC|' ${WRKSRC}/src/Makefile
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libespeak.so*

.include <bsd.port.post.mk>
