# New ports collection makefile for:	crimap
# Date created:				4 December 2001
# Whom:					Tony Maher <tonym@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	crimap
PORTVERSION=	2.4
CATEGORIES=	biology
MASTER_SITES=	http://compgen.rutgers.edu/multimap/crimap/
DISTNAME=	${PORTNAME}.source
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tonym@biolateral.com.au

NO_WRKSUBDIR=	true

PROGRAMS=	crimap
EXAMPLES=	chr7a.gen demo.dat

do-build:
	cd ${WRKSRC}; \
	cc -O -o crimap *.c -lm

do-install:
.for file in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	${CAT} ${WRKSRC}/progdoc_v2.4 | tbl | eqn -Tlatin1 | nroff -ms -t \
		> ${DOCSDIR}/progdoc_v2.4
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
