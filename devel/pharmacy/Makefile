# New ports collection makefile for:	pharmacy
# Date created:				02 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	pharmacy
PORTVERSION=	0.2.1
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.earthlink.net/~nawalker/pharmacy/

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
