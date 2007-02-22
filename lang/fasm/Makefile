# New ports collection makefile for:	fasm
# Date created:	   22 February 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	fasm
PORTVERSION=	1.67.21
CATEGORIES=	lang devel
MASTER_SITES=	http://flatassembler.net/
DISTNAME=	${PORTNAME}-1.67

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Flat, multiple-pass assembler for IA-32 & x86-64 architectures

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} fasm.o -o fasm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fasm ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
