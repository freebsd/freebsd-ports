# New ports collection makefile for:	aXe
# Date created:		28 December 1994
# Whom:			jc@irbs.com John Capo
#
# $FreeBSD$
#

PORTNAME=	aXe
PORTVERSION=	6.1.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple to use text editor for X

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_IMAKE=	yes
ALL_TARGET=	Xaw3d all
MAN1=		axe.1 axinfo.1

.include <bsd.port.mk>
