# New ports collection makefile for:	krefty
# Date created:			Fri Jan 16 02:55:31 CET 2004
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=	krefty
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.gnomedia.com/cw/krefty/

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	Quick Reference sheets for KDE

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
