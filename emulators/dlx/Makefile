# ex:ts=8
# Ports collection makefile for:  dlx
# Date created:			  Mon Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	dlx
PORTVERSION=	2.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://foofoo.stanford.edu/pub/max/pub/hennessy-patterson.software/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"Assembler for Hennessy and Patterson's DLX architecture"

ONLY_FOR_ARCHS=	i386
USE_GCC=	2.95
MAKE_ENV=	prefix=${PREFIX} INSTALLDIR=${PREFIX}/bin

PORTDOCS=	dlxsim.tex manual.tex report.tex report2.tex
MAN1=		dlxcc.1

do-configure:
	cd ${WRKSRC}/gcc && ./config.gcc dlx

do-build:
	cd ${WRKSRC}/dlxsim && ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}
	cd ${PREFIX}/bin && ${STRIP_CMD} dlxcc dlx-gcc-cc1 dlx-gcc-cpp
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dlxsim ${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/dlxsim/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
