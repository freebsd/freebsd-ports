# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	geda-utils
PORTVERSION=	20040111
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	gEDA utilities

RUN_DEPENDS=	${LOCALBASE}/share/gEDA/sym:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	geda.20:${PORTSDIR}/cad/libgeda \
		guile.15:${PORTSDIR}/lang/guile

USE_LIBTOOL=	yes
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-gdgeda
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
