# New ports collection makefile for:	xjig
# Date Created:		17 Sep 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	xjig
PORTVERSION=	2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jigsaw puzzle game for X11

USE_XLIB=	yes
MAKEFILE=	Makefile.Linux
MAN1=		xjig.1
PLIST_FILES=	bin/xjig

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xjig ${PREFIX}/bin/xjig
	@ ${INSTALL_MAN} ${WRKSRC}/xjig.man ${PREFIX}/man/man1/xjig.1

.include <bsd.port.mk>
