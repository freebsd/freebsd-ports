# New ports collection makefile for:	calltree
# Date created:				Jun 3 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	calltree
PORTVERSION=	0.9.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kcachegrind

MAINTAINER=	barner@gmx.de
COMMENT=	Valgrind skin for cache simulation and call tracing

RUN_DEPENDS=	valgrind:${PORTSDIR}/devel/valgrind
BUILD_DEPENDS=	valgrind:${PORTSDIR}/devel/valgrind

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
