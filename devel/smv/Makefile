# Created by: Marc E.E. van Woerkom <marc.vanwoerkom@fernuni-hagen.de>
# $FreeBSD$

PORTNAME=	smv
PORTVERSION=	2.5.4.3
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.cmu.edu/~modelcheck/smv/
DISTNAME=	${PORTNAME}.r${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Symbolic Model Verifier System for checking finite state systems

BROKEN_aarch64=		fails to build: undefined reference to sbrk
BROKEN_armv6=		fails to build: error: non-void function check_bdd should return a value
BROKEN_armv7=		fails to build: error: non-void function check_bdd should return a value

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
	${INSTALL_MAN} ${WRKSRC}/smv.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/smv-mode.el ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEW ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/smvmanual.ps ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/counter.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/dme1.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/dme2.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/featuring.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/gigamax.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/mutex.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/mutex1.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/periodic.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ring.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/semaphore.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/short.smv ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/syncarb5.smv ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
