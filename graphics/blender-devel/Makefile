# New ports collection makefile for:	blender
# Date created:				27 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.28c
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
USE_MESA=	yes

CONFIGURE_ARGS=	--disable-oggtest --disable-vorbistest --disable-sdltest

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include"

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
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
		s|-lSDL|-lSDL-1.1 -L${X11BASE}/lib|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

	@${REINPLACE_CMD} -e \
		's|-Wall||' \
		${WRKSRC}/source/blender/python/api2_2x/Makefile.in \
		${WRKSRC}/source/blender/python/Makefile.in

post-configure:
	@${FIND} ${WRKSRC} -name "Makefile" | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|-lesd||; \
		s|-lsmpeg||; \
		s|-lvorbisfile||; \
		s|-lvorbis||; \
		s|-logg||'

.include <bsd.port.mk>
