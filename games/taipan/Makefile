# New ports collection makefile for:	taipan
# Date created:				2002-03-15
# Whom:					Dave Walton <dwalton@acm.org>
#
# $FreeBSD$
#

PORTNAME=	taipan
PORTVERSION=	0.9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ilbbs.com/pub/linux/

MAINTAINER=	ports@FreeBSD.org

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/taipan
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
