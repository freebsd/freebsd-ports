# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	ccx
PORTVERSION=	2.12
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
PKGNAMEPREFIX=	CalculiX-
DISTFILES=	${DIST_SOURCES}
DIST_SUBDIR=	calculix
EXTRACT_ONLY=	${DIST_SOURCES}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Three-Dimensional Structural Finite Element Program

LICENSE=	GPLv2

LIB_DEPENDS=	libarpack.so:math/arpack	\
		libspooles.so:math/spooles	\
		libtaucs.so:math/taucs

DIST_SOURCES=	ccx_${PORTVERSION}.src${EXTRACT_SUFX}
DIST_HTM=	ccx_${PORTVERSION}.htm${EXTRACT_SUFX}
DIST_PS=	ccx_${PORTVERSION}.ps${EXTRACT_SUFX}
DIST_EXAMPLES=	ccx_${PORTVERSION}.test${EXTRACT_SUFX}

USES=		blaslapack compiler:openmp fortran gmake tar:bzip2 shebangfix
USE_PERL5=	build
SHEBANG_FILES=	date.pl

ALL_TARGET=	#Empty

CCX_VER=	ccx_${PORTVERSION}
WRKSRC=		${WRKDIR}/CalculiX/${CCX_VER}/src

OPTIONS_DEFINE=	DOCS EXAMPLES

OPTIONS_SINGLE=	METIS
OPTIONS_SINGLE_METIS=	METIS4 METISEDF
OPTIONS_DEFAULT=	METISEDF

METIS4_DESC=	Reference Metis4 Implementation
METIS4_DEPENDS=	libmetis.so:math/metis4

METISEDF_DESC=	EDF Metis Variant
METISEDF_DEPENDS=	libmetis.so:math/metis-edf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DIST_HTM} ${DIST_PS}
EXTRACT_ONLY+=	${DIST_HTM} ${DIST_PS}
DOCSDIR=	${PREFIX}/share/doc/CalculiX
.endif

.if $(PORT_OPTIONS:MEXAMPLES)
DISTFILES+=	${DIST_EXAMPLES}
EXTRACT_ONLY+=	${DIST_EXAMPLES}
PLIST_SUB=	PORTEXAMPLES=""
.else
PLIST_SUB=	PORTEXAMPLES="@comment "
.endif

.if ${ARCH} == "sparc64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic
FFLAGS+=	-fpic
.endif

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%CC%%+${CC}+g ; \
	s+%%BLAS_LIBS%%+${BLASLIB}+ ; \
	s+%%LAPACK_LIBS%%+${LAPACKLIB}+ ; \
	s+%%LOCALBASE%%+${LOCALBASE}+g;' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CCX_VER} \
	  ${STAGEDIR}${PREFIX}/bin/ccx
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKDIR}/CalculiX/${CCX_VER}/doc/ccx && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR}/ccx)
	${INSTALL_DATA} ${WRKDIR}/CalculiX/${CCX_VER}/doc/${CCX_VER}.ps \
		${STAGEDIR}${DOCSDIR}
	@${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/${CCX_VER}.ps
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKDIR}/CalculiX/${CCX_VER}/test && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
