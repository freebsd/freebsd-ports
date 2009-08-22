# New ports collection makefile for:	gqlplus
# Date created:				06 November 2002
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqlplus
PORTVERSION=	1.12
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	SQL*PLUS with commandline editing, history, and name completion

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PORTDOCS=	README ChangeLog
PLIST_FILES=	bin/gqlplus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
