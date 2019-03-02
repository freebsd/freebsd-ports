# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	fluidsynth-dssi
PORTVERSION=	1.0.0
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	SF/dssi/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for FluidSynth allowing it to function as a DSSI plugin

LIB_DEPENDS=	libdssialsacompat.so:audio/libdssialsacompat \
		liblo.so:audio/liblo \
		libfluidsynth.so:audio/fluidsynth \
		libjack.so:audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:audio/dssi

GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig
USE_GNOME=	gtk20

.include <bsd.port.mk>
