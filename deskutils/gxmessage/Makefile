# New ports collection makefile for:	gxmessage
# Date created:				9 March 2005
# Whom:					Andriy Gapon <avg@icyb.net.ua>
#
# $FreeBSD$
#

PORTNAME=	gxmessage
PORTVERSION=	2.4.3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://homepages.ihug.co.nz/~trmusson/stuff/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	GTK2 substitute for xmessage

USE_X_PREFIX=	yes
USE_GNOME=	gtk20 gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAKE_ARGS+=	INSTALL="${INSTALL_PROGRAM}"

MANCOMPRESSED=	no
MAN1=		gxmessage.1
PLIST_FILES=	bin/gxmessage \
		share/gnome/pixmaps/gxmessage.png

.include <bsd.port.mk>
