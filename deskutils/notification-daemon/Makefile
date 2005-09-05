# New ports collection makefile for:	notification-daemon
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	notification-daemon
PORTVERSION=	0.2.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.galago.info/files/releases/source/notification-daemon/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	andreas@syndrom23.de
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	dbus-1.1:${PORTSDIR}/devel/dbus \
		notify.0:${PORTSDIR}/devel/libnotify

USE_GNOME=	gnomehack gnometarget intlhack gtk20
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-main.cc
.endif

.include <bsd.port.post.mk>
