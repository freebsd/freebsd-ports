# New ports collection makefile for:	gracula
# Date created:				30 May 1999
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	gracula
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.whizkidtech.redprince.net/cgi/gcl/ \
		http://www.whizkidtech.redprince.net/gcl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graphic Counter Language compiler/interpreter

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gracula ${PREFIX}/bin
	$(INSTALL_PROGRAM) ${WRKSRC}/sec2000 ${PREFIX}/bin
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NNL  ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README  ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
