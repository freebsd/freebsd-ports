# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	glfw
PORTVERSION=	2.7.9
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
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	include/GL/glfw.h \
		lib/libglfw.a \
		lib/libglfw.so \
		lib/libglfw.so.0 \
		libdata/pkgconfig/libglfw.pc

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	*.html

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	*.pdf *.sty *.tex *.txt

PORTEXAMPLES=	*

EXAMPLESSRCDIR1=	${WRKSRC}/examples
EXAMPLES_FILES1=	boing gears heightmap listmodes mipmaps mtbench mthello \
			pong3d splitview triangle wave

EXAMPLESSRCDIR2=	${WRKSRC}/tests
EXAMPLESDIR2=		${EXAMPLESDIR}/tests
EXAMPLES_FILES2=	accuracy defaults dynamic events fsaa fsinput iconify \
			joysticks peter reopen tearing version

NO_STAGE=	yes
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
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES1:S|^|${EXAMPLESSRCDIR1}/|} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLESSRCDIR1}/*.tga ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR2}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES2:S|^|${EXAMPLESSRCDIR2}/|} ${EXAMPLESDIR2}
.endif

.include <bsd.port.mk>
