PORTNAME=	hedgewars
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://www.hedgewars.org/download/releases/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Worms-like turn based strategy game
WWW=		https://www.hedgewars.org

LICENSE=	GPLv2 GFDL
LICENSE_COMB=	multi

LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libpng.so:graphics/png

USES=		cmake:noninja desktop-file-utils fpc gl lua:51 pkgconfig qt:5 \
		sdl tar:bzip2
USE_SDL=	sdl2 mixer2 image2 ttf2 net2
USE_FPC=	opengl libpng rtl-objpas rtl-extra
USE_QT=		core gui widgets network \
		qmake:build buildtools:build \
		linguisttools:build
USE_GL=		gl glu
USE_LDCONFIG=	yes
CMAKE_ON=	NOSERVER

PORTDATA=	*

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	FPC and GHC limitations

OPTIONS_DEFINE=	VIDEOREC
OPTIONS_DEFAULT=VIDEOREC
OPTIONS_SUB=	yes

VIDEOREC_DESC=	Enable video recording (requires ffmpeg)

VIDEOREC_LIB_DEPENDS=	libavcodec.so.58:multimedia/ffmpeg4
VIDEOREC_CMAKE_OFF=	-DNOVIDEOREC=1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/cmake_modules/*.cmake
	@${REINPLACE_CMD} -e "s|'liblua'|'liblua-${LUA_VER}'|" ${WRKSRC}/hedgewars/LuaPas.pas
	@${REINPLACE_CMD} -e "/linklib/ s|lua|&-${LUA_VER}|" ${WRKSRC}/hedgewars/LuaPas.pas
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake_modules/FindLIBAV.cmake

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${INSTALL_DATA} ${WRKSRC}/share/hedgewars/Data/misc/hedgewars.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/misc/hedgewars.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
