# New ports collection makefile for:	sol
# Version required:			1.0.6
# Date created:				12 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	sol-1.0.6
CATEGORIES=	games
MASTER_SITES=	http://home.sol.no/~sverrehu/pub-unix/files/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		shhopt.1:${PORTSDIR}/devel/libshhopt \
		shhmsg.1:${PORTSDIR}/devel/libshhmsg \
		xalloc.1:${PORTSDIR}/devel/libxalloc \
		shhcards.1:${PORTSDIR}/games/libshhcards

USE_GMAKE=	yes
USE_X_PREFIX=	yes

MAN6=		sol.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/sol ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/sol
	@ ${INSTALL_DATA} ${WRKSRC}/sol.score ${PREFIX}/share/sol
	@ ${INSTALL_MAN} ${WRKSRC}/sol.6 ${PREFIX}/man/man6
	@ ${MKDIR} ${PREFIX}/share/doc/sol
	@ ${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/sol
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sol
	@ ${CHOWN} root:games ${PREFIX}/bin/sol
	@ ${CHOWN} root:games ${PREFIX}/share/sol/sol.score
	@ ${CHMOD} 2755 ${PREFIX}/bin/sol
	@ ${CHMOD} 770 ${PREFIX}/share/sol
	@ ${CHMOD} 660 ${PREFIX}/share/sol/sol.score

.include <bsd.port.mk>
