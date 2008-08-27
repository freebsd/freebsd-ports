# New ports collection makefile for:	mono-addins
# Date created:				Aug 25 2008
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mono-addins
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Mono framework to create extensible applications

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig

OPTIONS=	GTK2 "Enable GTK support" on

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if !defined(WITHOUT_GTK2) && !defined(WITHOUT_GUI) && !defined(WITHOUT_X11)
USE_GNOME+=	gtksharp20
CONFIGURE_ARGS+=	--enable-gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.include <bsd.port.post.mk>
