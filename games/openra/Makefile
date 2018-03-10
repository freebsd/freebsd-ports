# $FreeBSD$

PORTNAME=	openra
PORTVERSION=	20180307
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/SDL2-CS/releases/download/20161223/:SDL2_CS \
		https://github.com/${GH_ACCOUNT}/OpenAL-CS/releases/download/20151227/:OpenAL_CS \
		https://github.com/${GH_ACCOUNT}/Eluant/releases/download/20160124/:Eluant \
		https://geolite.maxmind.com/download/geoip/database/:GeoLite2
DISTFILES=	SDL2-CS.dll:SDL2_CS \
		SDL2-CS.dll.config:SDL2_CS \
		OpenAL-CS.dll:OpenAL_CS \
		OpenAL-CS.dll.config:OpenAL_CS \
		Eluant.dll:Eluant \
		GeoLite2-Country.mmdb.gz:GeoLite2
EXTRACT_ONLY=	${DISTFILES:C/:.*//:N*.config:N*.dll:N*.mmdb*:N*.nupkg}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multiplayer re-envisioning of early RTS games by Westwood Studios

LICENSE=	GPLv3

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgdiplus.so:x11-toolkits/libgdiplus
NUGET_DEPENDS=	FuzzyLogicLibrary=1.2.0 \
		MaxMind.Db=2.0.0 \
		NUnit=3.0.1 \
		NUnit.Console=3.0.1 \
		Open.Nat=2.1.0 \
		SharpFont=4.0.1 \
		SharpZipLib=0.86.0 \
		StyleCop.MSBuild=4.7.49.0 \
		StyleCopPlus.MSBuild=4.7.49.5 \
		rix0rrr.BeaconLib=1.0.1

USE_GITHUB=	yes
GH_PROJECT=	OpenRA

NO_ARCH=	yes
USES=		desktop-file-utils gmake lua:51,run mono:nuget openal:soft \
		shared-mime-info shebangfix
USE_SDL=	sdl2
NUGET_PACKAGEDIR=${WRKSRC}/thirdparty/download
SHEBANG_FILES=	launch-dedicated.sh
MAKE_ENV=	prefix="${PREFIX}" mandir="${PREFIX}/man" \
		gameinstalldir="${DATADIR}"
MAKE_ARGS=	VERSION="${GH_TAGNAME}"
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

post-patch:
	${REINPLACE_CMD} \
		-e '/echo/!s/	@/	/' \
		-e '/^mods:/s/$$/ version/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/noget\.sh/d' \
			${WRKSRC}/thirdparty/fetch-thirdparty-deps.sh
	${FIND} -L ${WRKSRC}/thirdparty -name '*.config*' -exec ${REINPLACE_CMD} \
		-i '.bak.os' -e '/${OPSYS:tl}/d; /linux/{ p; s//${OPSYS:tl}/; }' {} +
	${SED} 's/@LIBLUA51@/liblua-${LUA_VER}.so/' \
		${WRKSRC}/thirdparty/Eluant.dll.config.in \
		>${WRKSRC}/Eluant.dll.config

.include <bsd.port.mk>
