# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	linuxsampler
DISTVERSION=	2.1.1
CATEGORIES=	audio
MASTER_SITES=	https://download.linuxsampler.org/packages/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular MIDI sampler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	"not yet ported"

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libgig.so:audio/libgig \
		libsndfile.so:audio/libsndfile \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		bison:wrapper gmake libtool pathfix pkgconfig sqlite:3 tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	HAVE_UNIX98=1
USE_LDCONFIG=	${PREFIX}/lib/linuxsampler
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=	--disable-arts-driver

OPTIONS_DEFINE=		JACK ALSA DSSI LV2
OPTIONS_DEFAULT=	JACK
OPTIONS_SUB=	yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack-driver

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa-driver

DSSI_DESC=		Enable DSSI support
DSSI_BUILD_DEPENDS=	dssi>0:audio/dssi
DSSI_CPPFLAGS=	-I${LOCALBASE}/include/dssi

LV2_DESC=		Enable LV2 support
LV2_BUILD_DEPENDS=	lv2>0:audio/lv2
LV2_CONFIGURE_ENV_OFF=	ac_cv_header_lv2_h=no

post-patch:
	@${REINPLACE_CMD} -e \
		's|CXX_CPU_SWITCH=.*|CXX_CPU_SWITCH=|g ; \
		 s|"lv2core"|"_lv2core_"|' ${WRKSRC}/configure

post-install:
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/linuxsampler/plugins/.keep_me

.include <bsd.port.mk>
