# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	glfw
PORTVERSION=	2.7.7
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Portable framework for OpenGL development

LICENSE=	ZLIB

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		drm:${PORTSDIR}/graphics/libdrm

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	compile.sh
ALL_TARGET=	x11
INSTALL_TARGET=	x11-install
USE_XORG=	x11 xau xcb xdamage xdmcp xext xfixes xrandr xrender xxf86vm
USE_GL=		glu
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	include/GL/glfw.h \
		lib/libglfw.a \
		lib/libglfw.so \
		lib/libglfw.so.0 \
		libdata/pkgconfig/libglfw.pc

PORTDOCS=	*.pdf
PORTEXAMPLES=	Makefile.x11.in *.c *.tga

.include <bsd.port.options.mk>

post-extract:
	@${CHMOD} ${BINMODE} ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}| ; \
		 /SOFLAGS/s|-soname |-Wl,-soname,| ; \
		 /CFLAGS_THREAD/s|"-pthread"|"${PTHREAD_CFLAGS}"| ; \
		 /LFLAGS_THREAD/s|"-pthread"|"${PTHREAD_LIBS}"|' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's|lib/pkgconfig|libdata/pkgconfig|g' ${WRKSRC}/lib/x11/Makefile.x11.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/x11/libglfw.so ${PREFIX}/lib/libglfw.so.0
	${LN} -sf ${PREFIX}/lib/libglfw.so.0 ${PREFIX}/lib/libglfw.so

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
.for e in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${e} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
