PORTNAME=	xmoto
PORTVERSION=	0.6.1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Challenging 2D motocross platform game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libode.so:devel/ode \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl \
		libxdg-basedir.so:x11/libxdg-basedir

USES=		compiler:c++11-lang cmake gl gnome jpeg lua:52 pkgconfig sdl sqlite
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_SDL=	sdl mixer ttf net
USE_GL=		gl glu
CMAKE_ARGS=	-DOpenGL_GL_PREFERENCE="GLVND"

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
.for d in bzip2 lua ode xdgbasedir
	@${RM} -r ${WRKSRC}/src/${d}
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
