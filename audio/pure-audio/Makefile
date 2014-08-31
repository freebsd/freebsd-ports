# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-audio
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digital audio interface for the Pure language

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libportaudio.so.2:${PORTSDIR}/audio/portaudio2 \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libfftw3.so:${PORTSDIR}/math/fftw3

USES=		pure

post-patch:
	@${REINPLACE_CMD} \
		-e "s|-lportaudio|-I${LOCALBASE}/include/portaudio2 -L${LOCALBASE}/lib/portaudio2 -lportaudio|" \
		-e "s|portaudio.h|portaudio2/portaudio.h|g" \
			${WRKSRC}/Makefile

PORTDOCS=	README
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
