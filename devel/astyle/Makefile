# New ports collection makefile for:	astyle
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	astyle
PORTVERSION=	1.11.6
CATEGORIES=	devel textproc
MASTER_SITES=	ftp://astyle.sourceforge.net/pub/astyle/stable/src/\
		http://www.gelemna.org/ports/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	croyle@gelemna.org

WRKSRC=		${WRKDIR}/astyle_1.11.6

ALL_TARGET=	astyle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/astyle ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/astyle
	${INSTALL_DATA} ${WRKSRC}/astyle.html ${PREFIX}/share/doc/astyle
.endif

.include <bsd.port.mk>
