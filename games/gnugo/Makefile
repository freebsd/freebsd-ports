# New ports collection makefile for:	gnugo
# Version required:	1.2
# Date created:		29 December 1996
# Whom:			jseger@scds.com
#
# $Id: Makefile,v 1.1.1.1 1997/01/02 07:23:50 tg Exp $
#

DISTNAME=	gnugo-1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jseger@freebsd.org

WRKSRC=		${WRKDIR}/gnugo
ALL_TARGET=	gnugo
MAKE_FLAGS+=	CFLAGS="${CFLAGS}" -f

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnugo ${PREFIX}/bin

.include <bsd.port.mk>
