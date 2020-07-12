# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	xmp
PORTVERSION=	4.1.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Player for many different Amiga and PC module formats

LICENSE=	GPLv2

LIB_DEPENDS=	libxmp.so:audio/libxmp

USES=		gmake localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc

CONFIG_FILES=	xmp.conf modules.conf

OPTIONS_DEFAULT=	OSS
OPTIONS_DEFINE=	ALSA OSS PULSEAUDIO SNDIO

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CONFIGURE_ENABLE=	alsa

OSS_CONFIGURE_ENABLE=	oss

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

post-patch:
	@${REINPLACE_CMD} -e 's|\ install-conf||' ${WRKSRC}/Makefile.in

post-patch-SNDIO-on:
	@${REINPLACE_CMD} -e 's|openbsd\*)|\*)|' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for f in ${CONFIG_FILES}
	@test -f ${ETCDIR}/${f} || ${INSTALL_DATA} ${WRKSRC}/src/${f} ${STAGEDIR}${ETCDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

.include <bsd.port.mk>
