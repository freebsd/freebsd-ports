# New ports collection makefile for: wordplay
# Date created:		24 Jun 2000
# Whom:			Ben Smithurst <ben@scientia.demon.co.uk>
#
# $FreeBSD$

PORTNAME=	wordplay
PORTVERSION=	7.22
CATEGORIES=	games
MASTER_SITES=	http://hsvmovies.com/static_subpages/personal/wordplay/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple program to generate anagrams

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	wordplay

post-patch:
	@${REINPLACE_CMD} -e \
	  "s#words721.txt#${PREFIX}/share/wordplay/words721.txt#" \
	  ${WRKSRC}/wordplay.c

do-install:
	@${MKDIR} ${PREFIX}/share/wordplay
	${INSTALL_DATA} ${WRKSRC}/words721.txt ${WRKSRC}/readme \
	  ${PREFIX}/share/wordplay
	${INSTALL_PROGRAM} ${WRKSRC}/wordplay ${PREFIX}/bin

.include <bsd.port.mk>
