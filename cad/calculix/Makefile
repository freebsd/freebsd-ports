# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	CalculiX
PORTVERSION=	2.11
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
DISTFILES=	${DIST_SOURCES}
DIST_SUBDIR=	calculix
EXTRACT_ONLY=	${DIST_SOURCES}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Three-Dimensional Structural Finite Element Program

LICENSE=	GPLv2

LIB_DEPENDS=	libarpack.so:math/arpack	\
		libspooles.so:math/spooles	\
		libtaucs.so:math/taucs

DIST_SOURCES=	ccx_${PORTVERSION}.src${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.all${EXTRACT_SUFX}
DIST_HTM=	ccx_${PORTVERSION}.htm${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.htm${EXTRACT_SUFX}
DIST_PS=	ccx_${PORTVERSION}.ps${EXTRACT_SUFX}
DIST_PDF=	cgx_${PORTVERSION}.pdf
DIST_EXAMPLES=	ccx_${PORTVERSION}.test${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.exa${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${PORTNAME}
CCX_VER=	ccx_${PORTVERSION}
CGX_VER=	cgx_${PORTVERSION}

USES=		compiler:openmp fortran gmake tar:bzip2
USE_GCC=	yes
USE_XORG=	ice sm x11 xext xi xmu xt
USE_GL= 	gl glu glut

BROWSER?=	firefox
PSVIEWER?=	gv

OPTIONS_DEFINE=	METIS METIS_EDF DOCS EXAMPLES
OPTIONS_DEFAULT=METIS_EDF

OPTIONS_RADIO=  BLAS
OPTIONS_RADIO_BLAS=     REFERENCE OBLAS
OPTIONS_DEFAULT=        REFERENCE

REFERENCE_DESC= Blas / Lapack
REFERENCE_USES= blaslapack:netlib

OBLAS_DESC=     Openblas
OBLAS_USES=     blaslapack:openblas

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
DISTFILES+=	${DIST_EXAMPLES}
EXTRACT_ONLY+=	${DIST_EXAMPLES}
.endif

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DIST_HTM} ${DIST_PS} ${DIST_PDF}
EXTRACT_ONLY+=	${DIST_HTM} ccx_${PORTVERSION}.ps${EXTRACT_SUFX}
.endif

.if ${PORT_OPTIONS:MMETIS}
LIB_DEPENDS+=	libmetis.so:math/metis4
.endif
.if ${PORT_OPTIONS:MMETIS_EDF}
LIB_DEPENDS+=	libmetis.so:math/metis-edf
.endif

.if ${ARCH} == "sparc64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic
FFLAGS+=	-fpic
.endif

.if empty(PORT_OPTIONS:MEXAMPLES)
PLIST_SUB=	PORTEXAMPLES="@comment "
.else
PLIST_SUB=	PORTEXAMPLES=""
.endif

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%CC%%+${CC}+g ; \
	s+%%BLAS_LIBS%%+${BLASLIB}+ ; \
	s+%%LAPACK_LIBS%%+${LAPACKLIB}+ ; \
	s+%%LOCALBASE%%+${LOCALBASE}+g;' \
		${WRKSRC}/${CCX_VER}/src/Makefile
	@${REINPLACE_CMD} -e 's/c++/${CXX}/g;' \
		${WRKSRC}/libSNL/src/makefile
	@${REINPLACE_CMD} -e 's+%%DOCSDIR%%+${DOCSDIR}+g; \
	s+"firefox"+"${BROWSER}"+ ; \
	s+"gv"+"${PSVIEWER}"+ ;' \
		${WRKSRC}/${CGX_VER}/src/cgx.h

do-build:
	@(cd ${WRKSRC}/${CCX_VER}/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} )
	@(cd ${WRKSRC}/libSNL/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} )
	@(cd ${WRKSRC}/${CGX_VER}/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CCX_VER}/src/${CCX_VER} \
	  ${STAGEDIR}${PREFIX}/bin/ccx
	${INSTALL_PROGRAM} ${WRKSRC}/${CGX_VER}/src/cgx \
	  ${STAGEDIR}${PREFIX}/bin/cgx
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ccx
	@(cd ${WRKSRC}/${CCX_VER}/doc/ccx && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${DOCSDIR}/ccx)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/cgx
	@(cd ${WRKSRC}/${CGX_VER}/doc/cgx && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${DOCSDIR}/cgx)
	${INSTALL_DATA} ${WRKSRC}/${CCX_VER}/doc/${CCX_VER}.ps ${STAGEDIR}${DOCSDIR}
	@${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/${CCX_VER}.ps
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cgx_${PORTVERSION}.pdf \
	  ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/${CGX_VER}/examples && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/test
	@(cd ${WRKSRC}/${CCX_VER}/test && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${EXAMPLESDIR}/test)
.endif

.include <bsd.port.mk>
