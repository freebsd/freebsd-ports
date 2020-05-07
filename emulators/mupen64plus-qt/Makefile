# $FreeBSD$

PORTNAME=	mupen64plus-qt
DISTVERSION=	1.14
CATEGORIES=	emulators

MAINTAINER=	maintainer@hasting.email
COMMENT=	Basic launcher for Mupen64Plus

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libquazip5.so:archivers/quazip
RUN_DEPENDS=	${LOCALBASE}/lib/libmupen64plus.so.2:emulators/mupen64plus-core \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-audio-sdl.so:emulators/mupen64plus-audio-sdl \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-input-sdl.so:emulators/mupen64plus-input-sdl \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-rsp-hle.so:emulators/mupen64plus-rsp-hle \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-video-rice.so:emulators/mupen64plus-video-rice \
		mupen64plus:emulators/mupen64plus-ui-console

USES=		gl qmake qt:5
USE_GL=		gl
USE_QT=		core gui network sql widgets xml \
		buildtools_build \
		sql-sqlite3_run

USE_GITHUB=	yes
GH_ACCOUNT=	dh4

PORTDOCS=	README.md

PLIST_FILES=	bin/mupen64plus-qt \
		man/man6/mupen64plus-qt.6.gz \
		share/applications/mupen64plus-qt.desktop \
		share/pixmaps/mupen64plus-qt.png

OPTIONS_DEFINE=		DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/resources/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/resources/images/mupen64plus.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKSRC}/resources/${PORTNAME}.6 ${STAGEDIR}${MANPREFIX}/man/man6

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
