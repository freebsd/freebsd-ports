# New ports collection makefile for:	cre
# Date created:				2008-01-15
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	cre
DISTVERSION=	1.2beta_r2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${DISTVERSION}_src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Corewars Redcode Evolver

USE_DOS2UNIX=	../*.txt
WRKSRC=		${WRKDIR}/src

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e '/memwatch\.h/d' \
		asm.c pspace.c sim.c
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e \
		's|random[[:blank:]]*(|myrandom(|' \
		battler.c generator.c globals.h Main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
