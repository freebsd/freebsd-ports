# New ports collection makefile for:	gracula
# Date created:				30 May 1999
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	gracula
PORTVERSION=	3.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.whizkidtech.redprince.net/cgi/gcl/ \
		http://www.whizkidtech.redprince.net/gcl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graphic Counter Language compiler/interpreter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gracula ${PREFIX}/bin
	$(INSTALL_PROGRAM) ${WRKSRC}/sec2000 ${PREFIX}/bin
.if !defined (NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gracula
	${INSTALL_MAN} ${WRKSRC}/NNL ${PREFIX}/share/doc/gracula
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/gracula
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
