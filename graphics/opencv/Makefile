# New ports collection makefile for:   opencv - open source computer vision
# library from Intel
# Date created:                05 March 2005
# Whom:                        Marc Abramowitz (http://marc.abramowitz.info)
#
# $FreeBSD$
#

PORTNAME=	opencv
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	opencvlibrary
DISTNAME=	opencv-${PORTVERSION}

MAINTAINER=	msabramo@yahoo.com
COMMENT=	Open Source Computer Vision Library from Intel

USE_AUTOTOOLS=	libtool:15
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

LDFLAGS=	${PTHREAD_LIBS}
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
