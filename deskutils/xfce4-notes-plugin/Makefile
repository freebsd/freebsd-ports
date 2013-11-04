# Created by: Thorsten Greiner <thorsten.greiner@web.de>
# $FreeBSD$

PORTNAME=	xfce4-notes-plugin
PORTVERSION=	1.7.7
PORTREVISION=	3
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Notes plugin for the Xfce panel

LICENSE=	GPLv2

LIB_DEPENDS=	libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext pkgconfig gmake
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	configenv libgui libutil panel xfconf
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
