# New ports collection makefile for:	kbarcode
# Date created:				05 July 2002
# Whom:					Andy Raffle <andy@digitalspecies.com>
#
# $FreeBSD$
#

PORTNAME=	kbarcode
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A barcode and label printing application for KDE

RUN_DEPENDS=	barcode:${PORTSDIR}/graphics/barcode

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
