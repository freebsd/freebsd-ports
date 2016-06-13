# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	pioneer
PORTVERSION=	0.0.${GH_TAGNAME}
CATEGORIES=	games

MAINTAINER=	lightside@gmx.com
COMMENT=	Space adventure game set in the Milky Way galaxy

LICENSE=	APACHE20 GPLv3 MIT ZLIB CCBYSAv3 DejaVu GLEW IUP SIL
LICENSE_COMB=	multi
LICENSE_NAME_CCBYSAv3=	Creative Commons Attribution-ShareAlike 3.0 Unported license
LICENSE_NAME_DejaVu=	Bitstream Vera and Arev fonts license
LICENSE_NAME_GLEW=	The OpenGL Extension Wrangler Library license
LICENSE_NAME_IUP=	Galaxy colour image use policy
LICENSE_NAME_SIL=	SIL open font license version 1.1
LICENSE_FILE_APACHE20=	${WRKSRC}/licenses/Apache-2.0.txt
LICENSE_FILE_CCBYSAv3=	${WRKSRC}/licenses/CC-BY-SA-3.0.txt
LICENSE_FILE_DejaVu=	${WRKSRC}/licenses/DejaVu-license.txt
LICENSE_FILE_GLEW=	${WRKSRC}/licenses/GLEW.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/licenses/GPL-3.txt
LICENSE_FILE_IUP=	${WRKSRC}/licenses/Image\ Use\ Policy\ -\ NASA\ Spitzer\ Space\ Telescope.html
LICENSE_FILE_SIL=	${WRKSRC}/licenses/SIL-1.1.txt
LICENSE_PERMS_CCBYSAv3=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_DejaVu=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_GLEW=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_IUP=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/GL/glu.h:graphics/libGLU
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libsigc-2.0.so:devel/libsigc++20 \
		libfreetype.so:print/freetype2 \
		libvorbisfile.so:audio/libvorbis \
		libpng.so:graphics/png \
		libassimp.so:multimedia/assimp

USE_GITHUB=	yes
GH_ACCOUNT=	pioneerspacesim
GH_TAGNAME=	20160610

USES=		autoreconf gmake pkgconfig
USE_GL=		gl
USE_SDL=	image2 sdl2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PIONEER_DATA_DIR="${DATADIR}/data"
CONFIGURE_ARGS=	--with-version="${GH_TAGNAME}"
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions --exclude .gitignore

PORTDATA=	data
PORTDOCS=	AUTHORS.txt Changelog.txt Modelviewer.txt Quickstart.txt README.md

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="Pioneer" "${COMMENT}" \
		"${PORTNAME}" "${PORTNAME}" \
		"Game;Simulation;" false

SUB_FILES=	pkg-message
SUB_LIST=	QUICKSTART_PATH="${QUICKSTART_PATH}"

OPTIONS_DEFINE=		DOCS MODELCOMPILER PROFILER
OPTIONS_DEFAULT=	MODELCOMPILER
MODELCOMPILER_DESC=	Build/install modelcompiler tool
MODELCOMPILER_PLIST_FILES=	bin/${PORTNAME}-modelcompiler
PROFILER_DESC=		Build with internal profiler
PROFILER_CONFIGURE_ON=	--enable-profiler

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000054
USE_GCC=	yes
.else
USES+=		compiler:c++11-lang
CPPFLAGS+=	-I${LOCALBASE}/include
.endif

.if ${PORT_OPTIONS:MDOCS}
QUICKSTART_PATH=	${DOCSDIR}
.else
QUICKSTART_PATH=	\
	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GH_TAGNAME}
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e '/^OPTIMISE=/d' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's/std:://g' \
		${WRKSRC}/src/Orbit.cpp
	${REINPLACE_CMD} -e 's/std::to_string/to_string/g' \
		${WRKSRC}/src/graphics/opengl/RendererGL.cpp

post-patch-MODELCOMPILER-off: .SILENT
	${REINPLACE_CMD} -e 's/pioneer modelcompiler/pioneer/' \
		${WRKSRC}/src/Makefile.am

post-patch-PROFILER-off: .SILENT
	${REINPLACE_CMD} -e '/^SUBDIRS/s/ profiler//' \
		${WRKSRC}/contrib/Makefile.am
	${REINPLACE_CMD} -i '.p.bak' -e '/libjson.a/s| \\|| ; /libprofiler.a/d' \
		${WRKSRC}/src/Makefile.am
	${REINPLACE_CMD} -i '.p.bak' -e '/contrib\/profiler/d' \
		${WRKSRC}/configure.ac

post-install:
	${INSTALL_DATA} ${WRKSRC}/application-icon/pngs/pioneer-256x256.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

post-install-MODELCOMPILER-on:
	${MV} ${STAGEDIR}${PREFIX}/bin/modelcompiler \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-modelcompiler

.include <bsd.port.mk>
