# Ports collection Makefile for:	dasher
# Date created:				5 July 2003
# Whom:					lewiz <purple@lewiz.net>
#
# $FreeBSD$
#

PORTNAME=	dasher
PORTVERSION=	3.0.2
CATEGORIES=	editors
MASTER_SITES=	http://www.inference.phy.cam.ac.uk/${PORTNAME}/download/linux/source/3.0/
DIST_SUBDIR=	gnome2

MAINTAINER=	purple@lewiz.net
COMMENT=	Information efficient text-entry interface

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk2 --disable-gtkmmtest
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	yes

LDFLAGS+=	-L{LOCALBASE}/lib

MAN1=		dasher.1

.include <bsd.port.mk>
