# New ports collection makefile for:   games/pmars
# Version required:    pmars v0.8
# Date created:        15 Feb 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

DISTNAME=	pmars08s
PKGNAME=	pmars-0.8
CATEGORIES=	games
MASTER_SITES=	http://www.koth.org/pmars/ \
		http://www.giovannelli.it/~gmarco/files/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	gmarco@giovannelli.it

USE_XLIB=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	pmars
MAN6=		pmars.6

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/corewars
	@${INSTALL_PROGRAM} ${WRKSRC}/pmars ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/pmars.6 ${PREFIX}/man/man6
	@${INSTALL_DATA} ${WRKSRC}/*.red ${PREFIX}/share/games/corewars
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/games/corewars
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can try something like :"
	@${ECHO_MSG} "pmars -v 603 ${PREFIX}/share/games/corewars/rave.red ${PREFIX}/share/games/corewars/aeka.red"
	@${ECHO_MSG} "to see how the simulator works (rave.red and aeka.red are two sample warriors)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Some other warriors are installed in : ${PREFIX}/share/games/corewars"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Plase read also ${PREFIX}/share/games/corewars/README file for more infos"
	@${ECHO_MSG} "on corewars and on the current version of pmars"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
