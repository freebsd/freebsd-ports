# New ports collection makefile for:   jhead
# Date created:                01 Dec 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	jhead
PORTVERSION=	1.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jamie@hermans.ca

MAKEFILE=	${FILESDIR}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/usage.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
