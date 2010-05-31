# New ports collection makefile for:	xfce4-notifyd
# Date created:				22 Oct 2009
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-notifyd
PORTVERSION=	0.1.0
PORTREVISION=	5
CATEGORIES=	deskutils xfce
MASTER_SITES=	http://spuriousinterrupt.org/files/xfce4-notifyd/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Visually-appealing notification daemon for Xfce

LIB_DEPENDS=	sexy.2:${PORTSDIR}/x11-toolkits/libsexy \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	dbus-daemon:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool
USE_XFCE=	configenv libutil libgui
INSTALLS_ICONS=	yes

CONFLICTS=	notification-daemon-[0-9]* xfce4-notification-daemon-[0-9]*

OPTIONS=	NLS      "Enable Native Language Support"             on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch: .SILENT
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's|\(USE_NLS=\)yes|\1no|' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
