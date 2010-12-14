# New ports collection makefile for:	eina
# Date created:		Dec 10 2009
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	eina
DISTVERSION=	1.0.0.beta
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2010-10-03/base/

MAINTAINER=	magik@roorback.net
COMMENT=	Enlightenment API for data types

LICENSE=	LGPL21
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	librt_hack libtool_hack
USE_ICONV=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
