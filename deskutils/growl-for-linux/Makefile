# $FreeBSD$

PORTNAME=	growl-for-linux
PORTVERSION=	0.6.8
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Notification system compatible with Growl

LICENSE=	BSD

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

GH_ACCOUNT=	mattn
GH_COMMIT=	cab80f2
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	LIBNOTIFY
OPTIONS_DEFAULT=	LIBNOTIFY
LIBNOTIFY_DESC=	Use notify-osd for libnotify display plugin

USES=		pkgconfig

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	notify-osd>=0.9.29_3:${PORTSDIR}/deskutils/notify-osd
.endif

PLIST_SUB=	DESKTOPDIR=${_DESKTOPDIR_REL}

USE_AUTOTOOLS=	autoconf:env automake:env libtoolize:env
USE_GITHUB=	yes
USE_GNOME=	desktopfileutils gtk20
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_SQLITE=	3

WITH_OPENSSL_PORT=	yes

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} ; ${SETENV} ${CONFIGURE_ENV} ${SH} autogen.sh)

.include <bsd.port.mk>
