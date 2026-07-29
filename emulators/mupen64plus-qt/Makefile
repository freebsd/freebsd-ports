PORTNAME=	mupen64plus-qt
DISTVERSION=	1.17
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Basic launcher for Mupen64Plus
WWW=		https://github.com/dh4/mupen64plus-qt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libquazip1-qt6.so:archivers/quazip
RUN_DEPENDS=	${LOCALBASE}/lib/libmupen64plus.so.2:emulators/mupen64plus-core \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-audio-sdl.so:emulators/mupen64plus-audio-sdl \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-input-sdl.so:emulators/mupen64plus-input-sdl \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-rsp-hle.so:emulators/mupen64plus-rsp-hle \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-video-rice.so:emulators/mupen64plus-video-rice \
		mupen64plus:emulators/mupen64plus-ui-console

USES=		cmake compiler:c++17-lang gl pkgconfig qt:6 sdl
USE_GL=		gl
USE_QT=		base \
		sqldriver-sqlite:run
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	dh4

PORTDOCS=	README.md

PLIST_FILES=	bin/mupen64plus-qt \
		share/man/man6/mupen64plus-qt.6.gz \
		share/applications/mupen64plus-qt.desktop \
		share/pixmaps/mupen64plus-qt.png

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
