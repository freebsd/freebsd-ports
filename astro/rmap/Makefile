# New ports collection makefile for:	rmap
# Date created:				29 Mar 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	rmap
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	astro
MASTER_SITES=	http://www.reza.net/rmap/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Generates images of the Earth centered at a particular location

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

MAN1=		rmap.1
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
