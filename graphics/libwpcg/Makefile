# ex:ts=8
# Ports collection makefile for:	libWPCG
# Date Created:			Nov 18, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libwpcg
PORTVERSION=	0.9.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.paassen.tmfweb.nl/
DISTNAME=	libWPCG-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_GCC=	3.1
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -lGL -lGLU -lglut"

.include <bsd.port.mk>
