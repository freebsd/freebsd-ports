# New ports collection makefile for:	nautilus-open-terminal
# Date created:		2005-07-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/nautilus-open-terminal/Makefile,v 1.17 2009/08/09 15:30:27 ahze Exp $
#

PORTNAME=	nautilus-open-terminal
PORTVERSION=	0.18
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Nautilus extension which allows you to open a terminal

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	nautilus2 gnomeprefix intlhack gnomehack
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `pkg-config --cflags gnome-vfs-2.0`" \
		LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	nautilus-open-terminal.schemas

.include <bsd.port.mk>
