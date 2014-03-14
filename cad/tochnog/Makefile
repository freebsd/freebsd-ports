# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	tochnog
PORTVERSION=	20010211
PORTREVISION=	9
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/feb11_2001
DISTNAME=	${PORTNAME}_feb11_2001

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free explicit/implicit Finite Element Program

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-07

BUILD_DEPENDS=	${LOCALBASE}/lib/libf2c.a:${PORTSDIR}/lang/f2c

OPTIONS_DEFINE=	ATLAS EXAMPLES THREADS
ATLAS_DESC=	Use ATLAS instead of BLAS/LAPACK

WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile
USES=		fortran

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
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
BLAS_LIBS=	-lblas
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

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g ; \
	s,%%SUPERLU%%,${SUPERLU},g ; \
	s,%%BLAS_LIBS%%,-L${LOCALBASE}/lib ${BLAS_LIBS},g' \
	${WRKSRC}/makefile
.if ${PORT_OPTIONS:MTHREADS}
	@${REINPLACE_CMD} -e 's,SUPERLU_MT_USE 0,SUPERLU_MT_USE 1,' \
	${WRKSRC}/tnsuplu.h
.else	# Serial
	@${REINPLACE_CMD} -e 's,SUPERLU_USE 0,SUPERLU_USE 1,' \
	${WRKSRC}/tnsuplu.h
.endif

post-build:
	(cd ${WRKDIR}/tochnog/tools && ${CXX} ${CXXFLAGS} -o aba2tn aba2tn.cc)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tochnog ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/tochnog/tools/aba2tn ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/tochnog/tools/*.awk ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${GID_PTYPES}/tochnog.gid
	${INSTALL_DATA} ${WRKDIR}/tochnog/gid/tochnog.gid/tochnog.cnd	\
	  ${STAGEDIR}${GID_PTYPES}/tochnog.gid
	${INSTALL_DATA} ${WRKDIR}/tochnog/gid/tochnog.gid/tochnog.mat	\
	  ${STAGEDIR}${GID_PTYPES}/tochnog.gid
	${INSTALL_SCRIPT} ${WRKDIR}/tochnog/gid/tochnog.gid/tochnog.ba*	\
	  ${STAGEDIR}${GID_PTYPES}/tochnog.gid
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${RM} -f ${WRKDIR}/tochnog/test/*.orig
	${INSTALL_DATA} ${WRKDIR}/tochnog/test/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
