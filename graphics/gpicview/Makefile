# New ports collection makefile for:	gpicview
# Date created:		2007-10-05
# Whom:			Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	gpicview
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/lxde/GPicView%20%28image%20Viewer%29/GPicView%20${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	A Simple and Fast Image Viewer for X

USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
