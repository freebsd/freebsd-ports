# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	glfw
PORTVERSION=	2.7.6
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable framework for OpenGL development

USE_BZIP2=	yes
USE_XORG=	x11 xext xrandr
USE_GL=		glu
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	compile.sh
ALL_TARGET=	x11
INSTALL_TARGET=	x11-install
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.options.mk>

post-extract:
	@${CHMOD} ${BINMODE} ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}| ; \
		 /SOFLAGS/s|-soname |-Wl,-soname,| ; \
		 /CFLAGS_THREAD/s|"-pthread"|"${PTHREAD_CFLAGS}"| ; \
		 /LFLAGS_THREAD/s|"-pthread"|"${PTHREAD_LIBS}"|' ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's|lib/pkgconfig|libdata/pkgconfig|g' ${WRKSRC}/lib/x11/Makefile.x11.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/x11/libglfw.so ${PREFIX}/lib/libglfw.so.0
	${LN} -sf ${PREFIX}/lib/libglfw.so.0 ${PREFIX}/lib/libglfw.so
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile.x11 ${EXAMPLESDIR}/makefile
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.tga ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
