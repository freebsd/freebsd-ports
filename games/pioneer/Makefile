# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	pioneer
PORTVERSION=	0.0.${GH_TAGNAME}
CATEGORIES=	games

MAINTAINER=	lightside@gmx.com
COMMENT=	Space adventure game set in the Milky Way galaxy

LICENSE=	APACHE20 GPLv3 MIT ZLIB CC-BY-SA-3.0 DejaVu GLEW IUP SIL
LICENSE_COMB=	multi
LICENSE_NAME_DejaVu=	Bitstream Vera and Arev fonts license
LICENSE_NAME_GLEW=	The OpenGL Extension Wrangler Library license
LICENSE_NAME_IUP=	Galaxy colour image use policy
LICENSE_NAME_SIL=	SIL open font license version 1.1
LICENSE_FILE_APACHE20=	${WRKSRC}/licenses/Apache-2.0.txt
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/licenses/CC-BY-SA-3.0.txt
LICENSE_FILE_DejaVu=	${WRKSRC}/licenses/DejaVu-license.txt
LICENSE_FILE_GLEW=	${WRKSRC}/licenses/GLEW.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/licenses/GPL-3.txt
LICENSE_FILE_IUP=	${WRKSRC}/licenses/Image\ Use\ Policy\ -\ NASA\ Spitzer\ Space\ Telescope.html
LICENSE_FILE_SIL=	${WRKSRC}/licenses/SIL-1.1.txt
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
GH_TAGNAME=	20161129

USES=		autoreconf compiler:c++11-lib gmake pkgconfig
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

OPTIONS_DEFINE=		DOCS MODELCOMPILER NOGPUJOBS PROFILER
OPTIONS_DEFAULT=	MODELCOMPILER
DOCS_SUB_LIST=	QUICKSTART_PATH="${DOCSDIR}"
DOCS_SUB_LIST_OFF=	\
		QUICKSTART_PATH="https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GH_TAGNAME}"
MODELCOMPILER_DESC=	Build/install modelcompiler tool
MODELCOMPILER_PLIST_FILES=	bin/${PORTNAME}-modelcompiler
NOGPUJOBS_DESC=		Disable EnableGPUJobs for config.ini by default
PROFILER_DESC=		Build with internal profiler
PROFILER_CONFIGURE_ON=	--enable-profiler

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
# Unhide std::to_string() for GCC (ports/193528)
CXXFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e '/^OPTIMISE=/d' \
		${WRKSRC}/configure.ac

post-patch-MODELCOMPILER-off: .SILENT
	${REINPLACE_CMD} -e 's/pioneer modelcompiler/pioneer/' \
		${WRKSRC}/src/Makefile.am

post-patch-NOGPUJOBS-on: .SILENT
# Revert 41272a856d9072404efbfdb10f0e3c9e4f96bb4d commit, in case of
# GL_OUT_OF_MEMORY OpenGL error, when turning to gas giant planet
	${REINPLACE_CMD} -e '/EnableGPUJobs/s|1|0|' \
		 ${WRKSRC}/src/GameConfig.cpp

post-patch-PROFILER-off: .SILENT
	${REINPLACE_CMD} -e '/^SUBDIRS/s/ profiler//' \
		${WRKSRC}/contrib/Makefile.am
	${REINPLACE_CMD} -i '.p.bak' -e \
		'/libprofiler.a/d; $$!N; /libprofiler.a$$/s| \\||; P; D' \
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

.include <bsd.port.post.mk>
