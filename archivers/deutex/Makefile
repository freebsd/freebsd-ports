# New ports collection makefile for:	DeuTex
# Date created:				20 Dec 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deutex
PORTVERSION=	4.4.0
CATEGORIES=	archivers games
MASTER_SITES=	http://www.teaser.fr/~amajorel/deutex/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	WAD file composer for Doom, Heretic, Hexen, and Strife

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/deusf bin/deutex
PORTDOCS=	MANUAL TODO

MAN6=		${PORTNAME}.6

post-extract:
	@${REINPLACE_CMD} -e 's,malloc\.h,stdlib\.h,' ${WRKSRC}/src/tools.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deusf ${WRKSRC}/deutex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MANPREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dtexman6.txt ${DOCSDIR}/MANUAL
.endif

.include <bsd.port.mk>
