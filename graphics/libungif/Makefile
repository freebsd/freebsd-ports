# New ports collection makefile for:	giflib
# Version required:	2.3
# Date created:		03 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	giflib-2.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.ccil.org/~esr/

MAINTAINER=	tg@FreeBSD.ORG

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/giflib
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/giflib
.endif
	@${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
