PORTNAME=	xmoto
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Challenging 2D motocross platform game
WWW=		https://xmoto.tuxfamily.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libcurl.so:ftp/curl \
		libxdg-basedir.so:x11/libxdg-basedir

USES=		compiler:c++11-lang cmake gl gnome jpeg lua:52 pkgconfig sdl sqlite
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_SDL=	sdl2 mixer2 ttf2 net2
USE_GL=		gl glu

PORTDOCS=	README.md ChangeLog
PORTDATA=	*

ASIAN_FONT_PATH=${LOCALBASE}/share/fonts/TrueType/bkai00mp.ttf

OPTIONS_DEFINE=	ASIAN_TTF DOCS NLS
OPTIONS_SUB=	yes

ASIAN_TTF_DESC=	Use asian TTF font
ASIAN_TTF_RUN_DEPENDS=	${ASIAN_FONT_PATH}:chinese/arphicttf

NLS_USES=	gettext
NLS_CMAKE_BOOL=	USE_GETTEXT

# ensure bundled depends are not used
post-extract:
.for d in bzip2 lua xdgbasedir
	@${RM} -r ${WRKSRC}/vendor/${d}
.endfor

post-patch:
	@${REINPLACE_CMD} \
		-e "s|find_package(Lua|& ${LUA_VER} REQUIRED EXACT|" \
		-e "s|/usr/share/fonts/truetype/arphic/bkai00mp.ttf|${ASIAN_FONT_PATH}|" \
		-e "s|DEFAULT_ASIAN_TTF_FILE|ASIAN_TTF_FILE|" \
		${WRKSRC}/src/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
