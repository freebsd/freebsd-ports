# New ports collection makefile for:	tetrinet
# Date created:		23 Februari 2001
# Whom:			Fredrik Carlsson <fredrik@wasadata.com>
#
# $FreeBSD$
#

PORTNAME=	tetrinet
PORTVERSION=	0.7
CATEGORIES=	games net
MASTER_SITES=	http://achurch.org/tetrinet/
DISTNAME=	${PORTNAME}

MAINTAINER=	<fredrik@wasadata.com>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet-server ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tetrinet
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tetrinet
	${INSTALL_DATA} ${WRKSRC}/tetrinet.txt ${PREFIX}/share/doc/tetrinet
.endif

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
