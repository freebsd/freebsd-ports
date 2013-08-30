# Created by: ports@c0decafe.net <ports@c0decafe.net>
# $FreeBSD$
#

PORTNAME=	thunar-archive-plugin
PORTVERSION=	0.3.1
CATEGORIES=	archivers xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/thunar-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Archive plugin for the Thunar File Manager

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_XFCE=	configenv libexo thunar
USES=		gettext gmake pkgconfig
INSTALLS_ICONS=	yes
USE_GNOME=	intltool

.include <bsd.port.mk>
