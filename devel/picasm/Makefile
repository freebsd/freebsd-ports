# New ports collection makefile for:    picasm
# Date created:         25 October 2002
# Whom:                 Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	picasm
PORTVERSION=	1.05
CATEGORIES=	devel
MASTER_SITES=	http://www.iki.fi/hyvatti/pic/	\
		http://hyvatti.iki.fi/~jaakko/pic/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	bms@spc.org

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.uni
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=

EXAMPLE_FILES=	example.asm morse.asm morse.h pic16c84.h picmac.h

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/picasm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/picasm.doc ${DOCSDIR}
.for EXAMPLE in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKDIR}/examples/${EXAMPLE} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
