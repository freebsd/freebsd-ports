## New ports collection makefile for:   hexxagon
# Date created:			08 April 2006
# Whom:				Max Brazhnikov makc@issp.ac.ru
#
# $FreeBSD$
#

PORTNAME=	hexxagon
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.nesqi.se/hexxagon/hexxagon/download/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	A strategy hexagon game

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:14

MAKE_ENV+=	CC="${CC}" CXX="${CXX}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
