# New ports collection makefile for:	TrickyIRC
# Date created:			 	Jun 20th 1999
# Whom:					troll
#
# $FreeBSD$
#

PORTNAME=	trickyirc
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://www.leb.net/~troll/
DISTNAME=	TrickyIRC-${PORTVERSION}

MAINTAINER=	troll@digitalspark.net
COMMENT=	Allows client independent detaching and reattaching of IRC sessions

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
	@${STRIP_CMD} ${PREFIX}/bin/trickyirc
	@${CAT} ${PKGMESSAGE} | ${SED} -e s:/usr/local:${PREFIX}:

.include <bsd.port.mk>
