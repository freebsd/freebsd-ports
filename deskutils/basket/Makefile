# New ports collection makefile for:	basket
# Date created:			Mon Sep  8 19:32:42 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		basket
PORTVERSION=		0.3.3
CATEGORIES=		deskutils kde
MASTER_SITES=		http://www.sebastien.laout.tuxfamily.org/basket/

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		Desktop organization tool

WRKSRC=			${WRKDIR}/${PORTNAME}-0.3.2
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
