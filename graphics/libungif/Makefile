# New ports collection makefile for:	giflib
# Version required:	3.0
# Date created:		03 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1997/05/05 12:33:44 tg Exp $
#

DISTNAME=	giflib-3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ccil.org/~esr/giflib/

MAINTAINER=	tg@FreeBSD.ORG

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/giflib
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/giflib
.endif
	@${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
