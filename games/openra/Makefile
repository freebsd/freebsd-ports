# $FreeBSD$

PORTNAME=	openra
DISTVERSIONPREFIX=	release-
DISTVERSION=	20200503
CATEGORIES=	games
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/SDL2-CS/releases/download/20190907/:SDL2_CS \
		https://github.com/${GH_ACCOUNT}/OpenAL-CS/releases/download/20200316/:OpenAL_CS \
		https://github.com/${GH_ACCOUNT}/Eluant/releases/download/20160124/:Eluant \
		https://download.ip2location.com/lite/:ip2location
DISTFILES=	SDL2-CS.dll:SDL2_CS \
		SDL2-CS.dll.config:SDL2_CS \
		OpenAL-CS.dll:OpenAL_CS \
		OpenAL-CS.dll.config:OpenAL_CS \
		Eluant.dll:Eluant \
		IP2LOCATION-LITE-DB1.IPV6.BIN.ZIP:ip2location
EXTRACT_ONLY=	${DISTFILES:C/:.*//:N*.config:N*.dll:N*.nupkg}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multiplayer re-envisioning of early RTS games by Westwood Studios

LICENSE=	GPLv3

BUILD_DEPENDS=	msbuild:devel/msbuild
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgdiplus.so:x11-toolkits/libgdiplus
NUGET_DEPENDS=	FuzzyLogicLibrary=1.2.0 \
		NUnit=3.0.1 \
		NUnit.Console=3.0.1 \
		Open.NAT=2.1.0 \
		SharpZipLib=1.1.0 \
		StyleCop.MSBuild=4.7.49 \
		StyleCopPlus.MSBuild=4.7.49.5 \
		rix0rrr.BeaconLib=1.0.1

USE_GITHUB=	yes
GH_PROJECT=	OpenRA

NO_ARCH=	yes
USES=		desktop-file-utils gmake lua:51,run mono:nuget openal:soft sdl \
		shared-mime-info shebangfix
USE_SDL=	sdl2
NUGET_LAYOUT=	flat
NUGET_PACKAGEDIR=${WRKSRC}/thirdparty/download
SHEBANG_FILES=	launch-dedicated.sh
MAKE_ENV=	prefix="${PREFIX}" \
		gameinstalldir="${DATADIR}"
ALL_TARGET=	all
INSTALL_TARGET=	install install-man-page \
		install-linux-mime install-linux-shortcuts
PORTDATA=	*

OPTIONS_DEFINE=	TEST

TEST_MAKE_ENV=	HOME="${WRKDIR}"
TEST_ALL_TARGET=test

post-extract:
	${CP} ${DISTFILES:C/:.*//:N*.nupkg:N*.tar*:S,^,${_DISTDIR}/,} \
		${NUGET_PACKAGEDIR}
	${CP} ${_DISTDIR}/${DISTFILES:C/:.*//:MIP2LOCATION-*} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} \
		-e '/MSBUILD.*-t:restore/d' \
		-e '/echo/!s/	@/	/' \
		-e '/^VERSION/s/=.*/=	${GH_TAGNAME}/' \
		-e '/^core:/s/$$/ version/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/noget\.sh/d' \
			${WRKSRC}/thirdparty/fetch-thirdparty-deps.sh
	${SED} 's/@LIBLUA51@/liblua-${LUA_VER}.so/' \
		${WRKSRC}/thirdparty/Eluant.dll.config.in \
		>${WRKSRC}/Eluant.dll.config

.include <bsd.port.mk>
