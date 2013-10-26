# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	tochnog
PORTVERSION=	20010211
PORTREVISION=	7
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/feb11_2001
DISTNAME=	${PORTNAME}_feb11_2001

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free explicit/implicit Finite Element Program

.ifdef WITH_ATLAS
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas
.else
LIB_DEPENDS=	blas:${PORTSDIR}/math/blas
.endif
BUILD_DEPENDS=	${LOCALBASE}/lib/libf2c.a:${PORTSDIR}/lang/f2c
.ifdef WITH_THREADS
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsuperlu_mt.a:${PORTSDIR}/math/superlu_mt
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile

# You can set GIDDIR to share/gid to install the scripts to be used
# with the cad/linux-gid port, otherwise they can be linked to the data
# directory to avoid polluting the port space.

GIDDIR?=	share/${PORTNAME}
PLIST_SUB+=	GIDDIR=${GIDDIR}
GID_PTYPES=	${PREFIX}/${GIDDIR}/problemtypes

.ifdef WITH_ATLAS
.ifdef WITH_THREADS
BLAS_LIBS=	-lptf77blas
.else
BLAS_LIBS=	-lf77blas
.endif
.else	#BLAS
BLAS_LIBS?=	-lblas
.endif

.ifdef WITH_THREADS
SUPERLU=	superlu_mt
ALL_TARGET=	freebsd_parallel
.else
SUPERLU=	superlu
ALL_TARGET=	freebsd_old
.endif

USE_FORTRAN=	yes
FORTRANLIBS=	-lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

NO_STAGE=	yes
pre-build:
	@${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g ; \
	s,%%SUPERLU%%,${SUPERLU},g ; \
	s,%%FORTRANLIBS%%,${FORTRANLIBS},g ; \
	s,%%GCCLIBDIR%%,${GCCLIBDIR},g ; \
	s,%%BLAS_LIBS%%,-L${LOCALBASE}/lib ${BLAS_LIBS},g' \
	${WRKSRC}/makefile
.ifdef WITH_THREADS
	@${REINPLACE_CMD} -e 's,SUPERLU_MT_USE 0,SUPERLU_MT_USE 1,' \
	${WRKSRC}/tnsuplu.h
.else	# Serial
	@${REINPLACE_CMD} -e 's,SUPERLU_USE 0,SUPERLU_USE 1,' \
	${WRKSRC}/tnsuplu.h
.endif

post-build:
	@(cd ${WRKDIR}/tochnog/tools; ${CXX} ${CXXFLAGS} -o aba2tn aba2tn.cc)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tochnog ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/tochnog/tools/aba2tn ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/tochnog/tools/*.awk ${PREFIX}/bin
	${MKDIR} ${GID_PTYPES}/tochnog.gid
	${INSTALL_DATA} ${WRKDIR}/tochnog/gid/tochnog.gid/tochnog.cnd	\
	  ${GID_PTYPES}/tochnog.gid
	${INSTALL_DATA} ${WRKDIR}/tochnog/gid/tochnog.gid/tochnog.mat	\
	  ${GID_PTYPES}/tochnog.gid
	${INSTALL_SCRIPT} ${WRKDIR}/tochnog/gid/tochnog.gid/tochnog.ba*	\
	  ${GID_PTYPES}/tochnog.gid
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	@${RM} -f ${WRKDIR}/tochnog/test/*.orig
	${INSTALL_DATA} ${WRKDIR}/tochnog/test/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
