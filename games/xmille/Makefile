# New ports collection makefile for:    xmille
# Date created:         30 Dec 1994
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	xmille
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X window mille bourne game

WRKSRC=		${WRKDIR}/Mille

USE_IMAKE=	yes
MAN1=		xmille.1
PLIST_FILES=	bin/xmille

post-extract:
	@${FIND} ${WRKSRC} -name '*.[ao]' -delete

.include <bsd.port.mk>
