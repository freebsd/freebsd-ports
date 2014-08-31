# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	jamin
PORTVERSION=	0.95.0
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JACK Audio Mastering interface

LIB_DEPENDS=	libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libjack.so:${PORTSDIR}/audio/jack \
		liblo.so:${PORTSDIR}/audio/liblo
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		${LOCALBASE}/lib/ladspa/fast_lookahead_limiter_1913.so:${PORTSDIR}/audio/swhplugins
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gmake libtool pkgconfig shared-mime-info
USE_GNOME=	gtk20 libxml2

.include <bsd.port.mk>
