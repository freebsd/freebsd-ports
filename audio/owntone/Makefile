PORTNAME=	owntone
DISTVERSION=	29.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/owntone/owntone-server/releases/download/${DISTVERSION}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	DAAP (iTunes), MPD (Music Player Daemon) and RSP (Roku) media server
WWW=		https://github.com/owntone/owntone-server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libavcodec.so:multimedia/ffmpeg \
		libconfuse.so:devel/libconfuse \
		libcurl.so:ftp/curl \
		libevent_pthreads.so:devel/libevent \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libgpg-error.so:security/libgpg-error \
		libjson-c.so:devel/json-c \
		libinotify.so:devel/libinotify \
		libmxml.so:textproc/mxml \
		libplist-2.0.so:devel/libplist \
		libsodium.so:security/libsodium \
		libunistring.so:devel/libunistring \
		libprotobuf-c.so:devel/protobuf-c \
		libuuid.so:misc/libuuid

USES=		tar:xz localbase libtool iconv:wchar_t pkgconfig gnome gmake \
		gperf sqlite gnome
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-install_systemd \
		--with-owntone-user=${OWNTONE_USER} \
		--with-owntone-group=${OWNTONE_USER}
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

OWNTONE_USER?=	daapd
USERS?=		daapd
GROUPS?=	daapd

OPTIONS_DEFINE=		ITUNES MPD AIRPLAY2 CHROMECAST WEBINTERFACE \
			ALSA PULSEAUDIO NLS DOCS
OPTIONS_DEFAULT=	ITUNES MPD AIRPLAY2 CHROMECAST WEBINTERFACE \
			ALSA NLS DOCS
NO_OPTIONS_SORT=yes
OPTIONS_SUB=yes

AIRPLAY2_DESC=		Prefer AirPlay 2
ITUNES_DESC=		iTunes XML support
CHROMECAST_DESC=	Chromecast support
MPD_DESC=		Music Player Daemon protocol support
WEBINTERFACE_DESC=	Install web interface

AIRPLAY2_CONFIGURE_ENABLE=	preferairplay2

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_WITH=	alsa

ITUNES_CONFIGURE_ENABLE=	itunes

CHROMECAST_CONFIGURE_ENABLE=	chromecast

MPD_CONFIGURE_ENABLE=		mpd

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio

WEBINTERFACE_CONFIGURE_ENABLE=	webinterface
WEBINTERFACE_CONFIGURE_WITH=	libwebsockets
WEBINTERFACE_LIB_DEPENDS=	libwebsockets.so:net/libwebsockets

NLS_USES=			gettext-runtime
NLS_CONFIGURE_ENABLE=		nls

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/owntone/owntone-sqlext.so
	${MV} ${STAGEDIR}${PREFIX}/etc/owntone.conf \
		${STAGEDIR}${PREFIX}/etc/owntone.conf.sample

.include <bsd.port.mk>
