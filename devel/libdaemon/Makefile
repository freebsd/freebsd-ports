# New ports collection makefile for:	libdaemon
# Date created:		2005-10-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdaemon
PORTVERSION=	0.14
CATEGORIES=	devel
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight C library that eases the writing of UNIX daemons

CONFIGURE_ARGS=	--disable-lynx
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack gnometarget ltverhack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
