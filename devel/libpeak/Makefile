# ex:ts=8
# Ports collection makefile for:	libpeak
# Date created:			Mar 18, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libpeak
PORTVERSION=	0.1.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	SF/peak/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel Events and Asynchronous tasKing Library

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
MAKE_ARGS=	CFLAGS="${CFLAGS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22

.include <bsd.port.mk>
