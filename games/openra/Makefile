# $FreeBSD$

PORTNAME=	openra
PORTVERSION=	20150614
DISTVERSIONPREFIX=	release-
CATEGORIES=	games
# XXX Convert to USES=nuget or package dependencies instead
MASTER_SITES=	https://nuget.org/api/v2/package/StyleCopPlus.MSBuild/4.7.49.5?dummy=/:StyleCopPlus \
		https://nuget.org/api/v2/package/StyleCop.MSBuild/4.7.49.0?dummy=/:StyleCop \
		https://nuget.org/api/v2/package/SharpZipLib/0.86.0?dummy=/:SharpZipLib \
		https://nuget.org/api/v2/package/MaxMind.Db/1.0.0.0?dummy=/:MaxMind_Db \
		https://nuget.org/api/v2/package/Newtonsoft.Json/6.0.5?dummy=/:Newtonsoft_Json \
		https://nuget.org/api/v2/package/RestSharp/105.0.1?dummy=/:RestSharp \
		https://nuget.org/api/v2/package/MaxMind.GeoIP2/2.1.0?dummy=/:MaxMind_GeoIP2 \
		https://nuget.org/api/v2/package/SharpFont/3.0.1?dummy=/:SharpFont \
		https://nuget.org/api/v2/package/NUnit/2.6.4?dummy=/:NUnit \
		https://nuget.org/api/v2/package/Mono.Nat/1.2.21?dummy=/:Mono_Nat \
		https://nuget.org/api/v2/package/FuzzyLogicLibrary/1.2.0?dummy=/:FuzzyLogicLibrary \
		https://github.com/${GH_ACCOUNT}/SDL2-CS/releases/download/20140407/:SDL2_CS \
		https://github.com/${GH_ACCOUNT}/Eluant/releases/download/20140425/:Eluant \
		https://geolite.maxmind.com/download/geoip/database/:GeoLite2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		StyleCopPlus.MSBuild-4.7.49.5.zip:StyleCopPlus \
		StyleCop.MSBuild-4.7.49.0.zip:StyleCop \
		SharpZipLib-0.86.0.zip:SharpZipLib \
		MaxMind.Db-1.0.0.0.zip:MaxMind_Db \
		Newtonsoft.Json-6.0.5.zip:Newtonsoft_Json \
		RestSharp-105.0.1.zip:RestSharp \
		MaxMind.GeoIP2-2.1.0.zip:MaxMind_GeoIP2 \
		SharpFont-3.0.1.zip:SharpFont \
		NUnit-2.6.4.zip:NUnit \
		Mono.Nat-1.2.21.zip:Mono_Nat \
		FuzzyLogicLibrary-1.2.0.zip:FuzzyLogicLibrary \
		SDL2-CS.dll:SDL2_CS \
		Eluant.dll:Eluant \
		GeoLite2-Country.mmdb.gz:GeoLite2
EXTRACT_ONLY=	${DISTFILES:C/:.*//:N*.dll:N*.mmdb*}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multiplayer re-envisioning of early RTS games by Westwood Studios

LICENSE=	GPLv3

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libgdiplus.so:${PORTSDIR}/x11-toolkits/libgdiplus

USE_GITHUB=	yes
GH_PROJECT=	OpenRA

NO_ARCH=	yes
USES=		gmake lua:51,run mono openal:soft
USE_SDL=	sdl2
INSTALLS_ICONS=	yes
MAKE_ENV=	prefix="${PREFIX}"
MAKE_ARGS=	VERSION="${GH_TAGNAME}"
INSTALL_TARGET=	install-all install-linux-shortcuts
DATADIR=	${PREFIX}/lib/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*.html

OPTIONS_DEFINE=	DOCS TEST ZENITY
OPTIONS_DEFAULT=ZENITY

DOCS_BUILD_DEPENDS=markdown:${PORTSDIR}/textproc/markdown
DOCS_ALL_TARGET=docs

TEST_MAKE_ENV=	HOME="${WRKDIR}"
TEST_ALL_TARGET=test

ZENITY_RUN_DEPENDS=xdg-open:${PORTSDIR}/devel/xdg-utils \
		zenity:${PORTSDIR}/x11/zenity
ZENITY_DESC=	Use native crash dialog

.include <bsd.port.options.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/thirdparty/download
	@${CP} -v ${DISTFILES:C/:.*//:N*.tar*:N*.zip:S,^,${_DISTDIR}/,} \
		${WRKSRC}/thirdparty/download
	@for f in $$(${SED} -n 's/\.$$//; s,cp \./,,p' \
			${WRKSRC}/thirdparty/fetch-thirdparty-deps.sh); do \
		${MV} -v ${WRKDIR}/$${f#*/} ${WRKSRC}/thirdparty/download; \
	done

post-patch:
	${REINPLACE_CMD} -e 's/Linux/${OPSYS}/' \
		-e '/CP_R/s,hicolor/,hicolor,' \
		-e '\,thirdparty/.*\.sh,d' \
		-e 's/crashdialog/gamemonitor/' \
		-e '/echo/!s/	@/	/' \
		-e '/^mods:/s/$$/ version/' \
		-e '/^docs:/s/$$/ all/' \
		-e '/^test:/s/$$/ all/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/linux/{ p; s//${OPSYS:tl}/; }' \
		${WRKSRC}/thirdparty/download/*.config \
		${WRKSRC}/thirdparty/*.config*
	${SED} 's/@LIBLUA51@/liblua-${LUA_VER}.so/' \
		${WRKSRC}/thirdparty/Eluant.dll.config.in \
		>${WRKSRC}/Eluant.dll.config
# DragonFly lacks BSD suffix
	${REINPLACE_CMD} -e 's/"BSD"/"${OPSYS}"/' \
		${WRKSRC}/OpenRA.Game/Platform.cs

post-build:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} Generating HTML documentation...
	@for f in ${WRKSRC}/*.md; do \
		${ECHO_MSG} markdown $$f -\> $${f%.md}.html; \
		markdown $$f >$${f%.md}.html; \
	done
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
