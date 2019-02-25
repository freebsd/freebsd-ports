# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
DISTVERSION=	r${GIT_SRC_DATE}
PORTREVISION=	7
CATEGORIES=	cad
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=		mr@FreeBSD.org
COMMENT=		Schematic and PCB editing software

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/bin/swig3.0:devel/swig30
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libngspice.so:cad/ngspice_rework@shlib \
		libTKernel.so:cad/opencascade \
		libpixman-1.so:x11/pixman \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl

CONFLICTS=	kicad-4.*

USE_GITHUB=     yes
GH_ACCOUNT=     KiCad
GH_PROJECT=     kicad-source-mirror
GH_TAGNAME=	${GIT_SRC_HASH}

CXXFLAGS+=	--std=c++11 -I${WRKSRC} -I${WRKSRC}/include -I${LOCALBASE}/include -msse
USE_GL=		gl glew glu glut
USE_WX=		3.0
WX_COMPS=	wx wx:build wx:run python:build python:run
USE_GNOME=	atk cairo	# Required by libwx_gtk2_aui-2.8.so
USE_XORG+=	ice pixman x11 xext

BROKEN_aarch64=		Fails to compile: use of undeclared identifier builtin_ia32_emms

OPTIONS_DEFINE=	DOCS

PLIST_SUB=	OPSYS=${OPSYS}	\
		DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt
USES=		desktop-file-utils shared-mime-info compiler:c++11-lib tar:bzip2 cmake:insource,noninja \
		gettext python:2.7 shebangfix ssl
SHEBANG_FILES=	pcbnew/python/plugins/touch_slider_wizard.py

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Debug" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION} \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}" \
		-DwxWidgets_USE_DEBUG=ON \
		-DwxWidgets_USE_USE_UNICODE=ON \
		-DwxWidgets_wxrc_EXECUTABLE=${WXRC_CMD} \
		-DKICAD_SCRIPTING=ON \
		-DKICAD_SCRIPTING_MODULES=ON \
		-DKICAD_SCRIPTING_WXPYTHON=OFF \
		-DKICAD_SKIP_BOOST=YES \
		-DKICAD_SPICE=ON \
		-DKICAD_USE_OCE=OFF \
		-DKICAD_USE_OCC=ON \
		-DOCC_INCLUDE_DIR=${LOCALBASE}/include/OpenCASCADE

.include "Makefile.git_rev"

showversions:
	@${ECHO} "GIT_SRC_HASH: ${GIT_SRC_HASH}"
	@${ECHO} "GIT_SRC_DATE: ${GIT_SRC_DATE}"
	@${ECHO} "DISTDIR: ${DISTDIR}"
	@${ECHO} "DIST_SUBDIR: ${DIST_SUBDIR}"
	@${ECHO} "DISTNAME: ${DISTNAME}"
	@${ECHO} "DISTVERSION: ${DISTVERSION}"

# Updating to new rev:
# sh files/newVersion.sh
# make makesum && make clean
# make install #breaks probably due to plist differences
# make makeplist > pkg-plist #One has to edit/review the generated plist
# make generate-plist && make check-plist
# < Check PLIST_FILE_LIST below >

tmp:
	echo "${DATADIR} ${DATADIR:H}"

# The CheckCXXSymbolExists module has been shipped with CMake since 3.0 times.
# The ancient implementation that this bundled module uses, no longer works
# because it uses CMake internals that have gone away in 3.11.
post-extract:
	${RM} ${WRKSRC}/CMakeModules/CheckCXXSymbolExists.cmake

post-configure:
	${REINPLACE_CMD} -e 's|#define HAVE_ISO646_H|//#define HAVE_ISO646_H|'     \
		${WRKSRC}/config.h
	for f in `${FIND} ${WRKSRC} -name \*.make -o -name link.txt` ; do				\
		${REINPLACE_CMD}						\
		-e 's|CC = gcc|#CC = gcc|'					\
		-e 's|LD = gcc|LD = ${CC}|'					\
		-e 's|LD = g++|LD = ${CXX}|'					\
		-e 's|wx-config|${WX_CONFIG}|'					\
		-e 's|CXX_FLAGS =|CXX_FLAGS = -I${LOCALBASE}/include|'		\
		-e 's|C_FLAGS =|C_FLAGS = -I${LOCALBASE}/include|'		\
		-e 's|LDFLAGS =|LDFLAGS += -L${LOCALBASE}/lib|'			\
		-e 's|gcc -D|${CC} -D|'						\
		-e 's/-pthread;-D_THREAD_SAFE/-pthread -D_THREAD_SAFE/g'	\
		$$f ;								\
	done

pre-install:
	@echo "${DATADIR}, ${DOCSDIR}"

#post-install:
#.for subdir in library modules template
#	${CP} -Rp ${WRKDIR}/kicad-library-master/${subdir} ${STAGEDIR}${DATADIR}
#.endfor
#.for subdir in internat
#	${CP} -Rp ${WRKDIR}/kicad-doc/${subdir} ${STAGEDIR}${DOCSDIR}
#.endfor

PLIST_FILE_LIST=	bin/freeroute.jnlp \
			bin/cvpcb \
			bin/eeschema \
			bin/gerbview \
			bin/kicad \
			bin/pcbnew \
			bin/pl_editor \
			bin/bitmap2component \
			bin/pcb_calculator \
			share/mimelnk/application/x-kicad-schematic.desktop \
			share/mimelnk/application/x-kicad-project.desktop \
			share/icons/hicolor/24x24/mimetypes/application-x-kicad-project.png \
			share/icons/hicolor/48x48/apps/kicad.png \
			share/icons/hicolor/48x48/mimetypes/application-x-kicad-project.png \
			share/icons/hicolor/scalable/apps/kicad.svg \
			share/icons/hicolor/scalable/mimetypes/application-x-kicad-project.svg \
			share/icons/hicolor/16x16/mimetypes/application-x-kicad-project.png \
			share/icons/hicolor/32x32/mimetypes/application-x-kicad-project.png \
			share/icons/hicolor/22x22/mimetypes/application-x-kicad-project.png \
			share/mime/packages/kicad.xml \
			share/applications/kicad.desktop \
			share/applications/eeschema.desktop

PLIST_DIR_LIST=		lib/kicad

PLIST_SHAREDDIR_LIST=	share/mimelnk/application \
			share/mimelnk

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${CHOSEN_COMPILER_TYPE} == gcc
IGNORE=		builds only with clang
.endif

.include <bsd.port.post.mk>
