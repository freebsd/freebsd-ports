# Created by: mathias.picker@gmx.de
# $FreeBSD$

PORTNAME=	sooperlooper
PORTVERSION=	1.6.18
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://essej.net/sooperlooper/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Vamp audio analysis plugin SDK

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	fftw3.6:${PORTSDIR}/math/fftw3 \
		jack.0:${PORTSDIR}/audio/jack \
		lo:${PORTSDIR}/audio/liblo \
		rubberband.2:${PORTSDIR}/audio/rubberband \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		vamp-sdk.2:${PORTSDIR}/audio/vamp-plugin-sdk
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GMAKE=	yes
USE_WX=		2.6+
WX_UNICODE=	yes
CONFIGURE_ARGS=	-with-wxconfig-path=${WX_CONFIG}
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_GNOME=	libxml2

.include <bsd.port.mk>
