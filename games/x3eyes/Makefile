# New ports collection makefile for:   x3eyes
# Version required:	1.0
# Date created:		18 Aug 1999
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	x3eyes
PKGNAME=	x3eyes-1.0
CATEGORIES=	games
MASTER_SITES=	http://puma.cis.ibaraki.ac.jp/~th/pub/X11/

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
MAN1=		x3eyes.1

post-extract:
	@( cd ${WRKSRC}; ${CP} x3eyes.1 x3eyes.man )

.include <bsd.port.mk>
