# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	pulseaudio-module-sndio
PORTVERSION=	8.0
CATEGORIES=	audio

MAINTAINER=	t@tobik.me
COMMENT=	Sndio module for PulseAudio

LICENSE=	ISCL

LIB_DEPENDS+=	libsndio.so:audio/sndio \
		libpulse.so:audio/pulseaudio

USES=		pkgconfig

PULSE_VERSION?=	${PORTVERSION}
PULSE_MODDIR=	${LOCALBASE}/lib/pulse-${PULSE_VERSION}/modules

USE_GITHUB=	yes
GH_ACCOUNT=	t6

MAKE_ARGS=	PULSE_VERSION="${PULSE_VERSION}" \
		PULSE_MODDIR="${PULSE_MODDIR}" \
		STAGEDIR="${STAGEDIR}"

PLIST_FILES=	${PULSE_MODDIR}/module-sndio.so

.include <bsd.port.mk>
