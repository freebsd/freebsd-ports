# New ports collection makefile for:	htable
# Date created:				13 Aug 2010
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	htable
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp2.culot.org/culot/

MAINTAINER=	frederic@culot.org
COMMENT=	Lightweight implementation of hash tables in C

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		htable.3
PLIST_FILES=	include/htable.h

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/htable.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/src/htable.3 ${MAN3PREFIX}/man/man3

.include <bsd.port.mk>
