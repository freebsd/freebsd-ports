# New ports collection makefile for:	gnotime
# Date created:		1 March 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnotime/Makefile,v 1.15 2005/07/01 17:57:13 marcus Exp $
#

PORTNAME=	gnotime
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gttr

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GnoTime is a time tracker for gnome2

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_GNOME=	gnomehack gnomeprefix gtkhtml3 libgnomeui
USE_X_PREFIX=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnotime.1
GCONF_SCHEMAS=	gnotime.schemas

# until a new version comes out...
post-patch:
	@${REINPLACE_CMD} -e "s|gtkhtml-3.1|gtkhtml-3.8|g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
