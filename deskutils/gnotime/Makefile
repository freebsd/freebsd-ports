# New ports collection makefile for:	gnotime
# Date created:		1 March 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
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
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnotime.1
GCONF_SCHEMAS=	gnotime.schemas

# until a new version comes out...
post-patch:
	@${REINPLACE_CMD} -e "s|gtkhtml-3.1|gtkhtml-3.6|g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
