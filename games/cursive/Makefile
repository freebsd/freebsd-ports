# New ports collection makefile for:	cursive
# Date created:		4 December 1999
# Whom:			James Howard <howardj@wam.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	cursive
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://puck.nether.net/pub/janc/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create ASCII character cursive handwriting

MAN6=		cursive.6
PLIST_FILES=	bin/cursive

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cursive ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cursive.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
