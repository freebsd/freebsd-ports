# New ports collection makefile for: smv
# Date created: 18 November 2003
# Whom: Marc E.E. van Woerkom <marc.vanwoerkom@fernuni-hagen.de>
#
# $FreeBSD$
#

PORTNAME=	smv
PORTVERSION=	2.5.4.3
CATEGORIES=	devel
MASTER_SITES=	http://www-2.cs.cmu.edu/~modelcheck/smv/
DISTNAME=	${PORTNAME}.r${PORTVERSION}

MAINTAINER=	marc.vanwoerkom@fernuni-hagen.de
COMMENT=	Symbolic Model Verifier System for checking finite state systems

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	${PORTNAME}
MAKEFILE=	makefile

MAN1=		smv.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smv ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/smv-mode.el ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/smv.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEW ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/smvmanual.ps ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/counter.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/dme1.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/dme2.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/featuring.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/gigamax.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/mutex.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/mutex1.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/periodic.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/ring.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/semaphore.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/short.smv ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/syncarb5.smv ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
