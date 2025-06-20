PORTNAME=	pragha
PORTVERSION=	1.3.3
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	https://github.com/pragha-music-player/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight music player
WWW=		https://pragha-music-player.github.io/

LICENSE=	GPLv3

LIB_DEPENDS=	libtag.so:audio/taglib \
	libpeas-1.0.so:devel/libpeas1 \
	libnotify.so:devel/libnotify \
	libkeybinder-3.0.so:x11/keybinder-gtk3 \
	libsoup-2.4.so:devel/libsoup \
	libtotem-plparser.so:multimedia/totem-pl-parser

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome gstreamer \
		libtool pkgconfig sqlite tar:bz2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GNOME=	glib20 gtk30 intltool intlhack
USE_GSTREAMER=	faad flac libav mpg123 ogg speex
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-Wno-typedef-redefinition

CONFIGURE_ARGS=--disable-libglyr \
	--disable-gudev-1.0 \
	--disable-libmtp \
	--disable-rygel-server-2.2 \
	--disable-grilo-0.2 \
	--disable-libclastfm \
	--enable-taglib  \
	--enable-totem-plparser \
	--disable-libxfce4ui

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

.include <bsd.port.mk>
