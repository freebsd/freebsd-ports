# New ports collection makefile for:	taxipilot
# Date created:				2003-07-03
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	taxipilot
PORTVERSION=	0.9.0
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	taxipilot

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Spacetaxi clone

LIB_DEPENDS=	noatun.3:${PORTSDIR}/multimedia/kdemultimedia3

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
