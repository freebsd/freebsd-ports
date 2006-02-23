# New ports collection makefile for:	vp
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	vp
PORTVERSION=	1.6
CATEGORIES=	graphics
MASTER_SITES=	http://math.missouristate.edu/~erik/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image viewer for X

USE_SDL=	image
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		vp.1
PLIST_FILES=	bin/vp

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
