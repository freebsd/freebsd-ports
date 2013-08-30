# Created by: mathias.picker@gmx.de
# $FreeBSD$

PORTNAME=	rubberband
PORTVERSION=	1.7.0
CATEGORIES=	audio
MASTER_SITES=	http://code.breakfastquay.com/attachments/download/23/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Vamp audio analysis plugin SDK

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		vamp-sdk.2:${PORTSDIR}/audio/vamp-plugin-sdk \
		fftw3.6:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USES=		gmake pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
