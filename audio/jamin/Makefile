# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	jamin
PORTVERSION=	0.95.0
PORTREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JACK Audio Mastering interface

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		liblo.so:audio/liblo
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa \
		${LOCALBASE}/lib/ladspa/fast_lookahead_limiter_1913.so:audio/swhplugins
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gmake gnome libtool pkgconfig \
		shared-mime-info
USE_GNOME=	gtk20 intltool libxml2

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ladspa/jamincont_1912.so

.include <bsd.port.mk>
