PORTNAME=	fceux
DISTVERSION=	2.6.1
CATEGORIES=	emulators games
MASTER_SITES=	SF/fceultra/Source%20Code/${DISTVERSION}%20src/

MAINTAINER=	fuz@fuz.su
COMMENT=	NES emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libminizip.so:archivers/minizip

USES=		cmake desktop-file-utils gl lua:51 pkgconfig qt:5 sdl
USE_GL=		gl glu
USE_QT=		buildtools_build core gui opengl qmake_build sql widgets
USE_SDL=	sdl2

CFLAGS+=	-DPUBLIC_RELEASE
CMAKE_ON=	GLVND

OPTIONS_DEFINE=		DOCS FFMPEG X264 X265
OPTIONS_DEFAULT=	FFMPEG X264 X265
DOCS_CMAKE_BOOL=	QHELP
DOCS_USE=		qt=help,sql
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
X264_LIB_DEPENDS=	libx264.so:multimedia/libx264
X265_LIB_DEPENDS=	libx265.so:multimedia/x265

post-patch:
	${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/fceux.desktop
	${REINPLACE_CMD} -e 's:%%PKGNAME%%:${PKGNAME}:' ${WRKSRC}/scripts/genGitHdr.sh
	${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/src/drivers/Qt/HelpPages.cpp

pre-build-DOCS-on:
	${SETENV} QHELPGENERATOR=${QHELPGENERATOR} PROJECT_ROOT=${WRKSRC} ${SH} ${WRKSRC}/scripts/unix_make_docs.sh

post-install:
	${RM} ${STAGEDIR}${DATADIR}/*.dll
	${RM} ${STAGEDIR}${DATADIR}/*.chm
	# currently broken and not shipped
	${RM} ${STAGEDIR}${PREFIX}/man/man6/fceux-net-server.6

.include <bsd.port.mk>
