# New ports collection makefile for:	oregano
# Date created:			19 Feb 2001
# Whom:				Anders Andersson <anders@hack.org>
#
# $FreeBSD$
#

PORTNAME=	oregano
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://people.imendio.com/richard/oregano/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Schematic capture and simulation of electrical circuits

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnomeprint libglade
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
