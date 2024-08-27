PORTNAME=	openra
DISTVERSIONPREFIX=	release-
DISTVERSION=	20210321
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://download.ip2location.com/lite/:ip2location
DISTFILES=	IP2LOCATION-LITE-DB1.IPV6.BIN.ZIP:ip2location

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ee0d37f2b1c4.patch:-p1 # https://github.com/OpenRA/OpenRA/pull/20041

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer re-envisioning of early RTS games by Westwood Studios
WWW=		https://www.openra.net/

LICENSE=	GPLv3

BUILD_DEPENDS=	msbuild:devel/msbuild
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgdiplus.so:x11-toolkits/libgdiplus
NUGET_DEPENDS=	DiscordRichPresence=1.0.150 \
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
		Newtonsoft.Json=12.0.2 \
		NuGet.CommandLine=4.4.1 \
		OpenRA-Eluant=1.0.17 \
		OpenRA-Freetype6=1.0.4 \
		OpenRA-FuzzyLogicLibrary=1.0.1 \
		OpenRA-Open.NAT=1.0.0 \
		OpenRA-OpenAL-CS=1.0.16 \
		OpenRA-SDL2-CS=1.0.28 \
		SharpZipLib=1.2.0 \
		StyleCop.Analyzers=1.1.118 \
		rix0rrr.BeaconLib=1.0.2

USE_GITHUB=	yes
GH_PROJECT=	OpenRA

NO_ARCH=	yes
USES=		desktop-file-utils gmake lua:51 mono:nuget openal:soft sdl \
		shared-mime-info
USE_SDL=	sdl2
MAKE_ENV=	prefix="${PREFIX}" \
		gameinstalldir="${DATADIR}"
ALL_TARGET=	all
INSTALL_TARGET=	install install-man install-linux-appdata install-linux-shortcuts
PORTDATA=	*

.include <bsd.port.pre.mk>

.if defined(MONO_DEFAULT) && ${MONO_DEFAULT} > 6
BROKEN=		fails to build with Mono version ${MONO_DEFAULT}: error MSB4184: The expression ""Program.cs".GetPathsOfAllDirectoriesAbove()" cannot be evaluated. Method 'System.String.GetPathsOfAllDirectoriesAbove' not found.
.endif

post-extract:
	${CP} ${_DISTDIR}/${DISTFILES:C/:.*//:MIP2LOCATION-*} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} \
		-e 's/ -verbosity:m//' \
		-e '/echo/!s/	@/	/' \
		-e '/^VERSION/s/=.*/=	${GH_TAGNAME}/' \
		-e '/^all:/s/$$/ version/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' \
		-e '/target/s,$${DIR}/,,' \
		${WRKSRC}/configure-system-libraries.sh

do-test:
	@(cd ${TEST_WRKSRC} && mono \
		${NUGET_PACKAGEDIR}/NUnit.ConsoleRunner/tools/nunit3-console.exe \
		--noresult bin/OpenRA.Test.dll)

.include <bsd.port.post.mk>
