# New ports collection makefile for:	jamin
# Date created:		2006-12-06
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	jamin
PORTVERSION=	0.95.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jamin

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	JACK Audio Mastering interface

LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float \
		jack.0:${PORTSDIR}/audio/jack \
		lo.7:${PORTSDIR}/audio/liblo
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		${LOCALBASE}/lib/ladspa/fast_lookahead_limiter_1913.so:${PORTSDIR}/audio/swhplugins
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libxml2

MAN1=		jamin.1

.include <bsd.port.mk>
