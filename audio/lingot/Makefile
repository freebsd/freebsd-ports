# Created by: Bartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	lingot
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	coder@tuxfamily.org
COMMENT=	LINGOT is a musical instrument tuner

LICENSE=	GPLv2

USE_GNOME=	gtk20 intltool libglade2
GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig

CONFIGURE_ENV=	DATADIRNAME="share"
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		SOUND
OPTIONS_GROUP_SOUND=	ALSA JACK
OPTIONS_DEFAULT=	JACK

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CONFIGURE_ENABLE=	alsa

JACK_LIB_DEPENDS=	libjack.so:audio/jack \
			libsamplerate.so:audio/libsamplerate
JACK_CONFIGURE_ENABLE=	jack

.include <bsd.port.mk>
