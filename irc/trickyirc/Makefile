# New ports collection makefile for:	TrickyIRC
# Version required:		 	1.1
# Date created:			 	Jun 20th 1999
# Whom:					troll
#
# $FreeBSD$
#

DISTNAME=	TrickyIRC-1.1.0
PKGNAME=	trickyirc-1.1.0
CATEGORIES=	irc
MASTER_SITES=	http://www.leb.net/~troll/

MAINTAINER=	troll@digitalspark.net

MAKEFILE=	GNUmakefile
WRKSRC=		${WRKDIR}/trickyirc
USE_GMAKE=	YES

post-install:
	@ ${MKDIR} ${PREFIX}/share/doc/TrickyIRC
#	@ ${MKDIR} ${PREFIX}/share/examples/TrickyIRC
#	${INSTALL_DATA} ${WRKSRC}/config.sample \
#	    ${PREFIX}/share/examples/TrickyIRC
	${INSTALL_DATA} ${WRKSRC}/README \
	    ${PREFIX}/share/doc/TrickyIRC
	@strip ${PREFIX}/bin/trickyirc
	@${CAT} ${PKGDIR}/MESSAGE | ${SED} -e s:/usr/local:${PREFIX}:

.include <bsd.port.mk>
