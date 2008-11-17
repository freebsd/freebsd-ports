# New ports collection makefile for:	quake3-rq3
# Date created:				2006-02-19
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	rq3
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.rq3.com/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	ReactionQuake3-v${PORTVERSION}-Full

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Quake III Arena Mod: Reaction Quake 3

USE_ZIP=	yes
USE_CRLF=	yes
NO_BUILD=	yes
NO_PACKAGE=	Package will be 487MB, set FORCE_PACKAGE
WRKSRC=		${WRKDIR}/rq3
DATADIR=	${Q3DIR}/${PORTNAME}

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
.for FILE in *.cfg *.pk3 *.ini *.qst *.apk *.ico description.txt
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
.	for DIRE in docs mapdocs
		@${MKDIR} ${DOCSDIR}/${DIRE}
		@cd ${WRKSRC}/${DIRE} && \
			${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/${DIRE}/{}" \;
.	endfor
.endif

.include <bsd.port.post.mk>
