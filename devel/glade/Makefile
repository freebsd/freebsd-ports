# New ports collection makefile for:	glade
# Date created:		29 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	glade
PORTVERSION=	0.5.9
CATEGORIES=	devel gnome
MASTER_SITES=   ${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/glade

MAINTAINER=     ade@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

FETCH_BEFORE_ARGS=	-b

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/libs"

.include <bsd.port.mk>
