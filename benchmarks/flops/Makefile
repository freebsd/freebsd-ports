# New ports collection makefile for:	flops
# Date created:				06 Jul 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flops
PORTVERSION=	2.0
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.nosc.mil/pub/aburto/flops/
DISTFILES=	${PORTNAME}.c ${PORTNAME}.doc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Floating point benchmark to give your MFLOPS rating

PLIST_FILES=	bin/flops

.if !defined(NOPORTDOCS)
PORTDOCS=	flops.doc
.endif

do-extract: .SILENT
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/flops.c ${DISTDIR}/flops.doc ${WRKSRC}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -DUNIX -o flops flops.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flops ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/flops.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
