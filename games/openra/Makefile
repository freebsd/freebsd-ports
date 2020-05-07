# $FreeBSD$

PORTNAME=	openra
DISTVERSIONPREFIX=	release-
DISTVERSION=	20200503
CATEGORIES=	games
MASTER_SITES=	https://download.ip2location.com/lite/:ip2location
DISTFILES=	IP2LOCATION-LITE-DB1.IPV6.BIN.ZIP:ip2location

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	e13fd693c386.patch:-p1 # https://github.com/OpenRA/OpenRA/pull/17744
PATCHFILES+=	85096c4ba2fb.patch:-p1 # https://github.com/OpenRA/OpenRA/pull/17744

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multiplayer re-envisioning of early RTS games by Westwood Studios

LICENSE=	GPLv3

BUILD_DEPENDS=	msbuild:devel/msbuild
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgdiplus.so:x11-toolkits/libgdiplus
NUGET_DEPENDS=	Microsoft.NETFramework.ReferenceAssemblies=1.0.0 \
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
		OpenRA-Eluant=1.0.17 \
		OpenRA-Freetype6=1.0.4 \
		OpenRA-FuzzyLogicLibrary=1.0.1 \
		OpenRA-Open.NAT=1.0.0 \
		OpenRA-OpenAL-CS=1.0.16 \
		OpenRA-SDL2-CS=1.0.26 \
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
INSTALL_TARGET=	install install-man-page \
		install-linux-mime install-linux-shortcuts
PORTDATA=	*

post-extract:
	${CP} ${_DISTDIR}/${DISTFILES:C/:.*//:MIP2LOCATION-*} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} \
		-e 's/ -verbosity:m//' \
		-e '/echo/!s/	@/	/' \
		-e '/^VERSION/s/=.*/=	${GH_TAGNAME}/' \
		-e '/^core:/s/$$/ version/' \
		${WRKSRC}/Makefile
.if defined(PATCHFILES)
	${CHMOD} +x ${WRKSRC}/configure-system-libraries.sh
.endif
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' \
		-e '/target/s,$${DIR}/,,' \
		${WRKSRC}/configure-system-libraries.sh

do-test:
	@(cd ${TEST_WRKSRC} && mono \
		${NUGET_PACKAGEDIR}/NUnit.ConsoleRunner/tools/nunit3-console.exe \
		--noresult OpenRA.Test.nunit)

.include <bsd.port.mk>
