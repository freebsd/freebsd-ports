# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hedgewars
PORTVERSION=	0.9.25
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.hedgewars.org/download/releases/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Worms-like turn based strategy game

LICENSE=	GPLv2 GFDL
LICENSE_COMB=	multi

BUILD_DEPENDS=		${${ARCH}_BUILD_DEPENDS}
i386_BUILD_DEPENDS=	ghc:lang/ghc
LIB_DEPENDS=		libphysfs.so:devel/physfs \
			libpng.so:graphics/png

USES=		cmake:noninja desktop-file-utils fpc gl lua:51 pkgconfig qt:5 \
		sdl tar:bzip2
USE_SDL=	sdl2 mixer2 image2 ttf2 net2
USE_FPC=	opengl libpng rtl-objpas
USE_QT=		core gui widgets network \
		qmake_build buildtools_build \
		linguisttools_build
USE_GL=		gl glu glew
USE_LDCONFIG=	yes

PLIST_FILES=	bin/${PORTNAME} bin/hwengine \
		share/appdata/hedgewars.appdata.xml \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png \
		share/pixmaps/${PORTNAME}.xpm \
		lib/libphyslayer.so \
		lib/libphyslayer.so.1.0
PORTDATA=	*

OPTIONS_DEFINE=	SERVER VIDEOREC
OPTIONS_DEFAULT=SERVER VIDEOREC
OPTIONS_EXCLUDE_i386=	VIDEOREC  # some pascal issues preventing to use it

SERVER_DESC=	Build server (requires haskell)
VIDEOREC_DESC=	Enable video recording (requires ffmpeg)

VIDEOREC_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
VIDEOREC_PLIST_FILES=	lib/libavwrapper.so \
			lib/libavwrapper.so.1.0
VIDEOREC_CMAKE_OFF=	-DNOVIDEOREC=1

SERVER_RUN_DEPENDS=	hedgewars-server:games/hedgewars-server

CMAKE_ON=		NOSERVER

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/cmake_modules/*.cmake

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${INSTALL_DATA} ${WRKSRC}/share/hedgewars/Data/misc/hedgewars.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/misc/hedgewars.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
