# New ports collection makefile for:	xkoules
# Version required:			1.4
# Date created:				11 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1998/08/25 00:43:54 asami Exp $
#

DISTNAME=	koules1.4-src
PKGNAME=	xkoules-1.4
CATEGORIES=	games
MASTER_SITES=	http://www.paru.cas.cz/~hubicka/koules/packages/ \
		${MASTER_SITE_SUNSITE}

MAINTAINER=	andy@icc.surw.chel.su

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/koules1.4
MAN6=		xkoules.6
MANCOMPRESSED=	no

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xkoules ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xkoules
	@ ${INSTALL_PROGRAM} ${WRKSRC}/koules.sndsrv.freebsd ${PREFIX}/share/xkoules
	@ ${INSTALL_DATA} ${WRKSRC}/sounds/*.raw ${PREFIX}/share/xkoules
	@ ${INSTALL_MAN} ${WRKSRC}/xkoules.6 ${PREFIX}/man/man6

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xkoules
.for file in ANNOUNCE BUGS COPYING Card ChangeLog Koules.FAQ TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xkoules
.endfor
.endif

.include <bsd.port.mk>
