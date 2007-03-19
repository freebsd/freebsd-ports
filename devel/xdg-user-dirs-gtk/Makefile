# New ports collection makefile for:	xdg-user-dirs-gtk
# Date created:		2007-03-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/xdg-user-dirs-gtk/Makefile,v 1.3 2007/03/06 15:07:47 ahze Exp $

PORTNAME=	xdg-user-dirs-gtk
PORTVERSION=	0.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Companion to xdg-user-dirs that integrates into GTK/GNOME apps

USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
