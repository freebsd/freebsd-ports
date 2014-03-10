# $FreeBSD$

PORTNAME=	growl-for-linux
PORTVERSION=	0.6.9
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Notification system compatible with Growl

LICENSE=	BSD

BUILD_DEPENDS=	desktop-file-install:${PORTSDIR}/devel/desktop-file-utils
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

GH_ACCOUNT=	mattn
GH_COMMIT=	ac7c8cd
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	LIBNOTIFY
OPTIONS_DEFAULT=	LIBNOTIFY
LIBNOTIFY_DESC=	Use notify-osd for libnotify display plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	notify-osd>=0.9.29_3:${PORTSDIR}/deskutils/notify-osd
.endif

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,^${PREFIX}/,,}

USE_AUTOTOOLS=	autoconf:env automake:env libtoolize:env
USE_GITHUB=	yes
USE_GCC=	any
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_SQLITE=	3
USES=		pkgconfig

WITH_OPENSSL_PORT=	yes

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} ; ${SETENV} ${CONFIGURE_ENV} ${SH} autogen.sh)

.include <bsd.port.mk>
