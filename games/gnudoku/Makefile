# New ports collection makefile for:	GNUDoku
# Date created:				12 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	GNUDoku
PORTVERSION=	0.93
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/~jcspray/GNUDoku/ \
		http://icculus.org/~jcspray/GNUDoku/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A free program for creating and solving Su Doku puzzles

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_GMAKE=	yes
MAKE_ENV=	CXXLAGS="${CXXFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX=|PREFIX?=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CXXFLAGS=|CXXFLAGS+=|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
