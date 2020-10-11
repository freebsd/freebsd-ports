# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	forked-daapd
DISTVERSION=	27.2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/ejurgensen/forked-daapd/releases/download/${DISTVERSION}/

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	DAAP (iTunes), MPD (Music Player Daemon) and RSP (Roku) media server

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
		libgcrypt.so:security/libgcrypt \
		libinotify.so:devel/libinotify \
		libmxml.so:textproc/mxml \
		libplist.so:devel/libplist \
		libsodium.so:security/libsodium \
		libunistring.so:devel/libunistring \
		libwebsockets.so:net/libwebsockets

USES=		gnome gmake gperf iconv:wchar_t libtool localbase pathfix \
		pkgconfig sqlite tar:xz
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

USERS=		daapd
GROUPS=		daapd

OPTIONS_DEFINE=		ALSA ITUNES MPD PULSEAUDIO
OPTIONS_DEFAULT=	ITUNES MPD

ITUNES_DESC=		iTunes XML support
MPD_DESC=		Music Player Daemon protocol support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_WITH=	alsa

ITUNES_CONFIGURE_ENABLE=	itunes

MPD_CONFIGURE_ENABLE=		mpd

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/forked-daapd/forked-daapd-sqlext.so
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc/forked-daapd
	@${MV} ${STAGEDIR}${PREFIX}/etc/forked-daapd.conf ${STAGEDIR}${PREFIX}/etc/forked-daapd.conf.sample

.include <bsd.port.mk>
