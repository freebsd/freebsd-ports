# New ports collection makefile for:	gracula
# Version required:			3.0
# Date created:				30 May 1999
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

DISTNAME=	gracula-3.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.whizkidtech.net/cgi/gcl/ \
		http://www.whizkidtech.net/gcl/

MAINTAINER=	adam@whizkidtech.net

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
