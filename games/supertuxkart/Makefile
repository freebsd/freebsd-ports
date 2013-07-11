# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	supertuxkart
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/supertuxkart/SuperTuxKart/${PORTVERSION}
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free 3D kart racing game

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	vorbisfile:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg \
		fribidi:${PORTSDIR}/converters/fribidi \
		curl:${PORTSDIR}/ftp/curl \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GL=		gl glu glut
USE_OPENAL=	al alut
USES=		cmake gettext
USE_GMAKE=	yes
USE_SDL=	sdl
USE_DOS2UNIX=	lib/irrlicht/source/Irrlicht/Makefile
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/SuperTuxKart-${PORTVERSION}

PORTDOCS=	*

IRR_CPPFLAGS=	-DNO_IRR_USE_NON_SYSTEM_JPEG_LIB_ \
		-DNO_IRR_USE_NON_SYSTEM_LIB_PNG_ \
		-DNO_IRR_USE_NON_SYSTEM_ZLIB_ \
		-DNO_IRR_COMPILE_WITH_BZIP2_ \
		-DNO_IRR_COMPILE_WITH_JOYSTICK_EVENTS_

post-patch:
	@${REINPLACE_CMD} -e 's|libIrrlicht.a|& -L${LOCALBASE}/lib -lpng -ljpeg|' ${WRKSRC}/CMakeLists.txt

pre-build:
	cd ${WRKSRC}/lib/irrlicht/source/Irrlicht/ && \
		${SETENV} ${MAKE_ENV} CPPFLAGS="${CPPFLAGS} ${IRR_CPPFLAGS}" \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc
.endif

.include <bsd.port.post.mk>
