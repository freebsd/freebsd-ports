# New ports collection makefile for:    picasm
# Date created:         25 October 2002
# Whom:                 Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	picasm
PORTVERSION=	1.12b
CATEGORIES=	devel
MASTER_SITES=	http://www.co.jyu.fi/~trossi/pic/ \
		http://www.iki.fi/hyvatti/pic/	\
		http://hyvatti.iki.fi/~jaakko/pic/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	bms@spc.org
COMMENT=	Portable assembler for 16C84 series PICs

WRKSRC=         ${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=

EXAMPLE_FILES=	example.asm morse.asm morse.i pic16f84.i picmac.i

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picasm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/picasm.txt ${DOCSDIR}
.for EXAMPLE in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${EXAMPLE} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
