# New ports collection makefile for:	xgrasp
# Date created:		23 July 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	xgrasp
PORTVERSION=	1.7d
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	XCONTRIB/../R5contrib
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display GL animations on X screen

NO_WRKSUBDIR=	yes

USE_XORG=	x11 xext
USE_IMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		glib.1 xgrasp.1
PLIST_FILES=	bin/glib bin/xgrasp

.include <bsd.port.mk>
