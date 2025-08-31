PORTNAME=	openspades
PORTVERSION=	0.1.3
PORTREVISION=	5
DISTVERSIONPREFIX=	v
CATEGORIES=	games
MASTER_SITES=	https://github.com/yvt/openspades-paks/releases/download/r33/:data
DISTFILES=	OpenSpadesDevPackage-r33.zip:data

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Compatible client of Ace of Spades
WWW=		https://openspades.yvt.jp/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	bundles non-portable AngelScript

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libopusfile.so:audio/opusfile

USE_GITHUB=	yes
GH_ACCOUNT=	yvt

USES=		cmake:insource compiler:c++11-lib desktop-file-utils dos2unix \
		gl gnome magick:build openal sdl xorg
CMAKE_ARGS=	-DOPENSPADES_RESOURCES=OFF \
		-DOPENSPADES_INSTALL_BINARY="bin" \
		-DOPENSPADES_INSTALL_RESOURCES="${DATADIR_REL}"
DOS2UNIX_FILES=	Sources/AngelScript/source/as_config.h
USE_SDL=	sdl2 image2
USE_GL=		gl glew

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKDIR}/Nonfree/*.pak ${WRKDIR}/OfficialMods/*.pak \
	    ${WRKSRC}/Resources/

post-patch:
	@${REINPLACE_CMD} -e 's|Xext|${LOCALBASE}/lib/lib&.so|' ${WRKSRC}/Sources/CMakeLists.txt

post-install:
	cd ${WRKSRC}/Resources/ && ${COPYTREE_SHARE} "Gfx Locales Maps Models PackageInfo.json Scripts Shaders Sounds Textures *.pak" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
