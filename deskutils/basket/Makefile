# New ports collection makefile for:	basket
# Date created:			Mon Sep  8 19:32:42 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		basket
PORTVERSION=		0.4.0b
CATEGORIES=		deskutils kde
MASTER_SITES=		http://les83plus.free.fr/sebastien.laout/basket/downloads/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		Desktop organization tool

WRKSRC=			${WRKDIR}/${PORTNAME}-0.4
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
