# New ports collection makefile for:	xtruco
# Date created:				14 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xtruco
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple version for X Window of the famous card game Super Truco

PLIST_FILES=	bin/xtruco
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtruco ${PREFIX}/bin

.include <bsd.port.mk>
