# New ports collection makefile for:  kicad-devel
# Date created:               27 October 2009
# Whom:                       Michael Reifenberger <mr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		kicad
DISTVERSION=    r${SVN_REV}
PORTREVISION=	3
CATEGORIES=		cad
DIST_SUBDIR=		${PORTNAME}
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     mr
PKGNAMESUFFIX=  -devel
# Additional patches: http://svn.openmoko.org/trunk/gta02-core/kicad-patches/

MAINTAINER=		mr@FreeBSD.org
COMMENT=		Schematic and PCB editing software

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

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
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}"
CMAKE_USE_PTHREAD=	yes

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
SVN_REV!=       svn info https://kicad.svn.sourceforge.net/svnroot/kicad/trunk/kicad | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif

.if defined(BOOTSTRAP)
FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion
do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
		https://kicad.svn.sourceforge.net/svnroot/kicad/trunk/kicad ${WRKSRC}
	svn export -r ${SVN_REV} \
		https://kicad.svn.sourceforge.net/svnroot/kicad/trunk/kicad-library ${WRKDIR}/kicad-library
	svn export \
		http://svn.openmoko.org/trunk/gta02-core/kicad-patches ${WRKDIR}/kicad-patches
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.bz2 \
		${DISTNAME} kicad-library kicad-patches
	echo "SVN_REV=  ${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
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
	echo "${DATADIR}, ${DOCSDIR}"

post-install:
.for subdir in library modules
	${CP} -Rp ${WRKDIR}/kicad-library/${subdir} ${DATADIR}
.endfor

PLIST_FILE_LIST=	bin/freeroute.jnlp \
			bin/cvpcb \
			bin/eeschema \
			bin/gerbview \
			bin/kicad \
			bin/minizip \
			bin/pcbnew \
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
