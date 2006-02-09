# New ports collection makefile for:	cvsdadm
# Date Created:				Sat Jan 21 22:05:06 EST 2006
# Whom:					Serge Gagnon <serge.gagnon@b2b2c.ca>
#
# $FreeBSD$
#

PORTNAME=	cvsdadm
PORTVERSION=	0.2.4
CATEGORIES=	devel
MASTER_SITES=	ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/

MAINTAINER=	serge.gagnon@b2b2c.ca
COMMENT=	Tool for CVSd pserver user administration

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USE_PERL5_RUN=	yes
POD2TEXT?=	pod2text
PORTDOCS=	cvsdadm.README

PLIST_FILES=	bin/cvsdadm

post-patch:
	@${REINPLACE_CMD} -e "s,#!/usr/bin/perl,#! ${PERL}," ${WRKSRC}/cvsdadm

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${POD2TEXT} ${WRKSRC}/cvsdadm > ${WRKSRC}/${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/cvsdadm ${PREFIX}/bin

.include <bsd.port.mk>
