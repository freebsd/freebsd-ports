# New ports collection makefile for:	Chemeq
# Date created:				31 May 2000
# Whom:					Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	chemeq
PORTVERSION=	1.50
PORTREVISION=	1
CATEGORIES=	biology textproc
MASTER_SITES=	http://download.gna.org/chemeq/chemeq-1.5/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}_1.5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Outputs LaTeX code for chemical reaction

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-1.5

USE_BISON=	build

MAN1=		chemeq.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/chemeq ${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/chemeq.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/test.stuff ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tests/chemreport ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tests/chemreport.pl ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tests/chemtest ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tests/chemtest.pl ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
