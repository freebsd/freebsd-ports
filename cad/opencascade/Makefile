# New ports collection makefile for:  opencascade
# Date created:               29 November 2005
# Whom:                       Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=		opencascade
PORTVERSION=		6.2
CATEGORIES=		cad science
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	thierry

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open CASCADE Technology, 3D modeling & numerical simulation

BUILD_DEPENDS=	${LOCALBASE}/include/stlport/algorithm:${PORTSDIR}/devel/stlport
RUN_DEPENDS=	${LOCALBASE}/include/stlport/algorithm:${PORTSDIR}/devel/stlport	\
		autoexpect:${PORTSDIR}/lang/expect		\
		${LIB_TCLX}:${PORTSDIR}/lang/tclX
LIB_DEPENDS=	itcl.${ITCL_VER}:${PORTSDIR}/lang/itcl		\
		itk.${ITK_VER}:${PORTSDIR}/x11-toolkits/itk	\
		tix${TIX_VER}:${PORTSDIR}/x11-toolkits/tix	\
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_BZIP2=	yes
USE_BISON=	yes
USE_XLIB=	yes
USE_TK=		yes
USE_TCL_BUILD=	84-thread
USE_JAVA=	yes
JAVA_VERSION=	1.4+
#.if defined(MAINTAINER_MODE)
# linux-sun-jdk was required for 6.1, but 6.2 is OK with diablo-jdk.
#JAVA_OS=	linux
#.endif

ITCL_VER=	3
ITCL_MM=	3.3
ITK_VER=	3
ITK_MM=		3.3
TIX_VER=	8184.1
TIX_MM=		8.1
LIB_TCLX=	${LOCALBASE}/lib/tclx${TCL_VER}/libtclx${TCL_VER}.so
THRSH=		${TCLSH}-threads

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/ros
REINPLACE_ARGS=	-i ""
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR}				\
		--with-tk=${TK_LIBDIR}					\
		--with-java-include=${JAVA_HOME}/include		\
		--with-dps-include=${X11BASE}/include			\
		--with-dps-library=${X11BASE}/lib			\
		--with-gl-include=${X11BASE}/include			\
		--with-gl-library=${X11BASE}/lib			\
		--with-xmu-include=${X11BASE}/include/X11		\
		--with-xmu-library=${X11BASE}/lib			\
		--with-stlport-include=${LOCALBASE}/include/stlport	\
		--with-stlport-libname=stlport_${STL_COMPILER}		\
		--with-stlport-library=${LOCALBASE}/lib			\
		--enable-production=yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${X11BASE}/include		\
		-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}" ARCH=${ARCH}
# We strip the libs
MAKE_ENV=	INSTALL_STRIP_FLAG=-s OCC_BUILDDIR="${PATCH_WRKSRC}"	\
		OCC_INSTALLDIR="${OCCROOT}" PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

STL_COMPILER?=	gcc
WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
CONFIGURE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"
FFLAGS?=	-O2

LOCCROOT=	OpenCAS
OCCROOT=	${PREFIX}/${LOCCROOT}
CASROOT=	${OCCROOT}/ros
PLIST_SUB=	OCCROOT="${LOCCROOT}"
SUB_LIST=	OCCROOT="${OCCROOT}" PORTNAME=${PORTNAME} FILESDIR=${FILESDIR}
SUB_FILES=	pkg-message LICENSE.${OPSYS}
PKGMESSAGE=	${WRKDIR}/pkg-message

FBSDBIN=	DRAWEXE wokprocess woksh
DIR2INST=	data tools wok
SRC2INST=	adm drv inc make src
.if !defined(NOPORTDOCS)
DIR2INST+=	doc
.endif

.include <bsd.port.pre.mk>

.if defined(MAINTAINER_MODE)	# Get the sources & roll the tarballs

PRIM_MASTER_SITES=	http://files.opencascade.com/OCC_${PORTVERSION}_release/
PRIM_DISTFILES=		OpenCASCADE_Linux.tgz
DISABLE_SIZE=		yes
WRKPREP=		${WRKDIR}/prepare
#USE_LINUX=		yes

LINBIN=	uninstall

get-sources:
	# The tarball provided by Open CASCADE requires Java (+ Linux emulation)
	# to be extracted, and it is interactive!
