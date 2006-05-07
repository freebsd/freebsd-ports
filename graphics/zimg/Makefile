# New ports collection makefile for:	zimg
# Date created:		20 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	zimg
PORTVERSION=	5.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image-generator that uses ASCII input files to create PNGs/EDFs

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-dynaload-cc="${CC}" \
		--with-dynaload-cflags="${CFLAGS} -shared" \
		--with-gd-includes="${LOCALBASE}/include" \
		--with-gd-lib="${LOCALBASE}/lib"

MAN1=		zimg.1
PLIST_FILES=	include/zimg.h bin/zimg

CFLAGS+=	-DHAVE_GD_FREETYPE

.include <bsd.port.mk>
