# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfmpc
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Graphical MPD client focusing on low footprint

LICENSE=	GPLv2

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libmpd.so:audio/libmpd

USES=		compiler:c11 gettext-tools gmake gnome pkgconfig tar:bzip2 \
		xfce xorg
USE_GNOME=	cairo gtk30 intltool
USE_XFCE=	libmenu
USE_XORG=	ice sm x11

INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
