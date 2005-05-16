# New ports collection makefile for:	libgeda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	libgeda
PORTVERSION=	20050313
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	gEDA tools base utility library

LIB_DEPENDS=	gdgeda.6:${PORTSDIR}/graphics/libgdgeda \
		guile.15:${PORTSDIR}/lang/guile

USE_LIBTOOL_VER=	15
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-gdgeda
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		libgedadoc

.include <bsd.port.mk>
