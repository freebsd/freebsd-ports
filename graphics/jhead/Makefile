# New ports collection makefile for:   jhead
# Date created:                01 Dec 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	jhead
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Exif Jpeg camera setting parser and thumbnail remover

MAKEFILE=	${WRKSRC}/makefile
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/usage.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
