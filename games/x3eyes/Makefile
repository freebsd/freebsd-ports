# New ports collection makefile for:   x3eyes
# Date created:		18 Aug 1999
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	x3eyes
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://puma.cis.ibaraki.ac.jp/pub/X11/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xeyes-like game except with 3 eyes

USE_IMAKE=	yes
MAN1=		x3eyes.1
PLIST_FILES=	bin/x3eyes

post-extract:
	@( cd ${WRKSRC}; ${CP} x3eyes.1 x3eyes.man )

.include <bsd.port.mk>
