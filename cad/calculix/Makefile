# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	CalculiX
PORTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
DISTFILES=	${DIST_SOURCES}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DIST_HTM} ${DIST_PS} ${DIST_PDF}
.endif
.ifdef WITH_EXAMPLES
DISTFILES+=	${DIST_EXAMPLES}
.endif
DIST_SUBDIR=	calculix
EXTRACT_ONLY=	${DIST_SOURCES}
.if !defined(NOPORTDOCS)
EXTRACT_ONLY+=	${DIST_HTM} ccx_${PORTVERSION}.ps${EXTRACT_SUFX}
.endif
.ifdef WITH_EXAMPLES
EXTRACT_ONLY+=	${DIST_EXAMPLES}
.endif

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A Three-Dimensional Structural Finite Element Program

LICENSE=	GPLv2

LIB_DEPENDS=	arpack.1:${PORTSDIR}/math/arpack	\
		spooles.1:${PORTSDIR}/math/spooles \
		taucs.1:${PORTSDIR}/math/taucs

USE_BZIP2=	yes

DIST_SOURCES=	ccx_${PORTVERSION}.src${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.all${EXTRACT_SUFX}
DIST_HTM=	ccx_${PORTVERSION}.htm${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.htm${EXTRACT_SUFX}
DIST_PS=	ccx_${PORTVERSION}.ps${EXTRACT_SUFX}
DIST_PDF=	cgx_${PORTVERSION}.pdf
DIST_EXAMPLES=	ccx_${PORTVERSION}.test${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.exa${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_XORG=	xmu
USE_GL=	glut

BROWSER?=	firefox
PSVIEWER?=	gv

CCX_VER=	ccx_${PORTVERSION}
CGX_VER=	cgx_2.6

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

OPTIONS_DEFINE= METIS METIS_EDF
OPTIONS_DEFAULT=METIS

.if ${PORT_OPTIONS:MMETIS}
LIB_DEPENDS+= 	metis.1:${PORTSDIR}/math/metis4
.endif
.if ${PORT_OPTIONS:MMETIS_EDF}
LIB_DEPENDS+= 	metis.1:${PORTSDIR}/math/metis-edf
.endif

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=             yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=		atlas.2:${PORTSDIR}/math/atlas
BLAS_LIBS=		-lf77blas
LAPACK_LIBS=		-lalapack -lcblas
.else
LIB_DEPENDS+=		blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=		lapack.4:${PORTSDIR}/math/lapack
BLAS_LIBS=		-lblas
LAPACK_LIBS=		-llapack
.endif

USE_FORTRAN=	yes
USE_GCC=	yes

.if ${ARCH} == "sparc64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic
FFLAGS+=	-fpic
.endif

.if !defined(WITH_EXAMPLES)
PLIST_SUB=	WITH_EXAMPLES="@comment "
.else
PLIST_SUB=	WITH_EXAMPLES=""
.endif

.ifndef (WITH_EXAMPLES)
pre-everything::
	@${ECHO} "You can define WITH_EXAMPLES=yes to install example files"
.endif

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%CC%%+${CC}+g ; \
	s+%%BLAS_LIBS%%+${BLAS_LIBS}+ ; \
	s+%%LAPACK_LIBS%%+${LAPACK_LIBS}+ ; \
	s+%%LOCALBASE%%+${LOCALBASE}+g;' \
		${WRKSRC}/${CCX_VER}/src/Makefile
	@${REINPLACE_CMD} -e 's/c++/${CXX}/g;' \
		${WRKSRC}/libSNL/src/makefile
	@${REINPLACE_CMD} -e 's+%%DOCSDIR%%+${DOCSDIR}+g; \
	s+"firefox"+"${BROWSER}"+ ; \
	s+"gv"+"${PSVIEWER}"+ ;' \
		${WRKSRC}/${CGX_VER}/src/cgx.h

do-build:
	@(cd ${WRKSRC}/${CCX_VER}/src; ${SETENV} ${MAKE_ENV} $(GMAKE) )
	@(cd ${WRKSRC}/libSNL/src; ${SETENV} ${MAKE_ENV} $(GMAKE) )
	@(cd ${WRKSRC}/${CGX_VER}/src; ${SETENV} ${MAKE_ENV} $(GMAKE) )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${CCX_VER}/src/${CCX_VER} \
	  ${PREFIX}/bin/ccx
	@${INSTALL_PROGRAM} ${WRKSRC}/${CGX_VER}/src/cgx \
	  ${PREFIX}/bin/cgx
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/ccx
	@${INSTALL_DATA} ${WRKSRC}/${CCX_VER}/doc/ccx/* \
	  ${DOCSDIR}/ccx
	@${MKDIR} ${DOCSDIR}/cgx
	@${INSTALL_DATA} ${WRKSRC}/${CGX_VER}/doc/cgx/* \
	  ${DOCSDIR}/cgx
	@${INSTALL_DATA} ${WRKSRC}/${CCX_VER}/doc/*.ps ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cgx_${PORTVERSION}.pdf \
	  ${DOCSDIR}
	@${GZIP_CMD} ${DOCSDIR}/*.ps
.endif
.ifdef WITH_EXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} cf - -C ${WRKSRC}/${CGX_VER}/examples . | ${TAR} xf - -C ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/test
	@${TAR} cf - -C ${WRKSRC}/${CCX_VER}/test . | ${TAR} xf - -C ${EXAMPLESDIR}/test
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
