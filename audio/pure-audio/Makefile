# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-audio
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Digital audio interface for the Pure language

LICENSE=	BSD

LIB_DEPENDS=	portaudio.2:${PORTSDIR}/audio/portaudio2 \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		sndfile:${PORTSDIR}/audio/libsndfile \
		fftw3:${PORTSDIR}/math/fftw3

USES=		pure
NO_STAGE=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e "s|-lportaudio|-I${LOCALBASE}/include/portaudio2 -L${LOCALBASE}/lib/portaudio2 -lportaudio|" \
		-e "s|portaudio.h|portaudio2/portaudio.h|g" \
			${WRKSRC}/Makefile

PORTDOCS=	README

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
