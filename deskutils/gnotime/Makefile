# New ports collection makefile for:	gnotime
# Date created:		1 March 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gnotime
PORTVERSION=	2.1.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gttr

MAINTAINER=	ports@freebsd.org
COMMENT=	GnoTime is a time tracker for gnome2

LIB_DEPENDS=	gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui \
		gtkhtml-2.0:${PORTSDIR}/www/libgtkhtml \
		guile.15:${PORTSDIR}/lang/guile

USE_GNOME=	gnomehack gnomeprefix
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex -lcompat"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		gnotime.1

.include <bsd.port.mk>
