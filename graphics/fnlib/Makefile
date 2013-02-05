# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	fnlib
PORTVERSION=	0.5
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF/enlightenment/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fonts and font libraries necessary for Enlightenment

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

BROKEN=		does not configure

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GNOME=	imlib
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
