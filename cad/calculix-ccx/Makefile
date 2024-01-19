PORTNAME=	ccx
PORTVERSION=	2.21
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
PKGNAMEPREFIX=	CalculiX-
DISTFILES=	${DIST_SOURCES}
DIST_SUBDIR=	calculix
EXTRACT_ONLY=	${DIST_SOURCES}

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Three-Dimensional Structural Finite Element Program
WWW=		http://www.calculix.de/

LICENSE=	GPLv2

LIB_DEPENDS=	libarpack.so:math/arpack-ng	\
		libspooles.so:math/spooles

USES=		blaslapack fortran gmake perl5 tar:bzip2
USE_PERL5=	build

DIST_SOURCES=	ccx_${PORTVERSION}.src${EXTRACT_SUFX}
DIST_HTM=	ccx_${PORTVERSION}.htm${EXTRACT_SUFX}
DIST_PDF=	ccx_${PORTVERSION}.pdf
DIST_EXAMPLES=	ccx_${PORTVERSION}.test${EXTRACT_SUFX}

ALL_TARGET=	#Empty

CCX_VER=	ccx_${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/CalculiX
WRKSRC=		${WRKDIR}/CalculiX/${CCX_VER}/src

OPTIONS_DEFINE=	DOCS EXAMPLES

CFLAGS+=	-fpic
FFLAGS+=	-fpic

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DIST_HTM} ${DIST_PDF}
EXTRACT_ONLY+=	${DIST_HTM}
.endif

.if $(PORT_OPTIONS:MEXAMPLES)
DISTFILES+=	${DIST_EXAMPLES}
EXTRACT_ONLY+=	${DIST_EXAMPLES}
.endif

.if ${GCC_DEFAULT} >= 10
# workaround for Missing actual argument for argument '_formal_15' at (1)
FFLAGS+=	-fallow-argument-mismatch
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
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DIST_PDF} \
		${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKDIR}/CalculiX/${CCX_VER}/test && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
