# New ports collection makefile for:	libmrproject
# Date created:				17 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmrproject
PORTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	ftp://ftp.codefactory.se/pub/software/mrproject/source/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library backend for MrProject project management application

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libgsf
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_LIBTOOL_VER=	14
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
