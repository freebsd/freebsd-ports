# New ports collection makefile for:	monopd
# Date created:				14 February 2004
# Whom:					jhb
#
# $FreeBSD$
#

PORTNAME=	monopd
PORTVERSION=	0.9.2
CATEGORIES=	games
MASTER_SITES=	http://unixcode.org/downloads/monopd/

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Server for Atlantik and gtkAtlantic Games

BROKEN=		Unfetchable

LIB_DEPENDS=	capsinetwork.0:${PORTSDIR}/devel/libcapsinetwork \
		math\\+\\+.0:${PORTSDIR}/math/libmath++

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
