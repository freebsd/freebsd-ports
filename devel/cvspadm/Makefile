# New ports collection makefile for:	cvspadm
# Date Created:				17 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	cvspadm
PORTVERSION=	0.1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.securityfoo.net/ray/projs/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Tool for CVS pserver user administration

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USE_PERL5=	yes
POD2TEXT?=	pod2text

post-patch:
	@${PERL} -pi -e "s,#!/usr/bin/perl,#!${PERL}," ${WRKSRC}/cvspadm

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${POD2TEXT} ${WRKSRC}/cvspadm > ${WRKSRC}/cvspadm.README
	${INSTALL_DATA} ${WRKSRC}/cvspadm.README \
		${DOCSDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/cvspadm ${PREFIX}/bin

.include <bsd.port.mk>
