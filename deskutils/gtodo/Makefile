# New ports collection makefile for:	gtodo
# Date created:				29 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gtodo
PORTVERSION=	0.14
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtodo

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	An Gtk2 Todo list manager

BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget gnomevfs2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gtodo.schemas

.include <bsd.port.mk>
