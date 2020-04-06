# $FreeBSD$

PORTNAME=	openra
DISTVERSIONPREFIX=	release-
DISTVERSION=	20200202
PORTREVISION=	2
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	82ae5adc4631.patch:-p1 # https://github.com/OpenRA/OpenRA/pull/17744
PATCHFILES+=	f2177f57e6f4.patch:-p1 # https://github.com/OpenRA/OpenRA/pull/17744

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multiplayer re-envisioning of early RTS games by Westwood Studios

LICENSE=	GPLv3

BUILD_DEPENDS=	msbuild:devel/msbuild
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgdiplus.so:x11-toolkits/libgdiplus
NUGET_DEPENDS=	MaxMind.Db=2.6.1 \
		Microsoft.NETFramework.ReferenceAssemblies=1.0.0 \
		Microsoft.NETFramework.ReferenceAssemblies.net472=1.0.0 \
		NUnit=3.12.0 \
		NUnit.Console=3.11.1 \
		NUnit.ConsoleRunner=3.11.1 \
		NUnit.Extension.NUnitProjectLoader=3.6.0 \
		NUnit.Extension.NUnitV2Driver=3.8.0 \
		NUnit.Extension.NUnitV2ResultWriter=3.6.0 \
		NUnit.Extension.TeamCityEventListener=1.0.7 \
		NUnit.Extension.VSProjectLoader=3.8.0 \
		NUnit3TestAdapter=3.16.1 \
		NuGet.CommandLine=4.4.1 \
		OpenRA-Eluant=1.0.15 \
		OpenRA-Freetype6=1.0.4 \
		OpenRA-FuzzyLogicLibrary=1.0.1 \
		OpenRA-Open.NAT=1.0.0 \
		OpenRA-OpenAL-CS=1.0.14 \
		OpenRA-SDL2-CS=1.0.24 \
		SharpZipLib=1.2.0 \
		StyleCop.Analyzers=1.1.118 \
		rix0rrr.BeaconLib=1.0.2

USE_GITHUB=	yes
GH_PROJECT=	OpenRA

NO_ARCH=	yes
USES=		desktop-file-utils gmake lua:51,run mono:nuget openal:soft sdl \
		shared-mime-info
USE_SDL=	sdl2
MAKE_ENV=	prefix="${PREFIX}" \
		gameinstalldir="${DATADIR}"
ALL_TARGET=	all
INSTALL_TARGET=	install install-man-page \
		install-linux-mime install-linux-shortcuts
PORTDATA=	*

OPTIONS_DEFINE=	TEST

TEST_MAKE_ENV=	HOME="${WRKDIR}"
TEST_ALL_TARGET=test

post-patch:
	${REINPLACE_CMD} \
		-e 's/ -verbosity:m//' \
		-e '/echo/!s/	@/	/' \
		-e '/^VERSION/s/=.*/=	${GH_TAGNAME}/' \
		-e '/^core:/s/$$/ version/' \
		${WRKSRC}/Makefile
	${SED} 's/@LIBLUA51@/liblua-${LUA_VER}.so/' \
		${WRKSRC}/thirdparty/Eluant.dll.config.in \
		>${WRKSRC}/Eluant.dll.config

.include <bsd.port.mk>
