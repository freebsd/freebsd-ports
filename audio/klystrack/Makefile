PORTNAME=	klystrack
DISTVERSION=	1.7.6-make-fix-12
DISTVERSIONSUFFIX=	-gfe6e746
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tracker for making C64/NES/Amiga-style chiptunes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		compiler:c11 desktop-file-utils dos2unix gmake \
		localbase:ldconfig sdl
DOS2UNIX_FILES=	klystron/common.mk klystron/Makefile klystron/src/gui/menu.h \
		klystron/tools/editor/Makefile \
		klystron/tools/makebundle/Makefile Makefile player/Makefile \
		scancode-tool/Makefile
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	kometbomb
GH_TUPLE=	kometbomb:klystron:1074324:klystron/klystron
USE_SDL=	gfx2 image2 mixer2 sdl2 ttf2

MAKE_ENV+=	CFG=release \
		V=1
ALL_TARGET=	build

CFLAGS+=	-fPIC

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e "s#Default.kt#${DATADIR}/Default.kt#" \
		${WRKSRC}/src/main.c

do-install:
.for d in bin share/klystrack share/applications share/pixmaps \
	share/licenses/klystrack lib/klystrack share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/${d}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/bin.release/klystrack \
		${STAGEDIR}${PREFIX}/bin/klystrack
	cd ${WRKSRC}/res && \
		${COPYTREE_SHARE} \* ${STAGEDIR}/${PREFIX}/lib/klystrack/res/
	cd ${WRKSRC}/key && \
		${COPYTREE_SHARE} \* ${STAGEDIR}/${PREFIX}/lib/klystrack/key/
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/klystrack.1 \
		${STAGEDIR}${MANPREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/Default.kt \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/linux/klystrack.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icon/256x256.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/klystrack.png

.include <bsd.port.mk>
