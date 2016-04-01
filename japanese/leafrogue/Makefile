# Created by: TAKAHASHI Kaoru
# $FreeBSD$

PORTNAME=	leafrogue
PORTVERSION=	0.72
PORTREVISION=	3
CATEGORIES=	japanese games
MASTER_SITES=	http://games.roguelife.org/~roguelike/leaf/dl/
DISTNAME=	lfrog${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LeafRogue for message separated version of Rogue-clone

RUN_DEPENDS=	rogue_s:japanese/rogue_s

WRKSRC=		${WRKDIR}/lf_rogue
NO_BUILD=	yes
DOC_FILES=	readme.txt lf_rogue.html lf_rogue.txt guide.tex guide.txt
OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/rogue_s
	${INSTALL_DATA} ${WRKSRC}/leaf.msg ${STAGEDIR}${PREFIX}/share/rogue_s
	${INSTALL_SCRIPT} ${FILESDIR}/leafrogue ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for file in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/"$$file" ${STAGEDIR}${DOCSDIR} ; \
	done

.include <bsd.port.mk>
