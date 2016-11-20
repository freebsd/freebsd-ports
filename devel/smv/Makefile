# Created by: Marc E.E. van Woerkom <marc.vanwoerkom@fernuni-hagen.de>
# $FreeBSD$

PORTNAME=	smv
PORTVERSION=	2.5.4.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.cmu.edu/~modelcheck/smv/
DISTNAME=	${PORTNAME}.r${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Symbolic Model Verifier System for checking finite state systems

USE_GCC=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	${PORTNAME}
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=	yes

PORTEXAMPLES=	*
PORTDOCS=	NEW README smvmanual.ps

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smv ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/smv-mode.el ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/smv.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEW ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/smvmanual.ps ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/counter.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/dme1.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/dme2.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/featuring.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/gigamax.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/mutex.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/mutex1.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/periodic.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/ring.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/semaphore.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/short.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/syncarb5.smv ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
