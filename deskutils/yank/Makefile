# New ports collection makefile for:	yank
# Version required:			0.1.3
# Date created:				28 November 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	yank-0.1.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://home.ins.de/~m.hussmann/software/yank/

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs \
		xml.5:${PORTSDIR}/textproc/libxml

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
