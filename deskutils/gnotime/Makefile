# New ports collection makefile for:	gnotime
# Date created:		1 March 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnotime/Makefile,v 1.18 2007/03/14 17:45:39 marcus Exp $
#

PORTNAME=	gnotime
PORTVERSION=	2.2.2
PORTREVISON=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gttr

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GnoTime is a time tracker for gnome2

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack gnomeprefix intlhack gtkhtml3 libgnomeui
USE_X_PREFIX=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnotime.1
GCONF_SCHEMAS=	gnotime.schemas

.include <bsd.port.mk>
