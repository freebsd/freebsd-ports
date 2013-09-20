# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$

PORTNAME=	xjig
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jigsaw puzzle game for X11

USE_XORG=	x11 xproto xext
MAKEFILE=	Makefile.Linux
MAN1=		xjig.1
PLIST_FILES=	bin/xjig

NO_STAGE=	yes
do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xjig ${PREFIX}/bin/xjig
	@ ${INSTALL_MAN} ${WRKSRC}/xjig.man ${PREFIX}/man/man1/xjig.1

.include <bsd.port.mk>
