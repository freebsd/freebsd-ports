# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	gschem
PORTVERSION=	20010304
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/20010304/ \
		http://geda.seul.org/devel/20010304/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	bruno@tinkerbox.org

BUILD_DEPENDS=	gesym-config:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	geda.12:${PORTSDIR}/cad/libgeda \
		guile.9:${PORTSDIR}/lang/guile

USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
USE_GTK=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-gdgeda
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/gschem

MAN1=		gschem.1

.include <bsd.port.mk>
