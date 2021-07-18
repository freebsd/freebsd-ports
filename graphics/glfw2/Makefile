# Created by: Igor Pokrovsky <tiamat@comset.net>

PORTNAME=	glfw
PORTVERSION=	2.7.9
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable framework for OpenGL development

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gl tar:bzip2 xorg
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	compile.sh
ALL_TARGET=	x11
INSTALL_TARGET=	x11-install
USE_XORG=	xi xrandr
USE_GL=		glu
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-w

PLIST_FILES=	include/GL/glfw.h lib/libglfw.a lib/libglfw.so \
		lib/libglfw.so.0 libdata/pkgconfig/libglfw.pc

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS EXAMPLES

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limit:^2\..*

post-extract:
	@${CHMOD} +x ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|; \
		 /SOFLAGS/s|-soname |-Wl,-soname,|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} \
		-e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/lib/x11/Makefile.x11.in

post-install:
	${INSTALL_LIB} ${WRKSRC}/lib/x11/libglfw.so ${STAGEDIR}${PREFIX}/lib/libglfw.so.0
	${LN} -sf libglfw.so.0 ${STAGEDIR}${PREFIX}/lib/libglfw.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.pdf *.sty *.tex *.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in boing gears heightmap listmodes mipmaps mtbench mthello pong3d splitview triangle wave
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/examples/*.tga ${STAGEDIR}${EXAMPLESDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/tests
.for f in accuracy defaults dynamic events fsaa fsinput iconify joysticks peter reopen tearing version
	${INSTALL_PROGRAM} ${WRKSRC}/tests/${f} ${STAGEDIR}${EXAMPLESDIR}/tests
.endfor

.include <bsd.port.mk>
