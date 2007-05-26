# New ports collection makefile for:	WildMagic
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	WildMagic
DISTVERSION=	4p4
CATEGORIES=	graphics
MASTER_SITES=	http://www.geometrictools.com/Downloads/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	The Wild Magic Real-Time 3D Graphics Engine

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GL=		yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/GeometricTools/${PORTNAME}${MV}
DOS2UNIX_REGEX=	.*\.(wm${MV}|h|inl)
MAKEFILE=	makefile.wm${MV}
ALL_TARGET=	build
MAKE_ARGS=	CFG=${CONFIG} SYS=${OPSYS:L} GRF=${GRF}
MAKE_ENV=	CC=${CXX} GCC=${CC} AR=${AR} EGL=${EGL} EGL0=glx EGL1=Glx	\
		INCPATH="-I${LOCALBASE}/include -I${X11BASE}/include"		\
		LIBPATH="-L${LOCALBASE}/lib -L${X11BASE}/lib"			\
		XLIBS="-lX11 -lXext" GLIBS="-lGL -lGLU"
PLIST_SUB=	CFG=${CONFIG} GRF=${GRF} WM=Wm${MV}

.if defined(WITH_OPENGL)
GRF=		OpenGL
EGL=		Glx
PLIST_SUB+=	OGL="" SOFT="@comment "
IGNORE=		this version does not run with OpenGL
.else
GRF=		Soft
EGL=		XSoft
PLIST_SUB+=	OGL="@comment " SOFT=""
.endif

MV=		${PORTVERSION:R}
SAMPLEDIRS=	SampleFoundation SampleGraphics SampleImagics SamplePhysics

.if defined(WITH_DEBUG)
CONFIG=		Debug
CFLAGS+=	-D_DEBUG
.else
# Legit values: Debug, Release, DebugMemory, ReleaseMemory
CONFIG=		Release
#CFLAGS+=	-DNDEBUG
.endif

pre-configure:
	${FIND} ${WRKSRC} -name "*.wm${MV}" | ${XARGS}	\
	${REINPLACE_CMD} -e 's|make -f|${SETENV} ${MAKE_ENV} ${GMAKE} -f|;	\
			s|; make |; ${SETENV} ${MAKE_ENV} ${GMAKE} |;		\
			s|-O2 -DNDEBUG|${CFLAGS} |;s|CFLAGS := -c|CFLAGS += -c|;\
			s|INCPATH := |INCPATH += |; s|LIBPATH := |LIBPATH += |'
	${REINPLACE_CMD} -e 's|GetEnv("WM4_PATH")|"${DATADIR}"|'	\
		${WRKSRC}/LibFoundation/System/Wm4System.cpp

post-build:
.for sd in ${SAMPLEDIRS}
	${FIND} ${WRKSRC}/${sd} -type f -perm 755 -exec	\
		${STRIP_CMD} {} \;
.endfor

do-install:
	${MKDIR} ${PREFIX}/include/Wm${MV} ${DATADIR}
	${FIND} ${WRKSRC}/SDK/Library/Release -name "libWm*" -exec	\
		${INSTALL_DATA} {} ${PREFIX}/lib \;
	${FIND} ${WRKSRC}/SDK/Include  -name "Wm*" -exec	\
		${INSTALL_DATA} {} ${PREFIX}/include/Wm${MV} \;
	${CP} -R ${WRKSRC}/Data ${DATADIR}
.ifndef NOPORTDOCS
	${MKDIR} ${EXAMPLESDIR}
. for sd in ${SAMPLEDIRS}
	${CP} -R ${WRKSRC}/${sd} ${EXAMPLESDIR}
. endfor
	# make clean
	${FIND} ${EXAMPLESDIR} -type d -name ${CONFIG} -exec	\
		${RM} -rf {} \; 2>/dev/null || ${TRUE}
	${FIND} ${EXAMPLESDIR} -name "*.orig" -delete
	${FIND} ${EXAMPLESDIR} -name "*.bak" -delete
.endif

.include <bsd.port.mk>
