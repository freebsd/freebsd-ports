# New ports collection makefile for:	ppracer
# Date created:				28 May, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ppracer
DISTVERSION=	0.5alpha
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/ppracer/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	3D Downhill racing game... kindof like TuxRacer Improved

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_SDL=	mixer sdl
USE_GL=		yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
