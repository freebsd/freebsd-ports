# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
DISTVERSION=	r${BZR_SRC_REV}
#PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	LOCAL/mr
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=		mr@FreeBSD.org
COMMENT=		Schematic and PCB editing software

BUILD_DEPENDS=	bzr:devel/bzr \
		${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/bzrlib/plugins/bzrtools/bzrtools.py:devel/bzrtools \
		${LOCALBASE}/include/glm/glm.hpp:math/glm

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

CONFLICTS=	kicad-2014*

DOCVERSION=	1.1
LIBVERSION=	1.0

#CXXFLAGS+=	-std=c++11
USE_GL=		glew glu
USE_WX=		3.0
WX_COMPS=	wx
WX_UNICODE=	yes
USE_GNOME=	atk	# Required by libwx_gtk2_aui-2.8.so

OPTIONS_DEFINE=	DOCS

PLIST_SUB=	OPSYS=${OPSYS}	\
		DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt
USES=		desktop-file-utils shared-mime-info compiler:c++11-lib tar:bzip2 cmake \
		gettext python

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_VERBOSE_MAKEFILE=ON \
		-DCMAKE_BUILD_TYPE="Debug" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION} \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}" \
		-DKICAD_SKIP_BOOST=YES

.if exists(${LOCALBASE}/bin/konqueror)
RUN_DEPENDS+=	konqueror:x11/kde4-baseapps
.else
RUN_DEPENDS+=	xpdf:graphics/xpdf
.endif

.if defined(BOOTSTRAP)
BOOST_RELEASE=	1.54.0
BOOST_VERS=	${BOOST_RELEASE:S|.|_|g}
BZR_SRC_REV!=	bzr revno lp:kicad
#BZR_DOC_REV!=	bzr revno lp:~kicad-developers/kicad/doc
.else
.include "Makefile.bzr_rev"
.endif

.if defined(BOOTSTRAP)

# Updating to new rev:
# make do-fetch BOOTSTRAP=YES && make makesum && make clean
# make && make makeplist && make generate-plist && make check-plist
# < Check PLIST_FILE_LIST below >

FETCH_DEPENDS+=	svn:devel/subversion
FETCH_DEPENDS+=	bzr:devel/bzr

showversions:
	@${ECHO} "BOOST_RELEASE: ${BOOST_RELEASE}"
	@${ECHO} "BOOST_VERS: ${BOOST_VERS}"
	@${ECHO} "BZR_SRC_REV: ${BZR_SRC_REV}"
	@${ECHO} "BZR_LIB_REV: ${BZR_LIB_REV}"
	@${ECHO} "BZR_DOC_REV: ${BZR_DOC_REV}"

do-fetch:
	${MKDIR} ${WRKDIR}
	${ECHO} ${WRKSRC}
	bzr export -r ${BZR_SRC_REV} ${WRKSRC} lp:kicad
	${FETCH_CMD} --no-verify-peer -o ${WRKDIR}/master.zip https://github.com/KiCad/kicad-library/archive/master.zip
#	bzr export -r ${BZR_DOC_REV} ${WRKDIR}/kicad-doc lp:~kicad-developers/kicad/doc
#	fetch -o ${WRKDIR}/${DISTNAME}/boost_${BOOST_VERS}.tar.bz2 \
#		http://downloads.sourceforge.net/project/boost/boost/${BOOST_RELEASE}/boost_${BOOST_VERS}.tar.bz2
	cd ${WRKDIR}; \
	tar xvf master.zip; \
	tar cvfy ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.bz2 \
		${DISTNAME} kicad-library-master
	echo "BOOST_RELEASE=  ${BOOST_RELEASE}" > ${MASTERDIR}/Makefile.bzr_rev
	echo "BOOST_VERS=  ${BOOST_VERS}"   >> ${MASTERDIR}/Makefile.bzr_rev
	echo "BZR_SRC_REV=  ${BZR_SRC_REV}" >> ${MASTERDIR}/Makefile.bzr_rev
	echo "BZR_LIB_REV=  ${BZR_LIB_REV}" >> ${MASTERDIR}/Makefile.bzr_rev
#	echo "BZR_DOC_REV=  ${BZR_DOC_REV}" >> ${MASTERDIR}/Makefile.bzr_rev
.endif

tmp:
	echo "${DATADIR} ${DATADIR:H}"

post-configure:
	${REINPLACE_CMD} -e 's|#define HAVE_ISO646_H|//#define HAVE_ISO646_H|'     \
		${WRKSRC}/config.h
	for f in `${FIND} ${WRKSRC} -name \*.make -o -name link.txt` ; do				\
		${REINPLACE_CMD}						\
		-e 's|CC = gcc|#CC = gcc|'             				\
		-e 's|LD = gcc|LD = ${CC}|'                     		\
		-e 's|LD = g++|LD = ${CXX}|'                    		\
		-e 's|wx-config|${WX_CONFIG}|'                  		\
		-e 's|CXX_FLAGS =|CXX_FLAGS = -I${LOCALBASE}/include|'		\
		-e 's|C_FLAGS =|C_FLAGS = -I${LOCALBASE}/include|'		\
		-e 's|LDFLAGS =|LDFLAGS += -L${LOCALBASE}/lib|' 		\
		-e 's|gcc -D|${CC} -D|'						\
		-e 's/-pthread;-D_THREAD_SAFE/-pthread -D_THREAD_SAFE/g'	\
		$$f ;								\
	done

pre-install:
	@echo "${DATADIR}, ${DOCSDIR}"

post-install:
.for subdir in library modules template
	${CP} -Rp ${WRKDIR}/kicad-library-master/${subdir} ${STAGEDIR}${DATADIR}
.endfor
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

.if ${OPSYS} == FreeBSD
.if ${OSVERSION} < 1000000 || ${COMPILER_TYPE} == "gcc"
  IGNORE= builds only on greater than 10 and with clang
.endif
.endif

.include <bsd.port.post.mk>
