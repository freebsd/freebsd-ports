# New ports collection makefile for:	libgeda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	libgeda
PORTVERSION=	20030223
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	gEDA tools base utility library

LIB_DEPENDS=	gdgeda.5:${PORTSDIR}/graphics/libgdgeda \
		guile.15:${PORTSDIR}/lang/guile

USE_LIBTOOL=		yes
#USE_AUTOCONF_VER=	253

USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-gdgeda
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
