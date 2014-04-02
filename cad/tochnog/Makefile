# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	tochnog
PORTVERSION=	20140100
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/Tochnog%20Latest%20January%202014
DISTFILES=	Sources${EXTRACT_SUFX} gid${EXTRACT_SUFX} \
		tools${EXTRACT_SUFX} test${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free explicit/implicit Finite Element Program

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libf2c.a:${PORTSDIR}/lang/f2c

OPTIONS_DEFINE=	ATLAS EXAMPLES THREADS
ATLAS_DESC=	Use ATLAS instead of BLAS/LAPACK

WRKSRC=		${WRKDIR}/Sources/Tochnog-Latest-jan-2014
MAKEFILE=	makefile
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} PTHREAD_CFLAGS=${PTHREAD_CFLAGS}
USES=		fortran zip dos2unix
DOS2UNIX_FILES=	time.cc time.h tnlapack.h tnsuplu.h

# You can set GIDDIR to share/gid to install the scripts to be used
# with the cad/linux-gid port, otherwise they can be linked to the data
# directory to avoid polluting the port space.

GIDDIR?=	share/${PORTNAME}
PLIST_SUB+=	GIDDIR=${GIDDIR}
GID_PTYPES=	${PREFIX}/${GIDDIR}/problemtypes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
.if ${PORT_OPTIONS:MTHREADS}
BLAS_LIBS=	-lptf77blas
.else
BLAS_LIBS=	-lf77blas
.endif
.else
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas	\
		liblapack.so:${PORTSDIR}/math/lapack
BLAS_LIBS=	-llapack -lblas
.endif

.if ${PORT_OPTIONS:MTHREADS}
ALL_TARGET=	freebsd_parallel
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsuperlu_mt.a:${PORTSDIR}/math/superlu_mt
SUPERLU=	superlu_mt
.else
ALL_TARGET=	freebsd_old
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu
SUPERLU=	superlu
.endif

post-extract:
.for sup in gid tools test
	${MV} ${WRKDIR}/${sup} ${WRKDIR}/Sources/
.endfor

pre-configure:
.for hd in pthread.h
	${MV} ${WRKSRC}/${hd} ${WRKSRC}/${hd}.orig
.endfor
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g ; \
	s,%%SUPERLU%%,${SUPERLU},g ; \
	s,%%BLAS_LIBS%%,-L${LOCALBASE}/lib ${BLAS_LIBS},g' \
	${WRKSRC}/makefile
.if ${PORT_OPTIONS:MTHREADS}
	${REINPLACE_CMD} -e 's,SUPERLU_MT_USE 0,SUPERLU_MT_USE 1,' \
	${WRKSRC}/tnsuplu.h
.else	# Serial
	${REINPLACE_CMD} -e 's,SUPERLU_USE 0,SUPERLU_USE 1,' \
	${WRKSRC}/tnsuplu.h
.endif

post-build:
	(cd ${WRKDIR}/Sources/tools && ${CXX} ${CXXFLAGS} -o aba2tn aba2tn.cc)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tochnog ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/Sources/tools/aba2tn ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/Sources/tools/*.awk ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${GID_PTYPES}/tochnog.gid
	${INSTALL_DATA} ${WRKDIR}/Sources/gid/tochnog.gid/tochnog.cnd	\
	  ${STAGEDIR}${GID_PTYPES}/tochnog.gid
	${INSTALL_DATA} ${WRKDIR}/Sources/gid/tochnog.gid/tochnog.mat	\
	  ${STAGEDIR}${GID_PTYPES}/tochnog.gid
	${INSTALL_SCRIPT} ${WRKDIR}/Sources/gid/tochnog.gid/tochnog.ba*	\
	  ${STAGEDIR}${GID_PTYPES}/tochnog.gid
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${RM} -f ${WRKDIR}/Sources/test/*.orig
	${INSTALL_DATA} ${WRKDIR}/Sources/test/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
