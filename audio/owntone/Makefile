PORTNAME=	owntone
DISTVERSION=	28.5
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/owntone/owntone-server/releases/download/${DISTVERSION}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	DAAP (iTunes), MPD (Music Player Daemon) and RSP (Roku) media server
WWW=		https://github.com/owntone/owntone-server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libavahi-client.so:net/avahi-app \
		libavcodec.so:multimedia/ffmpeg \
		libconfuse.so:devel/libconfuse \
		libcurl.so:ftp/curl \
		libevent_pthreads.so:devel/libevent \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libjson-c.so:devel/json-c \
		libinotify.so:devel/libinotify \
		libmxml.so:textproc/mxml \
		libplist-2.0.so:devel/libplist \
		libsodium.so:security/libsodium \
		libunistring.so:devel/libunistring \
		libwebsockets.so:net/libwebsockets \
		libprotobuf-c.so:devel/protobuf-c \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		tar:xz localbase libtool iconv:wchar_t pkgconfig gnome gmake gperf \
		sqlite gnome pathfix
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

USERS=		daapd
GROUPS=		daapd

OPTIONS_DEFINE=		ALSA ITUNES MPD PULSEAUDIO NLS DOCS
OPTIONS_DEFAULT=	ITUNES MPD NLS DOCS

ITUNES_DESC=		iTunes XML support
MPD_DESC=		Music Player Daemon protocol support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_WITH=	alsa

ITUNES_CONFIGURE_ENABLE=	itunes

MPD_CONFIGURE_ENABLE=		mpd

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio

NLS_USES=			gettext-runtime
NLS_CONFIGURE_ENABLE=		nls

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/owntone/owntone-sqlext.so
	${RM} ${STAGEDIR}${PREFIX}/etc/systemd/system/owntone.service
	${MV} ${STAGEDIR}${PREFIX}/etc/owntone.conf \
		${STAGEDIR}${PREFIX}/etc/owntone.conf.sample
	${REINPLACE_CMD} -i '' -e 's|uid = "owntone"|uid = "daapd"|' \
		${STAGEDIR}${PREFIX}/etc/owntone.conf.sample

.include <bsd.port.mk>
