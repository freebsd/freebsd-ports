# ex:ts=8
# New ports collection makefile for:	fc++
# Date created:			Oct 10, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fc++
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.cc.gatech.edu/~yannis/fc++/
DISTNAME=	FC++.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Functional Programming in C++

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/include/fc++
	${CP} ${WRKSRC}/*.h ${PREFIX}/include/fc++

.include <bsd.port.mk>
