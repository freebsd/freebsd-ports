# New ports collection makefile for:	gnotime
# Date created:		1 March 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gnotime
PORTVERSION=	2.1.7
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gttr

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	GnoTime is a time tracker for gnome2

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_GNOME=	gnomehack gnomeprefix libgtkhtml libgnomeui
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnotime.1

.include <bsd.port.mk>
