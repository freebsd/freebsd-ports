# New ports collection makefile for:	AUnit
# Date created:				20 Jan 2002
# Whom:					Aidan Skinner <aidan@velvet.net>
#
# $FreeBSD$
#

PORTNAME=	aunit
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://libre2.adacore.com/aunit/
DISTNAME=	${PORTNAME}-${PORTVERSION}p-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A unit testing framework for the Ada '95 programming language

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/AUnit

pre-install:
	@${FIND} ${WRKSRC} -type d -name CVS -print0 | ${XARGS} -0 ${RM} -rf

do-install:
	@${MKDIR} ${PREFIX}/include/aunit
	${INSTALL_DATA} ${WRKSRC}/aunit/framework/* ${PREFIX}/include/aunit
	${INSTALL_DATA} ${WRKSRC}/aunit/text_reporter/* ${PREFIX}/include/aunit
	@${MKDIR} ${DATADIR}/template ${DATADIR}/test
	${INSTALL_DATA} ${WRKSRC}/template/* ${DATADIR}/template
	${INSTALL_DATA} ${WRKSRC}/test/* ${DATADIR}/test
	${INSTALL_DATA} ${WRKSRC}/*.gpr ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUnit.html ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
