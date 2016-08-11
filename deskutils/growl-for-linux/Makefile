# $FreeBSD$

PORTNAME=	growl-for-linux
PORTVERSION=	0.8.1
PORTREVISION=	0
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Notification system compatible with Growl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	desktop-file-install:devel/desktop-file-utils
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libdbus-glib-1.so:devel/dbus-glib

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

USES=		autoreconf compiler:nestedfct libtool pkgconfig sqlite:3
USE_GITHUB=	yes
USE_GNOME=	gtk20
USE_OPENSSL=	yes

post-patch:
	@${REINPLACE_CMD} '/^gol_LDADD =/s/$$/ -lgmodule-2.0/' \
		${WRKSRC}/Makefile.am

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libgolplug.a

.include <bsd.port.mk>
