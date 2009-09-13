# New ports collection makefile for:  opencascade
# Date created:               29 November 2005
# Whom:                       Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=		opencascade
PORTVERSION=		6.3
PORTREVISION=	6
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
		fltk.1:${PORTSDIR}/x11-toolkits/fltk		\
		dps.0:${PORTSDIR}/x11/dgs

USE_BZIP2=	yes
USE_BISON=	build
USE_TK=		84
USE_TCL_BUILD=	84
USE_TCL_RUN=	84
USE_TCL_THREADS=yes
USE_JAVA=	yes
USE_XORG=	xmu
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

PATCH_WRKSRC=	${WRKDIR}/OpenCASCADE${PORTVERSION}.0
WRKSRC=		${PATCH_WRKSRC}/ros
REINPLACE_ARGS=	-i ""
USE_AUTOTOOLS=	libtool:22
LIBTOOLFILES=	ros/configure
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR}				\
		--with-tk=${TK_LIBDIR}					\
		--with-java-include=${JAVA_HOME}/include		\
		--with-dps-include=${LOCALBASE}/include			\
		--with-dps-library=${LOCALBASE}/lib			\
		--with-gl-include=${LOCALBASE}/include			\
		--with-gl-library=${LOCALBASE}/lib			\
		--with-xmu-include=${LOCALBASE}/include/X11		\
		--with-xmu-library=${LOCALBASE}/lib			\
		--with-stlport-include=${LOCALBASE}/include/stlport	\
		--with-stlport-libname=stlport_${STL_COMPILER}		\
		--with-stlport-library=${LOCALBASE}/lib			\
		--enable-production=yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} ${GCC4WA} -I${LOCALBASE}/include	\
		-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}" ARCH=${ARCH}
# We strip the libs
MAKE_ENV=	INSTALL_STRIP_FLAG=-s OCC_BUILDDIR="${PATCH_WRKSRC}"	\
		OCC_INSTALLDIR="${OCCROOT}" PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes
USE_FORTRAN=	yes

STL_COMPILER?=	gcc
FFLAGS?=	-O2

LOCCROOT=	OpenCAS
OCCROOT=	${PREFIX}/${LOCCROOT}
CASROOT=	${OCCROOT}/ros
PLIST_SUB=	OCCROOT="${LOCCROOT}"
SUB_LIST=	OCCROOT="${OCCROOT}" PORTNAME=${PORTNAME} FILESDIR=${FILESDIR}
SUB_FILES=	pkg-message LICENSE.${OPSYS}
PKGMESSAGE=	${WRKDIR}/pkg-message

FBSDBIN=	DRAWEXE wokprocess woksh
DIR2INST=	data
#DIR2INST+=	tools wok
SRC2INST=	adm drv inc make src
.if !defined(NOPORTDOCS)
DIR2INST+=	doc
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700036 && defined(PACKAGE_BUILDING)
# Work-around for gcc-41+
GCC4WA=		-ffriend-injection -fpermissive
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: to build OpenCascade, you should have at least"
	@${ECHO_MSG} "3.7 Gb of free disk space in build area!"
	@${ECHO_MSG}

pre-configure:
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
		-e 's|/usr/X11R6|${LOCALBASE}|'		\
		${WRKSRC}/src/OS/Draw.tcl		\
		${WRKSRC}/src/OS/Visualization.tcl	\
		${WRKSRC}/src/OS/ApplicationFramework.tcl
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|'\
		-e 's|/usr/X11R6|${LOCALBASE}|'		\
		-e 's|/usr/local/bin/tclsh8.4|${TCLSH}|'\
		${WRKSRC}/src/WOKsite/wokinit.csh	\
		${WRKSRC}/src/OS/WOK.tcl
	${REINPLACE_CMD} -e 's|$${TCLBIN}/tclsh|${TCLSH}|'	\
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
		${WRKSRC}/src/WOKBuilderDef/CMPLRS.edl	\
		${WRKSRC}/src/WOKBuilderDef/LDEXE.edl	\
		${WRKSRC}/src/WOKBuilderDef/LDSHR.edl
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}		\
		${WRKSRC}/src/WOKBuilderDef/CSF.edl

pre-install:
	${MKDIR} ${CASROOT}

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
#	${LN} -sf ${PREFIX}/lib ${OCCROOT}/wok/lib/bsd
	cd ${OCCROOT} &&	\
		${FIND} ${DIR2INST} -name "*sh" -exec ${CHMOD} ${BINMODE} {} \;
.for es in env.csh env.ksh
	${INSTALL_SCRIPT} ${WRKSRC}/${es} ${CASROOT}
.endfor
	${FIND} ${OCCROOT} -name "*.orig" -exec ${RM} {} \;
	${FIND} ${CASROOT} -type d -empty -exec ${TOUCH} {}/.keep-me \;
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
