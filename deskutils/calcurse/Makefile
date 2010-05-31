# Ports collection makefile for:	calcurse
# Date created:                         Nov 1, 2005
# Whom:                                 Herbert J. Skuhra <h.skuhra@gmail.com>
#
# $FreeBSD$

PORTNAME=		calcurse
PORTVERSION=		2.7
PORTREVISION=	1
CATEGORIES=		deskutils
MASTER_SITES=		ftp://ftp2.culot.org/culot/

MAINTAINER=		h.skuhra@gmail.com
COMMENT=		A text-based personal organizer

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}

MAN1=			calcurse.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.include <bsd.port.mk>
