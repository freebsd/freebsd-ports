# New ports collection makefile for:	basket
# Date created:			Mon Sep  8 19:32:42 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		basket
PORTVERSION=		0.4.0d
CATEGORIES=		deskutils kde
MASTER_SITES=		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		Desktop organization tool

WRKSRC=			${WRKDIR}/${PORTNAME}-0.4
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
