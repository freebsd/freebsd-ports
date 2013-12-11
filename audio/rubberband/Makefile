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
LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libvamp-sdk.so:${PORTSDIR}/audio/vamp-plugin-sdk \
		libfftw3.so:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USES=		gmake pkgconfig
NO_STAGE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
