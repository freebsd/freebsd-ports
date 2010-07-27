# Ports collection makefile for:	calcurse
# Date created:                         Nov 1, 2005
# Whom:                                 Herbert J. Skuhra <h.skuhra@gmail.com>
#
# $FreeBSD$

PORTNAME=	calcurse
PORTVERSION=	2.8
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp2.culot.org/culot/

MAINTAINER=	frederic@culot.org
COMMENT=	A text-based calendar and scheduling application

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		calcurse.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
