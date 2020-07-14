# $FreeBSD$

PORTNAME=	warzone2100
PORTVERSION=	3.4.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}_src
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	7z:archivers/p7zip \
		a2x:textproc/asciidoc
LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libsodium.so:security/libsodium \
		libcurl.so:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		cmake bison compiler:c++11-lib gl openal:al pkgconfig \
		qmake:no_env qt:5 sdl tar:xz
USE_GL=		gl glu glew
USE_SDL=	sdl2
USE_QT=		core gui widgets script buildtools_build qmake_build
CMAKE_ARGS=	-DWZ_DISTRIBUTOR="FreeBSD ports" \
		-DCMAKE_DISABLE_FIND_PACKAGE_Asciidoctor=TRUE \
	       	-DCMAKE_DISABLE_FIND_PACKAGE_Git=TRUE \
		-DWZ_ENABLE_WARNINGS_AS_ERRORS=FALSE

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_BOOL=	ENABLE_NLS

.include <bsd.port.mk>
