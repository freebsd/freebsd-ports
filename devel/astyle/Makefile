# New ports collection makefile for:	astyle
# Version required:	1.11.5
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $FreeBSD$
#

DISTNAME=	astyle_1.11.5_src
PKGNAME=	astyle-1.11.5
CATEGORIES= 	devel textproc
MASTER_SITES=	http://gene.md.huji.ac.il/~tald/astyle/stable/src/ \
		http://www.infonex.com/~dacroyle/freebsd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

WRKSRC=		${WRKDIR}/astyle_1.11.5

ALL_TARGET=	astyle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/astyle ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/astyle
	${INSTALL_DATA} ${WRKSRC}/astyle.html ${PREFIX}/share/doc/astyle
.endif

.include <bsd.port.mk>