. if !exists(${_DISTDIR}/${PRIM_DISTFILES})
	${MKDIR} ${_DISTDIR}
	cd ${_DISTDIR} &&	\
	${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS}	\
		${PRIM_MASTER_SITES}${PRIM_DISTFILES} ${FETCH_AFTER_ARGS}
. endif
. if !exists(${WRKPREP}/install.csh)
	${MKDIR} ${PATCH_WRKSRC} ${WRKPREP} ${WRKDIR}/tmp
	cd ${WRKPREP} && ${TAR} xf ${_DISTDIR}${PRIM_DISTFILES}
	${RM} -f ${HOME}/vpd.properties
	#${BRANDELF} -t Linux ${WRKPREP}/Linux/setupLinux.bin
	@${ECHO_MSG} "========================================================================"
	@${ECHO_MSG} "Accept license, change destination directory to ${PATCH_WRKSRC}"
	@${ECHO_MSG} "select \"Complete installation\" and \"Install\"."
	@${ECHO_MSG} "========================================================================"
	#cd ${WRKPREP} && LANG=C JAVAHOME=. OS_NAME=${OPSYS} ./Linux/setupLinux.bin
	cd ${WRKPREP} &&	\
		${JAVA} -cp ./Linux/setup.jar -DOS_NAME=Linux -Dtemp.dir=${WRKDIR}/tmp run
. endif

tarballs:	get-sources
	# Remove Linux binaries
	${RM} -rf ${LINBIN:S|^|${PATCH_WRKSRC}/|}
	# Make separate tarballs / ports for samples
	${MV} ${PATCH_WRKSRC}/samples ${WRKDIR}
	cd ${WRKDIR} && ${TAR} cfj ${_DISTDIR}${DISTFILES} ${DISTNAME}
	${MV} ${WRKDIR}/samples ${PATCH_WRKSRC}
	cd ${WRKDIR} &&	\
	${TAR} cfj ${_DISTDIR}${PORTNAME}-tutorial-${PORTVERSION}${EXTRACT_SUFX}	\
			${DISTNAME}/samples/tutorial
	cd ${WRKDIR} &&	\
	${TAR} cfj ${_DISTDIR}${PORTNAME}-samples-java-${PORTVERSION}${EXTRACT_SUFX}	\
			${DISTNAME}/samples/standard/java
	cd ${WRKDIR} &&	\
	${TAR} cfj ${_DISTDIR}${PORTNAME}-samples-qt-${PORTVERSION}${EXTRACT_SUFX}	\
			${DISTNAME}/samples/standard/qt

.endif	# The sources tarballs are now available

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: to build OpenCascade, you should have at least"
	@${ECHO_MSG} "3.7 Gb of free disk space in build area!"
	@${ECHO_MSG}

