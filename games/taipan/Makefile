# Created by: Dave Walton <dwalton@acm.org>
# $FreeBSD$

PORTNAME=	taipan
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/textrpg

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic role-playing game from the 1980s

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PORTDOCS=	README
PLIST_FILES=	bin/taipan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/taipan ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
