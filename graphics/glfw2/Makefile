# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	glfw
PORTVERSION=	2.7.9
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable framework for OpenGL development

LICENSE=	ZLIB

USES=		gl tar:bzip2 xorg
GNU_CONFIGURE=	yes
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

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	*.html

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	*.pdf *.sty *.tex *.txt

PORTEXAMPLES=	*

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

EXAMPLESSRCDIR1=	${WRKSRC}/examples
EXAMPLES_FILES1=	boing gears heightmap listmodes mipmaps mtbench \
			mthello pong3d splitview triangle wave

EXAMPLESSRCDIR2=	${WRKSRC}/tests
EXAMPLESDIR2=		${EXAMPLESDIR}/tests
EXAMPLES_FILES2=	accuracy defaults dynamic events fsaa fsinput iconify \
			joysticks peter reopen tearing version

OPTIONS_DEFINE=	DOCS EXAMPLES

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limit:^2\..*

post-extract:
	@${CHMOD} ${BINMODE} ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|; \
		 /SOFLAGS/s|-soname |-Wl,-soname,|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} \
		-e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/lib/x11/Makefile.x11.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/x11/libglfw.so \
		${STAGEDIR}${PREFIX}/lib/libglfw.so.0
	${LN} -sf ${PREFIX}/lib/libglfw.so.0 ${STAGEDIR}${PREFIX}/lib/libglfw.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libglfw.so.0

	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES1:S|^|${EXAMPLESSRCDIR1}/|} \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLESSRCDIR1}/*.tga ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR2}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES2:S|^|${EXAMPLESSRCDIR2}/|} \
		${STAGEDIR}${EXAMPLESDIR2}

.include <bsd.port.mk>
