# New ports collection makefile for:	leafrogue
# Date created:				2 Oct 2000
# Whom:					TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	leafrogue
PORTVERSION=	0.72
PORTREVISION=	2
CATEGORIES=	japanese games
MASTER_SITES=	http://games.roguelife.org/~roguelike/leaf/dl/
DISTNAME=	lfrog${PORTVERSION:S/.//}

MAINTAINER=	kaoru@kaisei.org
COMMENT=	LeafRogue for message separated version of Rogue-clone

RUN_DEPENDS=	rogue_s:${PORTSDIR}/japanese/rogue_s

WRKSRC=		${WRKDIR}/lf_rogue
NO_BUILD=	yes

DOC_FILES=	readme.txt lf_rogue.html lf_rogue.txt guide.tex guide.txt

do-install:
	${MKDIR} ${PREFIX}/share/rogue
	${INSTALL_DATA} ${WRKSRC}/leaf.msg ${PREFIX}/share/rogue
	${INSTALL_SCRIPT} ${FILESDIR}/leafrogue ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for file in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/"$$file" ${DOCSDIR} ; \
	done
.endif

.include <bsd.port.mk>
