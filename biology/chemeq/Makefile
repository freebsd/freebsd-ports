# New ports collection makefile for:	chemeq
# Date created:				31 May 2000
# Whom:					rmiya
#
# $FreeBSD$

PORTNAME=	chemeq
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	biology textproc
MASTER_SITES=	ftp://boltz.univ-littoral.fr/pub/chemeq/
DISTNAME=	chemeq-V110-1

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp
COMMENT=	Outputs LaTeX code for chemical reaction

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BISON=	yes

MAN1=		chemeq.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/chemeq ${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/chemeq.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LISEZMOI ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/TODO ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/test.1 ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/chemreport ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/chemreport.pl ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/chemtest ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/chemtest.pl ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
