# New ports collection makefile for: rottdc
# Date created:		18 Feb 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	rottdc
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sdl-dc
DISTNAME=	${PORTNAME}-1.0-2

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Apogee's Rise Of The Triad source port

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer
USE_XLIB=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/rott

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rott ${PREFIX}/bin
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKDIR}/${DISTNAME}/README ${DOCSDIR}
.for i in cheats cmdline
	${INSTALL_DATA} ${WRKSRC}/${i}.txt ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
