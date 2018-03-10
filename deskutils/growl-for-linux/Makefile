# $FreeBSD$

PORTNAME=	growl-for-linux
PORTVERSION=	0.8.5
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Notification system compatible with Growl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	desktop-file-install:devel/desktop-file-utils
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

BROKEN_powerpc64=	fails to compile: balloon.c:160: error: nested functions are disabled, use -fnested-functions to re-enable

CONFIGURE_ARGS=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

GH_ACCOUNT=	mattn
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

LIBNOTIFY_DESC=		Use notify-osd for libnotify display plugin
LIBNOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
LIBNOTIFY_RUN_DEPENDS=	notify-osd>=0.9.29_3:deskutils/notify-osd

OPTIONS_DEFAULT=LIBNOTIFY
OPTIONS_DEFINE=	LIBNOTIFY

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,^${PREFIX}/,,}

USES=		autoreconf compiler:nestedfct libtool pkgconfig sqlite:3 ssl
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk20 libxml2
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}/display \
		${PREFIX}/lib/${PORTNAME}/subscribe
post-patch:
	@${REINPLACE_CMD} '/^gol_LDADD =/s/$$/ -lgmodule-2.0/' \
		${WRKSRC}/Makefile.am

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libgolplug.a

.include <bsd.port.mk>
