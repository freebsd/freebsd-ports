# New ports collection makefile for:	gnetlist
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	gnetlist
PORTVERSION=	20020209
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/20020209/ \
		http://geda.seul.org/devel/20020209/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	bruno@tinkerbox.org

LIB_DEPENDS=	geda.15:${PORTSDIR}/cad/libgeda \
		guile.10:${PORTSDIR}/lang/guile
BUILD_DEPENDS=	gesym-config:${PORTSDIR}/cad/geda-symbols

USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-gdgeda
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
DISTNAME=	geda-${PORTNAME}-${PORTVERSION}

MAN1=		gnetlist.1

.include <bsd.port.mk>
