# $FreeBSD$

PORTNAME=	growl-for-linux
PORTVERSION=	0.6.9
PORTREVISION=	4
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Notification system compatible with Growl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	desktop-file-install:${PORTSDIR}/devel/desktop-file-utils
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

GH_ACCOUNT=	mattn
GH_COMMIT=	ac7c8cd
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"
USES=		compiler:nestedfct libtool pkgconfig
USE_AUTOTOOLS=	libtoolize aclocal autoconf automake
AUTOMAKE_ARGS=	-a -c -f
USE_GITHUB=	yes
USE_GNOME=	gtk20
USE_OPENSSL=	yes
USE_SQLITE=	3

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,^${PREFIX}/,,}

OPTIONS_DEFINE=	LIBNOTIFY
OPTIONS_DEFAULT=LIBNOTIFY

LIBNOTIFY_DESC=		Use notify-osd for libnotify display plugin
LIBNOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
LIBNOTIFY_RUN_DEPENDS=	notify-osd>=0.9.29_3:${PORTSDIR}/deskutils/notify-osd

post-patch:
	@${REINPLACE_CMD} '/^gol_LDADD =/s/$$/ -lgmodule-2.0/' \
		${WRKSRC}/Makefile.am

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libgolplug.a

.include <bsd.port.mk>
