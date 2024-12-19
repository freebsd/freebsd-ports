PORTNAME=	shairport-sync
DISTVERSION=	4.3.7
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AirPlay audio player with multi-room audio synchronisation capability
WWW=		https://github.com/mikebrady/shairport-sync

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libconfig.so:devel/libconfig \
		libdaemon.so:devel/libdaemon \
		libpopt.so:devel/popt \
		libsoxr.so:audio/libsoxr

USES=		autoreconf libtool localbase pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	mikebrady
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc \
		--with-avahi \
		--with-libdaemon \
		--with-metadata \
		--with-piddir=/var/run/shairport-sync \
		--with-pipe \
		--with-soxr \
		--with-ssl=openssl \
		--with-stdout
CONFIGURE_ENV+=	SSL_CFLAGS=-I${OPENSSLINC} \
		SSL_LIBS=-L${OPENSSLLIB}

LDFLAGS+=	-lcrypto

OPTIONS_DEFINE=		AIRPLAY2 ALAC ALSA MQTT PULSEAUDIO SNDIO
OPTIONS_DEFAULT=	AIRPLAY2 SNDIO
AIRPLAY2_DESC=		Build with AirPlay 2 protocol support
ALAC_DESC=		Build with libalac support (experimental)
MQTT_DESC=		Build with MQTT protocol support

AIRPLAY2_BUILD_DEPENDS=	vim:editors/vim
AIRPLAY2_LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
			libgcrypt.so:security/libgcrypt \
			libplist-2.0.so:devel/libplist \
			libsodium.so:security/libsodium \
			libuuid.so:misc/libuuid
AIRPLAY2_RUN_DEPENDS=	nqptp:net/nqptp
AIRPLAY2_CONFIGURE_ON=	--with-airplay-2
AIRPLAY2_SUB_FILES=	pkg-message

ALAC_LIB_DEPENDS=	libalac.so:audio/alac
ALAC_CONFIGURE_ON=	--with-apple-alac

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ON=	--with-alsa

MQTT_LIB_DEPENDS=	libmosquitto.so:net/mosquitto
MQTT_CONFIGURE_ON=	--with-mqtt-client

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=	--with-pa

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ON=	--with-sndio

post-patch:
	@${REINPLACE_CMD} -e 's/-Wno-clobbered -Wno-psabi //' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
