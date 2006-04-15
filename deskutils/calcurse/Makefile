# Ports collection makefile for:	calcurse
# Date created:                         Nov 1, 2005
# Whom:                                 Herbert J. Skuhra <h.skuhra@gmail.com>
#
# $FreeBSD$

PORTNAME=		calcurse
PORTVERSION=		1.3
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=		h.skuhra@gmail.com
COMMENT=		A text-based personal organizer

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--prefix=${PREFIX}

MAN1=			calcurse.1
PLIST_FILES=		bin/${PORTNAME}

.include <bsd.port.mk>
