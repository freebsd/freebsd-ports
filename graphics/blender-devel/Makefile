# New ports collection makefile for:	blender
# Date created:				27 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.31a
PORTREVISION=	1
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dyeske@yahoo.com
COMMENT=	3D modeling/rendering/animation/gaming package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_SDL=	yes
USE_GL=		yes

CONFIGURE_ARGS=	--with-sdl=${LOCALBASE} --disable-oggtest --disable-vorbistest --disable-sdltest

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

.if exists(${LOCALBASE}/lib/libfreetype.so.9) && !defined(WITHOUT_FREETYPE)
WITH_FREETYPE=	yes
.endif

.if exists(${LOCALBASE}/lib/libopenal.so) && !defined(WITHOUT_OPENAL)
WITH_OPENAL=	yes
.endif

.if defined(WITH_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-freetype2=${LOCALBASE}
.endif

.if defined(WITH_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
CONFIGURE_ARGS+=	--enable-openal
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/intern/SoundSystem/intern/SND_WaveCache.cpp

	@${REINPLACE_CMD} -E -e \
		's|^program_transform_name.+$$||; \
		s| -DFreeBSD||; \
		s|-lSDL|-lSDL-1.1|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

	@${REINPLACE_CMD} -e \
		's|-Wall||' \
		${WRKSRC}/source/blender/python/api2_2x/Makefile.in \
		${WRKSRC}/source/blender/python/Makefile.in

.include <bsd.port.mk>
