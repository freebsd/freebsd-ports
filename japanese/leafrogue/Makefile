# New ports collection makefile for:	leafrogue
# Date created:				2 Oct 2000
# Whom:					TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	leafrogue
PORTVERSION=	0.72
CATEGORIES=	japanese games
MASTER_SITES=	http://www.lab3.kuis.kyoto-u.ac.jp/~roguelike/leaf/dl/
DISTNAME=	lfrog${PORTVERSION:S/.//}

MAINTAINER=	kaoru@kaisei.org

RUN_DEPENDS=	rogue_s:${PORTSDIR}/japanese/rogue_s

WRKSRC=		${WRKDIR}/lf_rogue
NO_BUILD=       yes

DOC_DIR=	${PREFIX}/share/doc/ja/leafrogue
DOC_FILES=	readme.txt lf_rogue.html lf_rogue.txt guide.tex guide.txt

do-install:
	${INSTALL_DATA} ${WRKSRC}/leaf.msg ${PREFIX}/share/rogue
	${INSTALL_SCRIPT} ${FILESDIR}/leafrogue ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOC_DIR}
	for file in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/"$$file" ${DOC_DIR} ; \
	done
.endif

.include <bsd.port.mk>
