# ex:ts=8
# Ports collection makefile for:  stlport
# Date Created:			  2 December 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	stlport
PORTVERSION=	4.0
CATEGORIES=	devel
MASTER_SITES=	http://www.stlport.com/archive/
DISTNAME=	STLport-${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/STLport-${PORTVERSION}/src
MAKEFILE=	gcc.mak
ALL_TARGET=	clean all
USE_GMAKE=	yes

do-install:
	${MKDIR} ${PREFIX}/include/stlport

.for include in *.h algorith algorithm deque functional hash_map hash_set \
iterator list map memory numeric queue rope set slist stack utility vector \
xmemory xutility
	${INSTALL_DATA} ${WRKSRC}/${include} ${PREFIX}/include/stlport
.endfor

.include <bsd.port.mk>
