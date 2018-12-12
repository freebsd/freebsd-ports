# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	ccx
PORTVERSION=	2.14
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
PKGNAMEPREFIX=	CalculiX-
DISTFILES=	${DIST_SOURCES}
DIST_SUBDIR=	calculix
EXTRACT_ONLY=	${DIST_SOURCES}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Three-Dimensional Structural Finite Element Program

LICENSE=	GPLv2

LIB_DEPENDS=	libarpack.so:math/arpack-ng	\
		libmetis.so:math/metis4 	\
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
DOCSDIR=	${PREFIX}/share/doc/CalculiX

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DIST_HTM} ${DIST_PS}
EXTRACT_ONLY+=	${DIST_HTM} ${DIST_PS}
.endif

.if $(PORT_OPTIONS:MEXAMPLES)
DISTFILES+=	${DIST_EXAMPLES}
EXTRACT_ONLY+=	${DIST_EXAMPLES}
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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKDIR}/CalculiX/${CCX_VER}/doc/ccx && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR}/ccx)
	${INSTALL_DATA} ${WRKDIR}/CalculiX/${CCX_VER}/doc/${CCX_VER}.ps \
		${STAGEDIR}${DOCSDIR}
	@${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/${CCX_VER}.ps

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKDIR}/CalculiX/${CCX_VER}/test && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
