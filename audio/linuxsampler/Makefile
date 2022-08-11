PORTNAME=	linuxsampler
DISTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://download.linuxsampler.org/packages/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular MIDI sampler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to this architecture

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libgig.so:audio/libgig \
		libsndfile.so:audio/libsndfile \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		bison:wrapper compiler:c++14-lang gmake libtool localbase pathfix pkgconfig sqlite:3 tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/linuxsampler

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	HAVE_UNIX98=1
CONFIGURE_ARGS=	--disable-arts-driver

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		JACK ALSA
OPTIONS_DEFAULT=	JACK
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa-driver
ALSA_BROKEN=		error: unknown type name 'snd_pcm_t'

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack-driver

CONFLICTS_BUILD=	dssi # DSSI is a no-longer-maintained interface to obsolete LADSPA plugins - no need to pull DSSI and LADSPA into dependencies

post-patch:
	@${REINPLACE_CMD} -e \
		's|CXX_CPU_SWITCH=.*|CXX_CPU_SWITCH=|g ; \
		 s|"lv2core"|"_lv2core_"|' ${WRKSRC}/configure

post-install:
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/linuxsampler/plugins/.keep_me

.include <bsd.port.mk>
