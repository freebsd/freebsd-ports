# New ports collection makefile for:	parcellite
# Date created:	29 April 2009
# Whom:	Joey Mingrone <joey@mingrone.org>
#
# $FreeBSD$
#

PORTNAME=	parcellite
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	joey@mingrone.org
COMMENT=	A lightweight GTK+ clipboard manager

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=	parcellite.1

.include <bsd.port.mk>
