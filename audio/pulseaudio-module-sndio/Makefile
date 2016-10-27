# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	pulseaudio-module-sndio
PORTVERSION=	9.0
CATEGORIES=	audio

MAINTAINER=	t@tobik.me
COMMENT=	Sndio module for PulseAudio

LICENSE=	ISCL

LIB_DEPENDS+=	libsndio.so:audio/sndio \
		libpulse.so:audio/pulseaudio

USES=		pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	t6

MAKE_ARGS=	STAGEDIR="${STAGEDIR}"

PULSE_MODDIR=	`pkg-config --variable=modlibexecdir libpulse`
PLIST_FILES=	${PULSE_MODDIR}/module-sndio.so

.include <bsd.port.mk>
