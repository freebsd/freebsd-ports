# New ports collection makefile for:	xbl
# Date created:		May 25 1997
# Whom:			pgs (original)
#
# $FreeBSD$
#

PORTNAME=	xbl
PORTVERSION=	1.0k
PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp710.univ-lyon1.fr/pub/xbl/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A 3D block-dropping game

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"
MANN=		xbl.n

.include <bsd.port.mk>
