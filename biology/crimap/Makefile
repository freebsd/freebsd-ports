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

MAINTAINER=	tonymaher@optusnet.com.au
COMMENT=	Creation of multilocus linkage maps

NO_WRKSUBDIR=	true

PROGRAMS=	crimap
EXAMPLES=	chr7a.gen demo.dat
EXIT_PATCH=	e_ped.c get_log.c our_allo.c our_orde.c

post-patch:
.for file in ${EXIT_PATCH}
	@${REINPLACE_CMD} -e 's|exit\ *()|exit(0)|' ${WRKSRC}/${file}
.endfor

do-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} -o crimap *.c -lm

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
