# New ports collection makefile for:	TrickyIRC
# Version required:			0.99
# Date created:				Jun 20th 1999
# Whom:					Trolld
#
# $Id: Makefile,v 1.1.1.1 1999/06/21 01:19:34 cpiazza Exp $
#

DISTNAME=	TrickyIRC-0.99
PKGNAME=	trickyirc-0.99
CATEGORIES=	irc
MASTER_SITES=	http://www.leb.net/~troll/

MAINTAINER=	troll@digitalspark.net

MAKEFILE=	GNUmakefile
WRKSRC=		${WRKDIR}/trickyirc
USE_GMAKE=	YES

post-install:
	@ ${MKDIR} ${PREFIX}/share/doc/TrickyIRC
	@ ${MKDIR} ${PREFIX}/share/examples/TrickyIRC
	${INSTALL_DATA} ${WRKSRC}/config.sample \
	    ${PREFIX}/share/examples/TrickyIRC
	${INSTALL_DATA} ${WRKSRC}/README \
	    ${PREFIX}/share/doc/TrickyIRC
	@${CAT} ${PKGDIR}/MESSAGE | ${SED} -e s:/usr/local:${PREFIX}:

.include <bsd.port.mk>
