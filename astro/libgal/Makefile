# ports collection makefile for:	linrad
# Date created:		7 July 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	libgal
PORTVERSION=	0.1.0
CATEGORIES=	astro hamradio
MASTER_SITES=	http://homepage.mac.com/pclwillmott/GAL/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	General Astrodynamics Library

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}
USE_LDCONFIG=	yes

.include <bsd.port.mk>
