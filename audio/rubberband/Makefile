# Created by: mathias.picker@gmx.de
# $FreeBSD$

PORTNAME=	rubberband
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://breakfastquay.com/files/releases/23/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vamp audio analysis plugin SDK

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libvamp-sdk.so:${PORTSDIR}/audio/vamp-plugin-sdk \
		libfftw3.so:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USES=		gmake pkgconfig tar:bzip2
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
