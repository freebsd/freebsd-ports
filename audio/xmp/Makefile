# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	xmp
PORTVERSION=	4.0.7
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Player for many different Amiga and PC module formats

LICENSE=	GPLv2

LIB_DEPENDS=	libxmp.so:${PORTSDIR}/audio/libxmp

USES=		pkgconfig gmake
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIG_FILES=	xmp.conf modules.conf

OPTIONS_DEFINE=	ALSA PULSEAUDIO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CONFIGURE_ARGS+=	--enable-alsa
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse-simple.so:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--enable-pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\ install-conf||' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for f in ${CONFIG_FILES}
	@test -f ${ETCDIR}/${f} || ${INSTALL_DATA} ${WRKSRC}/src/${f} ${STAGEDIR}${ETCDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

.include <bsd.port.mk>
