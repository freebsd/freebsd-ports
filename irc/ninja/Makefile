# New ports collection makefile for: 	Ninja-irc
# Version required: 	1.0.7
# Date created:	 	10 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.1.1.1 1999/04/15 03:20:01 mharo Exp $
#

DISTNAME= 	ninja-src
PKGNAME=	ninja-1.0.8
CATEGORIES=	net
MASTER_SITES=	http://ninja.pimped.org/

MAINTAINER=	cpiazza@home.net

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/ninja-irc

MAN1=	ninja.1

post-patch:
	@${SED} -e s#__PREFIX__#$(PREFIX)#g $(WRKSRC)/include/config.h.dist > $(WRKSRC)/include/config.h.dist.new
	@${MV} $(WRKSRC)/include/config.h.dist.new $(WRKSRC)/include/config.h.dist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/ninja ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/wserv ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/ninja/help
	${INSTALL_DATA} ${WRKSRC}/doc/ninja.help ${PREFIX}/share/ninja/help
	${INSTALL_MAN} ${WRKSRC}/doc/ninja.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ninja
	${INSTALL_DATA} ${WRKSRC}/doc/colors.txt ${PREFIX}/share/doc/ninja
	${INSTALL_DATA} ${WRKSRC}/doc/commands.txt ${PREFIX}/share/doc/ninja
	${INSTALL_DATA} ${WRKSRC}/doc/keyinfo.txt ${PREFIX}/share/doc/ninja
.endif

.include <bsd.port.mk>
