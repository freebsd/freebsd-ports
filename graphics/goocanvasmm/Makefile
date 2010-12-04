# New ports collection makefile for:	goocanvasmm
# Date created:		2008-08-10
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/goocanvasmm/Makefile,v 1.4 2010/10/29 10:27:45 kwm Exp $

PORTNAME=	goocanvasmm
PORTVERSION=	0.15.4
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	C++ bindings for the goocanvas widget for GTK

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		goocanvas.3:${PORTSDIR}/graphics/goocanvas

USE_GNOME=	gnomehack ltverhack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
USE_BZIP2=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
