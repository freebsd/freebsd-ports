# $FreeBSD$

PORTNAME=	openra
PORTVERSION=	20141029
CATEGORIES=	games

MAINTAINER=	jbeich@vfemail.net
COMMENT=	Multiplayer re-envisioning of early RTS games by Westwood Studios

LICENSE=	GPLv3

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libgdiplus.so:${PORTSDIR}/x11-toolkits/libgdiplus

USE_GITHUB=	yes
GH_ACCOUNT=	${GH_PROJECT}
GH_PROJECT=	OpenRA
GH_TAGNAME=	release-${PORTVERSION}
GH_COMMIT=	e5948ba

NO_ARCH=	yes
USES=		gmake lua:51,run mono openal:soft
USE_SDL=	sdl2
INSTALLS_ICONS=	yes
MAKE_ENV=	prefix="${PREFIX}"
MAKE_ARGS=	VERSION="${GH_TAGNAME}"
INSTALL_TARGET=	install-all install-linux-shortcuts
DATADIR=	${PREFIX}/lib/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

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

post-patch:
	${REINPLACE_CMD} -e 's/Linux/${OPSYS}/' \
		-e 's/crashdialog/gamemonitor/' \
		-e '/^mods:/s/$$/ version/' \
		-e '/^docs:/s/$$/ all/' \
		-e '/^test:/s/$$/ all/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/linux/{ p; s//${OPSYS:tl}/; }' \
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
		markdown $$f >$${f%.md}.html; \
	done
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
