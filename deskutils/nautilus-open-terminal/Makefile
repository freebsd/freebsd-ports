# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/deskutils/nautilus-open-terminal/Makefile,v 1.17 2009/08/09 15:30:27 ahze Exp $

PORTNAME=	nautilus-open-terminal
PORTVERSION=	0.18
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Nautilus extension which allows you to open a terminal

DEPRECATED=	nautilus will be updated to the 3.x version which is not compatible with 2.x
EXPIRATION_DATE=2014-04-10

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	nautilus2 gnomeprefix intlhack gnomehack
USES=		gettext gmake pkgconfig
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags gnome-vfs-2.0`
LDFLAGS+=	-L${LOCALBASE}/lib
GCONF_SCHEMAS=	nautilus-open-terminal.schemas

NO_STAGE=	yes
.include <bsd.port.mk>
