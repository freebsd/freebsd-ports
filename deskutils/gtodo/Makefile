# New ports collection makefile for:	gtodo
# Date created:				29 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gtodo
PORTVERSION=	0.13.5
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtodo

MAINTAINER=	mezz7@cox.net
COMMENT=	An Gtk2 Todo list manager

BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget gconf2 gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
