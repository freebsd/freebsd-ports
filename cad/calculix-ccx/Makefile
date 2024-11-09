PORTNAME=	ccx
DISTVERSION=	2.22
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
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libspooles.so:math/spooles

USES=		blaslapack fortran gmake perl5 tar:bzip2
USE_PERL5=	build

DIST_SOURCES=	ccx_${DISTVERSION}.src${EXTRACT_SUFX}
DIST_HTM=	ccx_${DISTVERSION}.htm${EXTRACT_SUFX}
DIST_PDF=	ccx_${DISTVERSION}.pdf
DIST_EXAMPLES=	ccx_${DISTVERSION}.test${EXTRACT_SUFX}

ALL_TARGET=

CFLAGS+=	-fpic
FFLAGS+=	-fpic

CCX_VER=	ccx_${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/CalculiX
TEST_WRKSRC=	${WRKDIR}/CalculiX/${CCX_VER}/test
WRKSRC=		${WRKDIR}/CalculiX/${CCX_VER}/src

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_DISTFILES=		${DIST_HTM} ${DIST_PDF}
DOCS_EXTRACT_ONLY=	${DIST_HTM}
EXAMPLES_DISTFILES=	${DIST_EXAMPLES}
EXAMPLES_EXTRACT_ONLY=	${DIST_EXAMPLES}

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

do-test:
	@cd ${TEST_WRKSRC} && ( \
		${SH} compare \
	)

.include <bsd.port.mk>
