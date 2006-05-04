# New ports collection makefile for:	krefty
# Date created:			Fri Jan 16 02:55:31 CET 2004
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=	krefty
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	deskutils kde
MASTER_SITES=	http://codeworks.gnomedia.com/krefty/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick Reference sheets for KDE

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|-fPIC|g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
