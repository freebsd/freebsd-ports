# Created by: mathias.picker@gmx.de
# $FreeBSD$

PORTNAME=	rubberband
PORTVERSION=	1.8.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://breakfastquay.com/files/releases/23/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vamp audio analysis plugin SDK

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate \
		libvamp-sdk.so:audio/vamp-plugin-sdk \
		libfftw3.so:math/fftw3
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

USES=		gmake pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rubberband
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librubberband.so.[0-9].*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ladspa/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/vamp/*.so

.include <bsd.port.mk>
