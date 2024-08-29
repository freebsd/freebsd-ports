PORTNAME=	pulseaudio-module-sndio
DISTVERSION=	13.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	https://github.com/t6/pulseaudio-module-sndio/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sndio module for PulseAudio
WWW=		https://github.com/t6/pulseaudio-module-sndio

LICENSE=	ISCL LGPL21+
LICENSE_COMB=	multi

LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libsndio.so:audio/sndio

USES=		pkgconfig

SUB_FILES=	pkg-message
PLIST_FILES=	${PULSE_MODDIR}/module-sndio.so

PULSE_MODDIR=	`${LOCALBASE}/bin/pkg-config --variable=modlibexecdir libpulse`
PULSE_VERSION=	`${LOCALBASE}/bin/pkg-config --modversion libpulse`

post-patch:
	${REINPLACE_CMD} \
		-e "/^PA_MODULE_VERSION/s/0.0/${PULSE_VERSION}/1" \
		${WRKSRC}/module-sndio.c

.include <bsd.port.mk>
