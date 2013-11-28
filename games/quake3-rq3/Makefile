# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	rq3
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.rq3.com/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	ReactionQuake3-v${PORTVERSION}-Full

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Quake III Arena Mod: Reaction Quake 3

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-12-22

BROKEN=		Does not fetch

USE_ZIP=	yes
USE_CRLF=	yes
NO_BUILD=	yes
NO_PACKAGE=	Package will be 487MB, set FORCE_PACKAGE
WRKSRC=		${WRKDIR}/rq3
DATADIR=	${Q3DIR}/${PORTNAME}

NO_STAGE=	yes
.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
.for FILE in *.cfg *.pk3 *.ini *.qst *.apk *.ico description.txt
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
.	for DIRE in docs mapdocs
		@${MKDIR} ${DOCSDIR}/${DIRE}
		@cd ${WRKSRC}/${DIRE} && \
			${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/${DIRE}/{}" \;
.	endfor
.endif

.include <bsd.port.post.mk>
