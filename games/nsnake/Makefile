# New ports collection makefile for:   nsnake
# Date created:        08 March 2011
# Whom:                markand
#
# $FreeBSD$
#

PORTNAME=	nsnake
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://softs.malikania.fr/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	markand@malikania.fr
COMMENT=	A snake game written in C and ncurses

MAN6=		nsnake.6
PLIST_FILES=	bin/nsnake
PORTDOCS=	LICENSE

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
.endif

.include <bsd.port.mk>

