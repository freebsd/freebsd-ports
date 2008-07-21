# New ports collection makefile for:	gnotime
# Date created:		1 March 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnotime/Makefile,v 1.21 2007/05/19 21:36:03 marcus Exp $
#

PORTNAME=	gnotime
PORTVERSION=	2.2.2
PORTREVISION=	10
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/gttr

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GnoTime is a time tracker for gnome2

LIB_DEPENDS=	guile.19:${PORTSDIR}/lang/guile

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack gnomeprefix intlhack gtkhtml3 libgnomeui
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnotime.1
GCONF_SCHEMAS=	gnotime.schemas

.include <bsd.port.mk>
