# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	linuxsampler
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular MIDI sampler

LIB_DEPENDS=	gig:${PORTSDIR}/audio/libgig

RESTRICTED=	no commercial use

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported"

OPTIONS_DEFINE=	JACK ALSA DSSI LV2CORE
OPTIONS_DEFAULT=	JACK
DSSI_DESC=	Enable DSSI support
LV2CORE_DESC=	Enable LV2 support

USE_BZIP2=	yes
USES=		gmake pathfix pkgconfig
USE_SQLITE=	3
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	HAVE_UNIX98=1
USE_LDCONFIG=	yes

MAN1=		linuxsampler.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--disable-arts-driver

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=--disable-jack-driver
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
.else
CONFIGURE_ARGS+=--disable-alsa-driver
.endif

.if ${PORT_OPTIONS:MDSSI}
BUILD_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
RUN_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
PLIST_SUB+=	DSSI=""
.else
CONFIGURE_ENV+=	ac_cv_header_dssi_h=no
PLIST_SUB+=	DSSI="@comment "
.endif

.if ${PORT_OPTIONS:MLV2CORE}
BUILD_DEPENDS+=	lv2core>=0:${PORTSDIR}/audio/lv2core
RUN_DEPENDS+=	lv2core>=0:${PORTSDIR}/audio/lv2core
PLIST_SUB+=	LV2CORE=""
.else
CONFIGURE_ENV+=	ac_cv_header_lv2_h=no
PLIST_SUB+=	LV2CORE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|CXX_CPU_SWITCH=.*|CXX_CPU_SWITCH=|g ; \
		 s|"lv2core"|"_lv2core_"|' ${WRKSRC}/configure

post-install:
	@${TOUCH} ${PREFIX}/lib/linuxsampler/plugins/.keep_me

.include <bsd.port.mk>
