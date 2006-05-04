# New ports collection makefile for:	basket
# Date created:			Mon Sep  8 19:32:42 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		basket
PORTVERSION=		0.5.0
PORTREVISION=	2
CATEGORIES=		deskutils kde
MASTER_SITES=		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		Desktop organization tool

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
