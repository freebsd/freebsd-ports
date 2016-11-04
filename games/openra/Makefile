# $FreeBSD$

PORTNAME=	openra
PORTVERSION=	20161019
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/SDL2-CS/releases/download/20151227/:SDL2_CS \
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
		MaxMind.GeoIP2=2.6.0 \
		NUnit=3.0.1 \
		NUnit.Console=3.0.1 \
		Newtonsoft.Json=8.0.3 \
		Open.NAT=2.1.0 \
		SharpFont=3.1.0 \
		SharpZipLib=0.86.0 \
		SmartIrc4net=0.4.5.1 \
		StyleCop.MSBuild=4.7.49.0 \
		StyleCopPlus.MSBuild=4.7.49.5

USE_GITHUB=	yes
GH_PROJECT=	OpenRA

NO_ARCH=	yes
USES=		desktop-file-utils gmake lua:51,run mono:nuget openal:soft \
		shared-mime-info shebangfix
USE_SDL=	sdl2
TARGET_ORDER_OVERRIDE=	520:nuget-extract
SHEBANG_FILES=	launch-dedicated.sh
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
	@${CP} -v ${DISTFILES:C/:.*//:N*.nupkg:N*.tar*:N*.zip:S,^,${_DISTDIR}/,} \
		${WRKSRC}/thirdparty/download
	@for f in $$(${SED} -n 's/\.$$//; s,cp \./,,p' \
			${WRKSRC}/thirdparty/fetch-thirdparty-deps.sh); do \
		${MV} -v ${NUGET_PACKAGEDIR}/$$f ${WRKSRC}/thirdparty/download; \
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
