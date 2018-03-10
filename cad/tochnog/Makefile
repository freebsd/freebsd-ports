# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	tochnog
PORTVERSION=	20140100
PORTREVISION=	6
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/Tochnog%20Latest%20January%202014
DISTFILES=	Sources${EXTRACT_SUFX} gid${EXTRACT_SUFX} \
		tools${EXTRACT_SUFX} test${EXTRACT_SUFX}
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free explicit/implicit Finite Element Program

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libf2c.a:lang/f2c

OPTIONS_DEFINE=	ATLAS EXAMPLES
ATLAS_DESC=	Use ATLAS instead of BLAS/LAPACK

WRKSRC=		${WRKDIR}/Sources/Tochnog-Latest-jan-2014
MAKEFILE=	makefile
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
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS_LIBS=	-lf77blas
.else
LIB_DEPENDS+=	libblas.so:math/blas	\
		liblapack.so:math/lapack
BLAS_LIBS=	-llapack -lblas
.endif

ALL_TARGET=	freebsd_old
LIB_DEPENDS+=	libsuperlu.so:math/superlu
SUPERLU=	superlu

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
	${REINPLACE_CMD} -e 's,SUPERLU_USE 0,SUPERLU_USE 1,' \
	${WRKSRC}/tnsuplu.h

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
do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${RM} ${WRKDIR}/Sources/test/*.orig
	${INSTALL_DATA} ${WRKDIR}/Sources/test/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
