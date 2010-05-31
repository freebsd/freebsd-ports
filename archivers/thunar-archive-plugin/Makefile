# New ports collection makefile for:	thunar-archive-plugin
# Date created:		2008-07-27
# Whom:			ports@c0decafe.net <ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	thunar-archive-plugin
PORTVERSION=	0.2.4
PORTREVISION=	8
CATEGORIES=	archivers xfce
MASTER_SITES=	BERLIOS
MASTER_SITE_SUBDIR=	xfce-goodies

MAINTAINER=	ports@c0decafe.net
COMMENT=	Archive plugin for the Thunar File Manager

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_XFCE=	configenv libexo thunar
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	desktopfileutils

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
