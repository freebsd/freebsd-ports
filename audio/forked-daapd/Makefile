# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	forked-daapd
PORTVERSION=	24.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	DAAP (iTunes), MPD (Music Player Daemon) and RSP (Roku) media server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	antlr3:devel/antlr3
LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libavahi-client.so:net/avahi-app \
		libavcodec.so:multimedia/ffmpeg \
		libconfuse.so:devel/libconfuse \
		libevent.so:devel/libevent2 \
		libgcrypt.so:security/libgcrypt \
		libinotify.so:devel/libinotify \
		libmxml.so:textproc/mxml \
		libunistring.so:devel/libunistring

USE_GITHUB=	yes
GH_ACCOUNT=	ejurgensen

USES=		autoreconf gettext gmake gperf iconv libtool localbase pathfix pkgconfig sqlite

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	${LOCALBASE}/lib/forked-daapd
CONFIGURE_ARGS+=--localstatedir=/var

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

USERS=		daapd
GROUPS=		daapd

OPTIONS_DEFINE=	ALSA ITUNES LASTFM MPD
OPTIONS_DEFAULT=ITUNES LASTFM MPD

ITUNES_DESC=	iTunes XML support
MPD_DESC=	Music Player Daemon protocol support

ALSA_CONFIGURE_WITH=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ITUNES_CONFIGURE_ENABLE=itunes
ITUNES_LIB_DEPENDS=	libplist.so:devel/libplist
LASTFM_CONFIGURE_ENABLE=lastfm
LASTFM_LIB_DEPENDS=	libcurl.so:ftp/curl
MPD_CONFIGURE_ENABLE=	mpd

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/forked-daapd.conf ${STAGEDIR}${PREFIX}/etc/forked-daapd.conf.sample

.include <bsd.port.mk>
