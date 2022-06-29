# Created by: Timothy Beyer <beyert@cs.ucr.edu>

PORTNAME=	reicast
PORTVERSION=	0.20201231
PORTREVISION=	1
CATEGORIES=	emulators games

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Multi-platform Sega Dreamcast emulator

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libao.so:audio/libao \
		libasound.so:audio/alsa-lib \
		libcurl.so:ftp/curl \
		libevdev.so:devel/libevdev \
		libpulse.so:audio/pulseaudio \
		libudev.so:devel/libudev-devd

USES=	cmake compiler gl xorg

.include <bsd.port.options.mk>

USE_GCC=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DOPENGL_EGL_INCLUDE_DIR:PATH=${LOCALBASE}/include/EGL \
		-DOPENGL_GLX_INCLUDE_DIR:PATH=${LOCALBASE}/include/GL \
		-DOPENGL_INCLUDE_DIR:PATH=${LOCALBASE}/include/GL \
		-DOPENGL_opengl_LIBRARY:PATH=${LOCALBASE}/lib/libGL.so

.if ${ARCH} == i386
USE_BINUTILS=	yes
CXXFLAGS+=	-DSIMPLELINK
.endif

USE_GITHUB=	yes
GH_TUPLE=	reicast:reicast-emulator:0bd6ea3 \
		yuikns:intrin:ae63327:intrin/libswirl/deps/intrin

USE_XORG=	ice sm x11 xext
USE_GL=	egl gbm gl

PLIST_FILES=	bin/reicast

do-install:
	${INSTALL} ${WRKDIR}/.build/${PORTNAME} \
		${STAGEDIR}/${PREFIX}/bin/${PORTNAME};
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
