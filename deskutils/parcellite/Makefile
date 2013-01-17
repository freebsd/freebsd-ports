# Created by: Joey Mingrone <joey@mingrone.org>
# $FreeBSD$

PORTNAME=	parcellite
PORTVERSION=	1.1.2
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jrm@ftfl.ca
COMMENT=	A lightweight GTK+ clipboard manager

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=	parcellite.1

.include <bsd.port.mk>