pre-configure:
	${CHMOD} a+x ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|tclConfig.sh|tclConfig-threads.sh|'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|%%CASROOT%%|${CASROOT}|'	\
		-e 's|%%LOCALBASE%%|${LOCALBASE}|'	\
		-e 's|%%TCL_LIBDIR%%|${TCL_LIBDIR}|'	\
		-e 's|%%TK_LIBDIR%%|${TK_LIBDIR}|'	\
		-e 's|%%ITCLMM%%|${ITCL_VER}|'		\
		-e 's|%%ITKMM%%|${ITK_MM}|'		\
		-e 's|%%TIX_MM%%|${TIX_MM}|'		\
		-e 's|!/bin/ksh|! ${LOCALBASE}/bin/ksh|'\
		${WRKSRC}/env.csh ${WRKSRC}/env.ksh
	${REINPLACE_CMD} -e 's|/tmp/OCC50|${CASROOT}|'	\
		-e 's|/usr/bin/g++|${CXX}|'		\
		-e 's|/usr/bin/gcc|${CC}|'		\
		-e 's|%%JAVAHOME%%|${JAVA_HOME}|'	\
		-e 's|/usr/local|${LOCALBASE}|'		\
		-e 's|/usr/X11R6|${X11BASE}|'		\
		${WRKSRC}/src/OS/Draw.tcl		\
		${WRKSRC}/src/OS/Visualization.tcl	\
		${WRKSRC}/src/OS/ApplicationFramework.tcl
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|'\
		-e 's|/usr/X11R6|${X11BASE}|'		\
		-e 's|/usr/local/bin/tclsh8.4|${THRSH}|'\
		${PATCH_WRKSRC}/wok/site/wokinit.csh	\
		${WRKSRC}/src/WOKsite/wokinit.csh	\
		${WRKSRC}/src/OS/WOK.tcl
	${REINPLACE_CMD} -e 's|$${TCLBIN}/tclsh|${THRSH}|'	\
		${PATCH_WRKSRC}/wok/site/wok.csh		\
		${WRKSRC}/src/WOKsite/wok.csh
	${REINPLACE_CMD} -e 's|/usr/bin/g++|${CXX}|'	\
		-e 's|/usr/bin/gcc|${CC}|'		\
		-e 's|/usr/bin/f77|${F77}|'		\
		-e 's|/usr/bin/ld|${LD}|'		\
		-e 's|%%CXXFLAGS%%|${CXXFLAGS}|'	\
		-e 's|%%CFLAGS%%|${CFLAGS}|'		\
		-e 's|%%FFLAGS%%|${FFLAGS}|'		\
		-e 's|%%LOCALBASE%%|${LOCALBASE}|'	\
		-e 's|%%/usr/X11R6%%|${X11LBASE}|'	\
		-e 's|%%STL_COMPILER%%|${STL_COMPILER}|'\
		-e 's|%%TCL_INCDIR%%|${TCL_INCLUDEDIR}|'\
		-e 's|%%JAVA_HOME%%|${JAVA_HOME}|'	\
		${WRKSRC}/src/WOKBuilderDef/CSF.edl	\
		${PATCH_WRKSRC}/wok/lib/CSF.edl		\
		${WRKSRC}/src/WOKBuilderDef/CMPLRS.edl	\
		${PATCH_WRKSRC}/wok/lib/CMPLRS.edl	\
		${WRKSRC}/src/WOKBuilderDef/LDEXE.edl	\
		${PATCH_WRKSRC}/wok/lib/LDEXE.edl	\
		${WRKSRC}/src/WOKBuilderDef/LDSHR.edl	\
		${PATCH_WRKSRC}/wok/lib/LDSHR.edl
	cd ${WRKSRC} &&	\
		${TAR} cfz ${WRKDIR}/ros_src_to_avoid_make_clean.tbz ${SRC2INST}

post-install:
	${MKDIR} ${CASROOT}/bsd/bin ${OCCROOT}/samples
	${LN} -sf ${FBSDBIN:S|^|${PREFIX}/bin/|} ${CASROOT}/bsd/bin
	${LN} -sf ${PREFIX}/lib ${CASROOT}/bsd/lib
	${LN} -sf ${CASROOT}/bsd ${CASROOT}/${OPSYS}
	${INSTALL_DATA} ${PATCH_WRKSRC}/LICENSE ${OCCROOT}
	${INSTALL_DATA} ${WRKDIR}/LICENSE.${OPSYS} ${OCCROOT}
	@${ECHO_CMD} "To populate this directory, please install the following ports:"\
		> ${OCCROOT}/samples/README
	@${ECHO_CMD} "- cad/${PORTNAME}-tutorial" >> ${OCCROOT}/samples/README
	@${ECHO_CMD} "- cad/${PORTNAME}-samples-qt" >> ${OCCROOT}/samples/README
	@${ECHO_CMD} "- cad/${PORTNAME}-samples-java" >> ${OCCROOT}/samples/README
.for di in ${DIR2INST}
	cd ${PATCH_WRKSRC} &&	\
		${FIND} ${di} -type d -exec ${MKDIR} ${OCCROOT}/{} \;
	cd ${PATCH_WRKSRC} &&	\
		${FIND} ${di} -type f -exec ${INSTALL_DATA} {} ${OCCROOT}/{} \;
.endfor
	${LN} -sf ${PREFIX}/lib ${OCCROOT}/wok/lib/bsd
	cd ${OCCROOT} &&	\
		${FIND} ${DIR2INST} -name "*sh" -exec ${CHMOD} ${BINMODE} {} \;
.for es in env.csh env.ksh
	${INSTALL_SCRIPT} ${WRKSRC}/${es} ${CASROOT}
.endfor
	cd ${CASROOT} &&	\
		${TAR} xfz ${WRKDIR}/ros_src_to_avoid_make_clean.tbz
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${CASROOT}/src
	${FIND} ${OCCROOT} -name "*.orig" -exec ${RM} {} \;
	${FIND} ${CASROOT}/drv -type d -empty -exec ${TOUCH} {}/.keep-me \;
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
