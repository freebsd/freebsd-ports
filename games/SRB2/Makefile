PORTNAME=	SRB2
PORTVERSION=	2.2.15
DISTVERSIONPREFIX=	SRB2_release_
CATEGORIES=	games
MASTER_SITES=	https://github.com/STJr/SRB2/releases/download/SRB2_release_${PORTVERSION}/:assets
DISTFILES+=	SRB2-v${PORTVERSION:C/\.//g}-Full.zip:assets
EXTRACT_ONLY=	STJr-SRB2-SRB2_release_${PORTVERSION}_GH0.tar.gz

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	3D Sonic the Hedgehog fangame
WWW=		https://www.srb2.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png

USES=		cmake localbase:ldflags sdl
CMAKE_ARGS+=	-DSRB2_CONFIG_ASSET_DIRECTORY=${WRKSRC}/assets/installer/ \
		-DSRB2_SDL2_EXE_NAME=${EXE_NAME}

USE_GITHUB=	yes
GH_ACCOUNT=	STJr

USE_SDL=	mixer2 sdl2

LDFLAGS+=	-lexecinfo -lm

EXE_NAME=	srb2

OPTIONS_DEFINE=	GME OPENMPT UPNP
OPTIONS_DEFAULT=	GME OPENMPT UPNP

GME_DESC=	Game Music Emu support for VGM/NSF/SPC music
OPENMPT_DESC=	Tracker music playback via libopenmpt

GME_LIB_DEPENDS=	libgme.so:audio/libgme
GME_CMAKE_BOOL=		SRB2_CONFIG_USE_GME
GME_CMAKE_ON=		-DSRB2_CONFIG_SYSTEM_LIBRARIES:BOOL=ON

OPENMPT_LIB_DEPENDS=	libopenmpt.so:audio/libopenmpt
OPENMPT_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libopenmpt

UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_miniupnpc

post-extract:
	@${MKDIR} ${WRKSRC}/assets/installer
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip srb2.pk3
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip models.dat
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip music.pk3
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip characters.pk3
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip zones.pk3

post-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/srb2.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/models.dat ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/music.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/characters.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/zones.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/${EXE_NAME} ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
