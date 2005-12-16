# New ports collection makefile for:	xbl
# Date created:		May 25 1997
# Whom:			pgs (original)
#
# $FreeBSD$
#

PORTNAME=	xbl
PORTVERSION=	1.1.3
CATEGORIES=	games
MASTER_SITES=	http://www710.univ-lyon1.fr/~exco/XBL/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D block-dropping game

BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		xbl.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

.include <bsd.port.post.mk>
