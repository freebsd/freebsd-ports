# New ports collection makefile for:	chemeq
# Date created:				31 May 2000
# Whom:					rmiya
#
# $FreeBSD$

PORTNAME=	chemeq
PORTVERSION=	1.10
CATEGORIES=	biology textproc
MASTER_SITES=	ftp://boltz.univ-littoral.fr/pub/chemeq/
DISTNAME=	chemeq-V110

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BISON=	yes

MAN1=		chemeq.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/chemeq ${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/chemeq.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/chemeq
	${MKDIR} ${PREFIX}/share/examples/chemeq
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/chemeq
	${INSTALL_DATA} ${WRKSRC}/LISEZMOI ${PREFIX}/share/doc/chemeq
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/chemeq
	${INSTALL_DATA} ${WRKSRC}/src/TODO ${PREFIX}/share/examples/chemeq
	${INSTALL_DATA} ${WRKSRC}/src/test.1 ${PREFIX}/share/examples/chemeq
	${INSTALL_SCRIPT} ${WRKSRC}/src/chemreport ${PREFIX}/share/examples/chemeq
	${INSTALL_SCRIPT} ${WRKSRC}/src/chemreport.pl ${PREFIX}/share/examples/chemeq
	${INSTALL_SCRIPT} ${WRKSRC}/src/chemtest ${PREFIX}/share/examples/chemeq
	${INSTALL_SCRIPT} ${WRKSRC}/src/chemtest.pl ${PREFIX}/share/examples/chemeq
.endif

.include <bsd.port.mk>
