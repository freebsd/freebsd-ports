# New ports collection makefile for:	blender
# Date created:				27 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.36
CATEGORIES=	graphics games
MASTER_SITES=	http://public.planetmirror.com/pub/blender/source/ \
		http://download.blender.org/source/ \
		ftp://ftp.cs.umn.edu/pub/blender.org/source/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dyeske@yahoo.com
COMMENT=	3D modeling/rendering/animation/gaming package

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png

PLIST_FILES=	bin/blender
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_SDL=	sdl
USE_GL=		yes

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

do-build:
	@cd ${WRKSRC} && scons

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/blender ${PREFIX}/bin

.include <bsd.port.mk>
