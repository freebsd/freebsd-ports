# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	geda-utils
PORTVERSION=	20030223
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	gEDA utilities

BUILD_DEPENDS=	gesym-config:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	geda.18:${PORTSDIR}/cad/libgeda \
		guile.15:${PORTSDIR}/lang/guile

USE_LIBTOOL=	yes
USE_GETOPT_LONG=yes
AUTOCONF=	autoconf
USE_GNOME=	gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-gdgeda
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
