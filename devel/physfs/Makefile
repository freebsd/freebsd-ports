# New ports collection makefile for:	physfs
# Date Created:		26 July 2003
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	physfs
PORTVERSION=	0.1.8
CATEGORIES=	devel
MASTER_SITES=	http://icculus.org/${PORTNAME}/downloads/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A library to provide abstract access to various archives

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ARGS=	--program-transform-name=''

.include <bsd.port.mk>
