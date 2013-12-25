# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arx-libertatis
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://cloud.github.com/downloads/arx/ArxLibertatis/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of Arx Fatalis

LICENSE=	GPLv3

LIB_DEPENDS=	libIL.so:${PORTSDIR}/graphics/devil \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libboost_program_options.so:${PORTSDIR}/devel/boost-libs

USE_XZ=		yes
USE_SDL=	sdl
USE_GL=		gl glu
USES=		cmake openal
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR="man" -DDATA_DIR=arx

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS CHANGELOG README.md

OPTIONS_DEFINE=	CRASHREPORTER
CRASHREPORTER_DESC=	Build crash reporter (requires Qt4)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRASHREPORTER}
USE_QT4=	corelib gui network rcc_build moc_build uic_build qmake_build
CMAKE_ARGS+=	-DBUILD_CRASHREPORTER=ON
PLIST_SUB+=	CRASHREPORTER=""
.else
CMAKE_ARGS+=	-DBUILD_CRASHREPORTER=OFF
PLIST_SUB+=	CRASHREPORTER="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
