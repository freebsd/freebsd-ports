# New ports collection makefile for:	krefty
# Date created:			Fri Jan 16 02:55:31 CET 2004
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=	krefty
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.gnomedia.com/cw/krefty/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Quick Reference sheets for KDE

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
