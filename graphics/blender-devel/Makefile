# New ports collection makefile for:	blender
# Date created:				27 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.42a
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/ \
		ftp://ftp.cs.umn.edu/pub/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dyeske@yahoo.com
COMMENT=	3D modeling/rendering/animation/gaming package

BUILD_DEPENDS=	${X11BASE}/lib/libftgl.a:${PORTSDIR}/graphics/ftgl
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		SDL.11:${PORTSDIR}/devel/sdl12 \
		Half.2:${PORTSDIR}/graphics/OpenEXR \
		gettextpo.1:${PORTSDIR}/devel/gettext \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg-devel

BROKEN=		Does not build
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

PLIST_FILES=	bin/blender
USE_X_PREFIX=	yes
USE_PYTHON=	2.3
USE_SCONS=	yes
USE_SDL=	sdl
USE_GL=		yes

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/../install/freebsd/blender ${PREFIX}/bin

.include <bsd.port.post.mk>
