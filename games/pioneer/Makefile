# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	pioneer
DISTVERSION=	0.0.${GH_TAGNAME}
CATEGORIES=	games

MAINTAINER=	lightside@gmx.com
COMMENT=	Space adventure game set in the Milky Way galaxy

LICENSE=		APACHE20 BSD2CLAUSE CC-BY-SA-3.0 DejaVu GLEW GPLv3 IUP \
			MIT SIL ZLIB
LICENSE_COMB=		multi
LICENSE_NAME_DejaVu=	Bitstream Vera and Arev fonts license
LICENSE_NAME_GLEW=	The OpenGL Extension Wrangler Library license
LICENSE_NAME_IUP=	Galaxy colour image use policy
LICENSE_NAME_SIL=	SIL open font license version 1.1
LICENSE_FILE_APACHE20=	${WRKSRC}/licenses/Apache-2.0.txt
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/licenses/LZ4.txt
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

BROKEN_powerpc=		fails to build: contrib/profiler/Profiler.h:158:51: inconsistent operand constraints in an 'asm'
BROKEN_powerpc64=	fails to build: contrib/profiler/Profiler.h:158:51: inconsistent operand constraints in an 'asm'
BROKEN_powerpcspe=	fails to build: contrib/profiler/Profiler.h:158:51: inconsistent operand constraints in an 'asm'

LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libfreetype.so:print/freetype2 \
		libsigc-2.0.so:devel/libsigc++20 \
		libvorbisfile.so:audio/libvorbis

USES=		cmake compiler:c++11-lib gl gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	pioneerspacesim
GH_TAGNAME=	20191009
USE_GL=		gl glu
USE_SDL=	image2 sdl2

CMAKE_ARGS=	-DPIONEER_DATA_DIR:PATH="${DATADIR}/data"
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions --exclude \
			.gitignore
INSTALLS_ICONS=	yes

PORTDATA=	data
PORTDOCS=	AUTHORS.txt Changelog.txt Modelviewer.txt Quickstart.txt \
		README.md

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS EXTERNAL_GLEW EXTERNAL_LUA NOGPUJOBS PROFILER
OPTIONS_DEFAULT=	EXTERNAL_GLEW EXTERNAL_LUA

EXTERNAL_GLEW_DESC=	Use external libglew from graphics/glew
EXTERNAL_LUA_DESC=	Use external liblua from lang/lua52
NOGPUJOBS_DESC=		Disable EnableGPUJobs for config.ini by default
PROFILER_DESC=		Build with internal profiler

DOCS_SUB_LIST=			QUICKSTART_PATH="${DOCSDIR}"
DOCS_SUB_LIST_OFF=		QUICKSTART_PATH="https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GH_TAGNAME}"
EXTERNAL_GLEW_CMAKE_BOOL=	USE_SYSTEM_LIBGLEW
EXTERNAL_GLEW_VARS_OFF=		LICENSE+=GLEW
EXTERNAL_GLEW_USE=		GL=glew
EXTERNAL_LUA_CMAKE_BOOL=	USE_SYSTEM_LIBLUA
EXTERNAL_LUA_USES=		lua:52
PROFILER_CMAKE_BOOL=		PROFILER_ENABLED

post-patch: .SILENT
	${REINPLACE_CMD} -e '/^include(FindGit/d ; \
		/TIMESTAMP PROJECT_VERSION/s|.*|set(PROJECT_VERSION "${GH_TAGNAME}")|' \
		${WRKSRC}/CMakeLists.txt

post-patch-NOGPUJOBS-on: .SILENT
# Revert 41272a856d9072404efbfdb10f0e3c9e4f96bb4d commit, in case of
# GL_OUT_OF_MEMORY OpenGL error, when turning to gas giant planet
	${REINPLACE_CMD} -e '/EnableGPUJobs/s|1|0|' \
		 ${WRKSRC}/src/GameConfig.cpp

post-patch-PROFILER-off: .SILENT
	${REINPLACE_CMD} -i '.profiler' -e '/contrib\/profiler/d ; /profiler$$/d ; \
		/target_link_libraries(savegamedump/s| profiler||' \
		${WRKSRC}/CMakeLists.txt

post-install:
.for f in modelcompiler savegamedump
	${MV} ${STAGEDIR}${PREFIX}/bin/${f} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${f}
.endfor

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
