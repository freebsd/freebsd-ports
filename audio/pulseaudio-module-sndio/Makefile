PORTNAME=	pulseaudio-module-sndio
DISTVERSION=	13.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/t6/pulseaudio-module-sndio/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sndio module for PulseAudio

LICENSE=	ISCL LGPL21+
LICENSE_COMB=	multi

LIB_DEPENDS=	libsndio.so:audio/sndio \
		libpulse.so:audio/pulseaudio

USES=		pkgconfig
PULSE_MODDIR=	`pkg-config --variable=modlibexecdir libpulse`
PLIST_FILES=	${PULSE_MODDIR}/module-sndio.so
SUB_FILES=	pkg-message

.include <bsd.port.mk>
