# New ports collection makefile for:    picasm
# Date created:         25 October 2002
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	picasm
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.jmp.fi/~trossi/pic/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable assembler for 16C84 series PICs

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}

USE_PERL5_BUILD=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PERL5="${PERL5}"
ALL_TARGET=

EXAMPLE_FILES=	example.asm morse.asm morse.i pic16f84.i picmac.i

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picasm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/picasm.txt ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
.for EXAMPLE in ${EXAMPLE_FILES}
	@ ${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${EXAMPLE} ${EXAMPLESDIR}
.endfor
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}/device_definitions
	${INSTALL_DATA} ${WRKSRC}/device_definitions/*.i ${DATADIR}/device_definitions
.endif

.include <bsd.port.mk>
