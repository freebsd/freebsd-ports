# New ports collection makefile for:	eio
# Date created:				02 April 2012
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	eio
DISTVERSION=	0.1.0.65643
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/snapshots/2011-11-28/ \
		http://files.roorback.net/e17/base/

MAINTAINER=	magik@roorback.net
COMMENT=	Enlightenment Input/Output Library

LICENSE=	LGPL21

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina ecore libtool_hack
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
