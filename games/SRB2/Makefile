PORTNAME=	SRB2
PORTVERSION=	2.2.13
DISTVERSIONPREFIX=	SRB2_release_
PORTREVISION=	1
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
		libgme.so:audio/libgme \
		libopenmpt.so:audio/libopenmpt \
		libpng.so:graphics/png

USES=		cmake localbase:ldflags sdl
CMAKE_ARGS+=	-DSRB2_CONFIG_ASSET_DIRECTORY=${WRKSRC}/assets/installer/ \
		-DSRB2_SDL2_EXE_NAME=${EXE_NAME}

CMAKE_ON=	SRB2_CONFIG_SYSTEM_LIBRARIES
CMAKE_OFF=	SRB2_CONFIG_ENABLE_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	STJr

USE_SDL=	mixer2 sdl2

CXXFLAGS+=	-DDEFAULTWADLOCATION5=${DATADIR}
LDFLAGS+=	-lexecinfo -lm

EXE_NAME=	srb2

post-extract:
	@${MKDIR} ${WRKSRC}/assets/installer
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip srb2.pk3
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip models.dat
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip music.dta
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip player.dta
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip zones.pk3
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v${PORTVERSION:S/.//g}-Full.zip patch.pk3

post-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/srb2.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/models.dat ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/music.dta ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/player.dta ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/zones.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/patch.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/${EXE_NAME} ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
