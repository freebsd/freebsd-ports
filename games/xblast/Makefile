# New ports collection makefile for:    xblast
# Date created:         Sat Nov 08 09:47:12 CET 1997
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	xblast
PORTVERSION=	2.6.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
DISTNAME=	xblast-2.6.1.sound

MAINTAINER=	se@FreeBSD.org

WRKSRC=		${WRKDIR}/XBlast-2.6-sound
USE_IMAKE=      yes
NO_INSTALL_MANPAGES=	yes
MANN=		xblast.n
MANCOMPRESSED=	no

post-install:
	@${INSTALL_MAN} ${WRKSRC}/xblast.man ${MANNPREFIX}/man/mann/xblast.n

.include <bsd.port.mk>
