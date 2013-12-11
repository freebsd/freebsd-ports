# Created by: Bartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	lingot
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	coder@tuxfamily.org
COMMENT=	LINGOT is a musical instrument tuner

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gtk20 libglade2
NO_STAGE=	yes
GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig

LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	JACK ALSA
OPTIONS_DEFAULT=	JACK

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-jack
.else
CONFIGURE_ARGS+=--disable-jack
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CONFIGURE_ARGS+=--enable-alsa
.else
CONFIGURE_ARGS+=--disable-alsa
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 802502 || (${OSVERSION} > 900000 && ${OSVERSION} < 900027)
EXTRA_PATCHES+=	${FILESDIR}/extra-lingot-config-scale.h
.endif

.include <bsd.port.post.mk>
