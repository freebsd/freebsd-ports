# New ports collection makefile for:   xbomber
# Date created:        28 June 1998
# Whom:                marcus
#
# $FreeBSD$
#

PORTNAME=	xbomber
PORTVERSION=	0.8
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/xbomber/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A game based on "Super Bomberman" for the Super Nintendo

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xbomber ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xbomber
	${TAR} -C ${WRKSRC} -cf - bitmaps jungle levels pixmaps sounds | \
		${TAR} -C ${PREFIX}/share/xbomber --unlink -xf -
	@${FIND} ${PREFIX}/share/xbomber | \
		${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${PREFIX}/share/xbomber -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xbomber
.for file in README.txt LEVELS.txt SOUND.txt GRAPHICS.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xbomber
.endfor
.endif

.include <bsd.port.mk>
