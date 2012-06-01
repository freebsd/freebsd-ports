# New ports collection makefile for:	wenju
# Date created:				18 Oct 2003
# Whom:				Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wenju
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of writing tools in Chinese

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

OPTIONS=	NLS	"Build with Native Language Support"	on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules

.include <bsd.port.mk>
