# New ports collection makefile for:	espeak
# Date created:		2006-03-25
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	espeak
PORTVERSION=	1.46.02
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A software speech synthesizer

# default is runtime audio detection
LIB_DEPENDS=	${PORTAUDIOLIB} \
		${PULSEAUDIOLIB}

PULSEAUDIOLIB=	pulse:${PORTSDIR}/audio/pulseaudio
PORTAUDIOLIB=	portaudio:${PORTSDIR}/audio/portaudio

.if (!defined(WITH_PULSEAUDIO) && !defined(WITH_PORTAUDIO)) || (defined(WITH_PULSEAUDIO) && defined(WITH_PORTAUDIO))
AUDIO=	"runtime"
.elif defined(WITH_PULSEAUDIO)
AUDIO=	"pulseaudio"
PORTAUDIOLIB=
.else
AUDIO=	"portaudio"
PULSEAUDIOLIB=
.endif

CONFLICTS=	speak-1.[0-9]

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		AUDIO="${AUDIO}"

CXXFLAGS+=	-I${LOCALBASE}/include
USE_GMAKE=	yes
USE_GCC=	4.2+
USE_LDCONFIG=	yes
USE_ZIP=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

REINPLACE_FILES=	Makefile speech.h
REINPLACE_ARGS=	-i.bak -e "s|%%DATADIR%%|${DATADIR}|g"

post-patch:
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} ${REINPLACE_FILES}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
