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
LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libjack.so:${PORTSDIR}/audio/jack \
		liblo.so:${PORTSDIR}/audio/liblo \
		librubberband.so:${PORTSDIR}/audio/rubberband \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsigc-1.2.so:${PORTSDIR}/devel/libsigc++12 \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libvamp-sdk.so:${PORTSDIR}/audio/vamp-plugin-sdk
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
NO_STAGE=	yes
USE_WX=		2.6+
WX_UNICODE=	yes
CONFIGURE_ARGS=	-with-wxconfig-path=${WX_CONFIG}
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_GNOME=	libxml2

.include <bsd.port.mk>
