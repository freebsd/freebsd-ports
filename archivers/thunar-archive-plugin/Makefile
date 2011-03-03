# New ports collection makefile for:	thunar-archive-plugin
# Date created:		2008-07-27
# Whom:			ports@c0decafe.net <ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	thunar-archive-plugin
PORTVERSION=	0.3.0
CATEGORIES=	archivers xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/thunar-plugins//${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@c0decafe.net
COMMENT=	Archive plugin for the Thunar File Manager

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_XFCE=	configenv libexo thunar
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	desktopfileutils
USE_GMAKE=	yes

.include <bsd.port.mk>
