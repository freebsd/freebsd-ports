# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openspades
PORTVERSION=	0.1.3
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	games
MASTER_SITES=	https://github.com/yvt/openspades-paks/releases/download/r33/:data
DISTFILES=	OpenSpadesDevPackage-r33.zip:data

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Compatible client of Ace of Spades

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64
ONLY_FOR_ARCHS_REASON=	bundles non-portable AngelScript

BUILD_DEPENDS=	convert:graphics/ImageMagick6 # for building icons
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libopusfile.so:audio/opusfile

USE_GITHUB=	yes
GH_ACCOUNT=	yvt

USES=		cmake:insource compiler:c++11-lib desktop-file-utils dos2unix \
		gl gnome openal sdl xorg
CMAKE_ARGS=	-DOPENSPADES_RESOURCES=OFF \
		-DOPENSPADES_INSTALL_MAN="man/man6" \
		-DOPENSPADES_INSTALL_BINARY="bin" \
		-DOPENSPADES_INSTALL_RESOURCES="${DATADIR_REL}"
DOS2UNIX_FILES=	Sources/AngelScript/source/as_config.h
USE_SDL=	sdl2 image2
USE_GL=		gl glew
INSTALLS_ICONS=	yes

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
