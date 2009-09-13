# New ports collection makefile for:	CalculiX
# Date created:		19 April 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	CalculiX
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
DISTFILES=	${DIST_SOURCES}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DIST_HTM} ${DIST_PS}
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

LIB_DEPENDS=	arpack.1:${PORTSDIR}/math/arpack	\
		spooles.1:${PORTSDIR}/math/spooles \
		metis.1:${PORTSDIR}/math/metis	\
		taucs.1:${PORTSDIR}/math/taucs

USE_BZIP2=	yes

DIST_SOURCES=	ccx_${PORTVERSION}.src${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.all${EXTRACT_SUFX}
DIST_HTM=	ccx_${PORTVERSION}.htm${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.htm${EXTRACT_SUFX}
DIST_PS=	ccx_${PORTVERSION}.ps${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.ps.bz2
DIST_EXAMPLES=	ccx_${PORTVERSION}.test${EXTRACT_SUFX}	\
		cgx_${PORTVERSION}.exa${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_GL=	glut

BROWSER?=	mozilla
PSVIEWER?=	gv

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=             yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=		atlas.2:${PORTSDIR}/math/atlas
BLAS_LIBS=		-lf77blas -latlas
LAPACK_LIBS=		-lalapack -lcblas
.else
LIB_DEPENDS+=		blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=		lapack.4:${PORTSDIR}/math/lapack
BLAS_LIBS=		-lblas
LAPACK_LIBS=		-llapack
.endif

USE_FORTRAN=	yes

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
	s+%%PTHREAD_CFLAGS%%+-DUSE_MT ${PTHREAD_CFLAGS}+g; \
	s+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g; \
	s+%%BLAS_LIBS%%+${BLAS_LIBS}+ ; \
	s+%%LAPACK_LIBS%%+${LAPACK_LIBS}+ ; \
	s+%%LOCALBASE%%+${LOCALBASE}+g;' \
		${WRKSRC}/ccx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+g; \
	s+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g;' \
		${WRKSRC}/cgx_${PORTVERSION}/src/Makefile
	@${REINPLACE_CMD} -e 's+%%DOCSDIR%%+${DOCSDIR}+g; \
	s+"mozilla"+"${BROWSER}"+ ; \
	s+"ghostview"+"${PSVIEWER}"+ ;' \
		${WRKSRC}/cgx_${PORTVERSION}/src/cgx.h

do-build:
	@(cd ${WRKSRC}/ccx_${PORTVERSION}/src; ${SETENV} ${MAKE_ENV} $(GMAKE) )
	@(cd ${WRKSRC}/libSNL/src; ${SETENV} ${MAKE_ENV} $(GMAKE) )
	@(cd ${WRKSRC}/cgx_${PORTVERSION}/src; ${SETENV} ${MAKE_ENV} $(GMAKE) )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ccx_${PORTVERSION}/src/ccx_${PORTVERSION} \
	  ${PREFIX}/bin/ccx
	@${INSTALL_PROGRAM} ${WRKSRC}/cgx_${PORTVERSION}/src/cgx \
	  ${PREFIX}/bin/cgx
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/ccx
	@${INSTALL_DATA} ${WRKSRC}/ccx_${PORTVERSION}/doc/ccx/* \
	  ${DOCSDIR}/ccx
	@${MKDIR} ${DOCSDIR}/cgx
	@${INSTALL_DATA} ${WRKSRC}/cgx_${PORTVERSION}/doc/cgx/* \
	  ${DOCSDIR}/cgx
	@${INSTALL_DATA} ${WRKSRC}/ccx_${PORTVERSION}/doc/*.ps ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cgx_${PORTVERSION}.ps.bz2	\
	  ${DOCSDIR}
	bunzip2 ${DOCSDIR}/cgx_${PORTVERSION}.ps.bz2
	@${GZIP_CMD} ${DOCSDIR}/*.ps
.endif
.ifdef WITH_EXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} cf - -C ${WRKSRC}/cgx_${PORTVERSION}/examples . | ${TAR} xf - -C ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/test
	@${TAR} cf - -C ${WRKSRC}/ccx_${PORTVERSION}/test . | ${TAR} xf - -C ${EXAMPLESDIR}/test
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
