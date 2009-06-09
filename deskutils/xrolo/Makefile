# New ports collection makefile for:  xrolo
# Date created:        17 January 1999
# Whom:                Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	xrolo
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.uni-potsdam.de/pub/X11/open-look/ \
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/
DISTNAME=	${PORTNAME}.v2p6
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic rolodex

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/xrolo

USE_IMAKE=	yes
USE_XORG=	x11 xext
MAN1=		xrolo.1
PLIST_FILES=	bin/xrolo

.include <bsd.port.mk>
