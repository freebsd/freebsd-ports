# New ports collection makefile for:	xdigger
# Version required:			1.0.9
# Date created:				29 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		xdigger-1.0.9
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
EXTRACT_SUFX=		.tgz

MAINTAINER=		andy@icc.surw.chel.su

USE_IMAKE=		yes
MAN6=			xdigger.6
MANCOMPRESSED=		no

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xdigger ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/xdigger.man ${PREFIX}/man/man6/xdigger.6
	@ ${MKDIR} ${PREFIX}/share/xdigger
	@ ${INSTALL_DATA} ${WRKSRC}/xdigger.hiscore ${PREFIX}/share/xdigger
	@ ${INSTALL_DATA} ${WRKSRC}/xdigger.level ${PREFIX}/share/xdigger
.for file in diamond.au step.au stone.au
	@ ${INSTALL_DATA} ${WRKSRC}/audio/${file} ${PREFIX}/share/xdigger
.endfor
	@ ${CHMOD} a+rw ${PREFIX}/share/xdigger/xdigger.hiscore
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xdigger
.for file in COPYING ChangeLog README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xdigger
.endfor
.endif

.include <bsd.port.mk>
