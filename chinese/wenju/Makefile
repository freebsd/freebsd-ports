# New ports collection makefile for:   wenju
# Date created:                18 Oct 2003
# Whom:                        Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wenju
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	SF

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Collection of writing tools in Chinese

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
		gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules

.include <bsd.port.mk>
