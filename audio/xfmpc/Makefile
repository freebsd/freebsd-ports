# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfmpc
PORTVERSION=	0.2.3
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Graphical MPD client focusing on low footprint

LICENSE=	GPLv2

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libmpd.so:audio/libmpd

INSTALLS_ICONS=	yes
USES=		gettext gmake pkgconfig tar:bzip2 xfce
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	libmenu
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
