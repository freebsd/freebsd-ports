# New ports collection makefile for:   fnccheck
# Date created:        22 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	fnccheck
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A profiling library/utilities for C/C++ programs

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-devel-${PORTVERSION}

DOCS=		README.txt README1ST.txt CHANGES.txt \
		doc/fncdump.info doc/html/fncdump_toc.html \
		doc/html/fncdump.html

STRIP=		#

do-install:
.for B in fncdump fncaverage
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$B ${PREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libfnccheck.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for D in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$D ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
