# New ports collection makefile for:	pure-gtk
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-audio
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	A digital audio interface for the Pure language

LIB_DEPENDS+=	pure.7:${PORTSDIR}/lang/pure \
		portaudio.2:${PORTSDIR}/audio/portaudio2 \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		fftw3:${PORTSDIR}/math/fftw3

#RUN_DEPENDS+=	${LOCALBASE}/lib/pure/ffi.pure:${PORTSDIR}/devel/pure-ffi

LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes

MAKE_ARGS+=	prefix=${PREFIX} CPPFLAGS+=-I${LOCALBASE}/include LDFLAGS+=-L${LOCALBASE}/lib CFLAGS="${CFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s|-lportaudio|-I${LOCALBASE}/include/portaudio2 -L${LOCALBASE}/lib/portaudio2 -lportaudio|" \
		-e "s|portaudio.h|portaudio2/portaudio.h|g" \
	   	${WRKSRC}/Makefile

PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
