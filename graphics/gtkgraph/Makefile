# New ports collection makefile for:	gtkgraph
# Version required:			0.5.1
# Date created:				12 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	gtkgraph-0.5.1
CATEGORIES=	math
MASTER_SITES=	http://gtkgraph.linuxbox.com/

MAINTAINER=	jedgar@fxp.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		intl.1:${PORTSDIR}/devel/gettext \
		gdk_imlib.5:${PORTSDIR}/graphics/imlib

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
