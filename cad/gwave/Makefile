# New ports collection makefile for:	gwave
# Date created:			16 June 2002
# Whom:				Duncan Barclay <dmlb@dmlb.org>
#
# $FreeBSD$
#

PORTNAME=	gwave
PORTVERSION=	20020122
CATEGORIES=	cad
MASTER_SITES=	http://geda.seul.org/dist/

MAINTAINER=	dmlb@dmlb.org

RUN_DEPENDS=	graph:${PORTSDIR}/graphics/plotutils
LIB_DEPENDS=	geda.16:${PORTSDIR}/cad/libgeda \
		guile.10:${PORTSDIR}/lang/guile \
		guilegtk-1.2.0:${PORTSDIR}/x11-toolkits/guile-gtk

USE_AUTOCONF=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
#CONFIGURE_ARGS=	--enable-gdgeda
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		sp2sp.1

.include <bsd.port.mk>
