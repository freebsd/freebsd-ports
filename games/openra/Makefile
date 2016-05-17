# $FreeBSD$

PORTNAME=	openra
PORTVERSION=	20160508
DISTVERSIONPREFIX=	release-
CATEGORIES=	games
# XXX Convert to USES=nuget or package dependencies instead
MASTER_SITES=	https://nuget.org/api/v2/package/StyleCopPlus.MSBuild/4.7.49.5?dummy=/:StyleCopPlus \
		https://nuget.org/api/v2/package/StyleCop.MSBuild/4.7.49.0?dummy=/:StyleCop \
		https://nuget.org/api/v2/package/SharpZipLib/0.86.0?dummy=/:SharpZipLib \
		https://nuget.org/api/v2/package/MaxMind.Db/1.1.0.0?dummy=/:MaxMind_Db \
		https://nuget.org/api/v2/package/Newtonsoft.Json/7.0.1?dummy=/:Newtonsoft_Json \
		https://nuget.org/api/v2/package/RestSharp/105.2.3?dummy=/:RestSharp \
		https://nuget.org/api/v2/package/MaxMind.GeoIP2/2.3.1?dummy=/:MaxMind_GeoIP2 \
		https://nuget.org/api/v2/package/SharpFont/3.1.0?dummy=/:SharpFont \
		https://nuget.org/api/v2/package/NUnit/3.0.1?dummy=/:NUnit \
		https://nuget.org/api/v2/package/NUnit.Console/3.0.1?dummy=/:NUnit_Console \
		https://nuget.org/api/v2/package/Mono.Nat/1.2.24?dummy=/:Mono_Nat \
		https://nuget.org/api/v2/package/FuzzyLogicLibrary/1.2.0?dummy=/:FuzzyLogicLibrary \
		https://nuget.org/api/v2/package/SmartIrc4net/0.4.5.1?dummy=/:SmartIrc4net \
		https://github.com/${GH_ACCOUNT}/SDL2-CS/releases/download/20151227/:SDL2_CS \
		https://github.com/${GH_ACCOUNT}/OpenAL-CS/releases/download/20151227/:OpenAL_CS \
		https://github.com/${GH_ACCOUNT}/Eluant/releases/download/20160124/:Eluant \
		https://geolite.maxmind.com/download/geoip/database/:GeoLite2
DISTFILES=	StyleCopPlus.MSBuild-4.7.49.5.zip:StyleCopPlus \
		StyleCop.MSBuild-4.7.49.0.zip:StyleCop \
		SharpZipLib-0.86.0.zip:SharpZipLib \
		MaxMind.Db-1.1.0.0.zip:MaxMind_Db \
		Newtonsoft.Json-7.0.1.zip:Newtonsoft_Json \
		RestSharp-105.2.3.zip:RestSharp \
		MaxMind.GeoIP2-2.3.1.zip:MaxMind_GeoIP2 \
		SharpFont-3.1.0.zip:SharpFont \
		NUnit-3.0.1.zip:NUnit \
		NUnit.Console-3.0.1.zip:NUnit_Console \
		Mono.Nat-1.2.24.zip:Mono_Nat \
		FuzzyLogicLibrary-1.2.0.zip:FuzzyLogicLibrary \
		SmartIrc4net-0.4.5.1.zip:SmartIrc4net \
		SDL2-CS.dll:SDL2_CS \
		SDL2-CS.dll.config:SDL2_CS \
		OpenAL-CS.dll:OpenAL_CS \
		OpenAL-CS.dll.config:OpenAL_CS \
		Eluant.dll:Eluant \
		GeoLite2-Country.mmdb.gz:GeoLite2
EXTRACT_ONLY=	${DISTFILES:C/:.*//:N*.dll:N*.config:N*.mmdb*}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multiplayer re-envisioning of early RTS games by Westwood Studios

LICENSE=	GPLv3

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgdiplus.so:x11-toolkits/libgdiplus

USE_GITHUB=	yes
GH_PROJECT=	OpenRA

NO_ARCH=	yes
USES=		desktop-file-utils gmake lua:51,run mono openal:soft \
		shared-mime-info shebangfix
SHEBANG_FILES=	launch-dedicated.sh
USE_SDL=	sdl2
MAKE_ENV=	prefix="${PREFIX}" mandir="${PREFIX}/man"
MAKE_ARGS=	VERSION="${GH_TAGNAME}"
INSTALL_TARGET=	install-all install-man-page \
		install-linux-mime install-linux-shortcuts
DATADIR=	${PREFIX}/lib/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*.html

OPTIONS_DEFINE=	DOCS TEST ZENITY
OPTIONS_DEFAULT=ZENITY

DOCS_BUILD_DEPENDS=markdown:textproc/markdown
DOCS_ALL_TARGET=docs

TEST_MAKE_ENV=	HOME="${WRKDIR}"
TEST_ALL_TARGET=test

ZENITY_RUN_DEPENDS=xdg-open:devel/xdg-utils \
		zenity:x11/zenity
ZENITY_DESC=	Use native crash dialog

post-extract:
	@${MKDIR} ${WRKSRC}/thirdparty/download
	@${CP} -v ${DISTFILES:C/:.*//:N*.tar*:N*.zip:S,^,${_DISTDIR}/,} \
		${WRKSRC}/thirdparty/download
	@for f in $$(${SED} -n 's/\.$$//; s,cp \./,,p' \
			${WRKSRC}/thirdparty/fetch-thirdparty-deps.sh); do \
		${MV} -v ${WRKDIR}/$${f#*/} ${WRKSRC}/thirdparty/download; \
	done

post-patch:
	${REINPLACE_CMD} \
		-e '\,thirdparty/.*\.sh,d' \
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

post-build-DOCS-on:
	@${ECHO_MSG} Generating HTML documentation...
	@for f in ${WRKSRC}/*.md; do \
		${ECHO_MSG} markdown $$f -\> $${f%.md}.html; \
		markdown $$f >$${f%.md}.html; \
	done

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
