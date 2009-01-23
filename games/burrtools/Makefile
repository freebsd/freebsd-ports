# ex:ts=8
# Ports collection makefile for:	burrtools
# Date created:			Mar 23, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	burrtools
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A puzzle solver

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		xmlwrapp.5:${PORTSDIR}/textproc/xmlwrapp

USE_GL=		yes
USE_XORG=	x11 xt xext xmu xi
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

.include <bsd.port.mk>
