# New ports collection makefile for:  	kyra
# Date created:				10.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	kyra
PORTVERSION=	2.0.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kyra is a simple Sprite engine written in C++

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_LIBTOOL_VER=	13
USE_SDL=	image sdl
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=		CPPFLAGS="-I${X11BASE}/include"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
