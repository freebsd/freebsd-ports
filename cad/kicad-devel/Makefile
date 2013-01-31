# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=		kicad
DISTVERSION=    r${BZR_SRC_REV}
PORTREVISION=	3
CATEGORIES=		cad
DIST_SUBDIR=		${PORTNAME}
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     mr
PKGNAMESUFFIX=  -devel
# Additional patches: http://svn.openmoko.org/trunk/gta02-core/kicad-patches/

MAINTAINER=		mr@FreeBSD.org
COMMENT=		Schematic and PCB editing software

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

CONFLICTS=      kicad-2008*

DOCVERSION=	1.1
LIBVERSION=	1.0

USE_BZIP2=	yes
USE_GETTEXT=	yes
#USE_GMAKE=	yes
USE_GL=		yes
USE_WX=		2.8
WX_UNICODE=	yes
USE_GNOME=	atk	# Required by libwx_gtk2_aui-2.8.so
#TODO	Add support for Python.

#OPTIONS=	GTA2CORE "Apply additional Openmoko GTA2_CORE patches" off

PLIST_SUB=	OPSYS=${OPSYS}	\
		DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt
USE_CMAKE=      yes
CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DKICAD_TESTING_VERSION=ON \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}"

MAKE_JOBS_SAFE= yes

.include <bsd.port.pre.mk>

#.if !defined(WITHOUT_GTA2CORE)
#PATCH_STRIP=	-p1
#EXTRA_PATCHES+= \
#	${WRKDIR}/kicad-patches/eeschema-plot-only-mode.patch \
#	${WRKDIR}/kicad-patches/streamline-erc.patch
#.endif

.if exists(${LOCALBASE}/bin/konqueror)
RUN_DEPENDS+=	konqueror:${PORTSDIR}/x11/kdebase3
.else
RUN_DEPENDS+=	xpdf:${PORTSDIR}/graphics/xpdf
.endif

.if defined(BOOTSTRAP)
BZR_SRC_REV!=        bzr revno lp:kicad
BZR_LIB_REV!=        bzr revno lp:~kicad-lib-committers/kicad/library
BZR_DOC_REV!=        bzr revno lp:~kicad-developers/kicad/doc
.else
.include "Makefile.bzr_rev"
.endif

.if defined(BOOTSTRAP)

# Updating to new rev:
# make BOOTSTRAP=YES do-fetch
# make makesum && make && make install
# < Check PLIST_FILE_LIST below >
# make build-plist
# make deinstall && make install && make package
# pkg_deinstall /var/db/pkg/kicad-devel*
# pkg_add /usr/ports/pkg_amd64/All/kicad-devel*

FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion
FETCH_DEPENDS+= bzr:${PORTSDIR}/devel/bzr

do-fetch:
	${MKDIR} ${WRKDIR}
	${ECHO} ${WRKSRC} 
	bzr export -r ${BZR_SRC_REV} ${WRKSRC} lp:kicad
	bzr export -r ${BZR_LIB_REV} ${WRKDIR}/kicad-library lp:~kicad-lib-committers/kicad/library
	bzr export -r ${BZR_DOC_REV} ${WRKDIR}/kicad-doc lp:~kicad-developers/kicad/doc
	svn export \
		http://svn.openmoko.org/trunk/gta02-core/kicad-patches ${WRKDIR}/kicad-patches
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.bz2 \
		${DISTNAME} kicad-library kicad-doc kicad-patches
	echo "BZR_SRC_REV=  ${BZR_SRC_REV}" > ${MASTERDIR}/Makefile.bzr_rev
	echo "BZR_LIB_REV=  ${BZR_LIB_REV}" >> ${MASTERDIR}/Makefile.bzr_rev
	echo "BZR_DOC_REV=  ${BZR_DOC_REV}" >> ${MASTERDIR}/Makefile.bzr_rev
.endif

ki:
	svn export \
		http://svn.openmoko.org/trunk/gta02-core/kicad-patches ${WRKDIR}/kicad-patches

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
.for subdir in library modules
	${CP} -Rp ${WRKDIR}/kicad-library/${subdir} ${DATADIR}
.endfor
.for subdir in internat
	${CP} -Rp ${WRKDIR}/kicad-doc/${subdir} ${DOCSDIR}
.endfor

PLIST_FILE_LIST=	bin/freeroute.jnlp \
			bin/cvpcb \
			bin/eeschema \
			bin/gerbview \
			bin/kicad \
			bin/minizip \
			bin/pcbnew \
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

PLIST_SHAREDDIR_LIST=	share/applications \
			share/mimelnk/application \
			share/mimelnk

build-plist:
	${RM} -f ${PLIST}
	cd ${PREFIX} && \
		(ls ${PLIST_FILE_LIST}; ${FIND} ${PLIST_DIR_LIST} -type f) | \
		${SORT} >> ${PLIST}
	${FIND} ${DATADIR} ${DOCSDIR} -type f | \
		${SED} -e 's|${DATADIR}|%%DATADIR%%|' \
		-e 's|${DOCSDIR}|%%DOCSDIR%%|' | ${SORT} >> ${PLIST}
	cd ${PREFIX} && \
		${FIND} ${PLIST_DIR_LIST} -type d | \
		${SORT} -r | ${SED} -e 's|^|@dirrm |' >> ${PLIST}
.for subdir in ${PLIST_SHAREDDIR_LIST}
	@${ECHO_CMD} '@unexec ${RMDIR} %D/${subdir} 2> /dev/null || true' >> ${PLIST}
.endfor
	${FIND} ${DATADIR} ${DOCSDIR} -type d | ${SORT} -r | \
		${SED} -e 's|${DATADIR}|%%DATADIR%%|' \
			-e 's|${DOCSDIR}|%%DOCSDIR%%|' \
			-e 's|^|@dirrm |' >> ${PLIST}

.include <bsd.port.post.mk>
