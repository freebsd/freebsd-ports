# New ports collection makefile for:	gnugo
# Version required:	1.2
# Date created:		29 December 1996
# Whom:			jseger@scds.com
#
# $Id$
#

DISTNAME=	gnugo-1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jseger@scds.com

WRKSRC=		${WRKDIR}/gnugo
ALL_TARGET=	gnugo
MAKE_FLAGS+=	CFLAGS="${CFLAGS}" -f

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnugo ${PREFIX}/bin

.include <bsd.port.mk>
