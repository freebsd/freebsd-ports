PORTNAME=	calculix
DISTVERSION=	2.22
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
DISTFILES=	${DIST_SOURCES}
DIST_SUBDIR=	calculix
EXTRACT_ONLY=	${DIST_SOURCES}

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Three-Dimensional Structural Finite Element Program
WWW=		http://www.calculix.de/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/cgx_${DISTVERSION}/COPYING

RUN_DEPENDS=	ccx:cad/calculix-ccx

USES=		compiler:c++11-lib gl gmake tar:bzip2 xorg
USE_GL=		gl glu glut
USE_XORG=	ice sm x11 xext xi xmu xt

CXXFLAGS+=	-std=c++98

DOCSDIR=	${PREFIX}/share/doc/CalculiX

WRKSRC=		${WRKDIR}/CalculiX

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_DISTFILES=	${DIST_HTM} ${DIST_PDF}
DOCS_EXTRACT_ONLY=	${DIST_HTM}
EXAMPLES_DISTFILES=	${DIST_EXAMPLES}
EXAMPLES_EXTRACT_ONLY=	${DIST_EXAMPLES}

BROWSER?=	xdg-open
CGX_VER=	cgx_${DISTVERSION}
DIST_EXAMPLES=	cgx_${DISTVERSION}.exa${EXTRACT_SUFX}
DIST_HTM=	cgx_${DISTVERSION}.htm${EXTRACT_SUFX}
DIST_PDF=	cgx_${DISTVERSION}.pdf
DIST_SOURCES=	cgx_${DISTVERSION}.all${EXTRACT_SUFX}
PSVIEWER?=	gv

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
USES+=		llvm:max=15
CPPFLAGS+=	-Wno-error=int-conversion
.endif
CFLAGS+=	-fpic
FFLAGS+=	-fpic

.include <bsd.port.pre.mk>

pre-build:
	@${REINPLACE_CMD} -e 's!c++!${CXX}!g;' \
		${WRKSRC}/libSNL/src/makefile
	@${REINPLACE_CMD} -e 's+%%DOCSDIR%%+${DOCSDIR}+g; \
	s+"firefox"+"${BROWSER}"+ ; \
	s+"gv"+"${PSVIEWER}"+ ;' \
		${WRKSRC}/${CGX_VER}/src/cgx.h
	@${REINPLACE_CMD} -e 's!CalculiX/${CGX_VER}/doc!share/doc/CalculiX!g;' \
		${WRKSRC}/${CGX_VER}/src/cgx.h

do-build:
	@(cd ${WRKSRC}/libSNL/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} )
	@(cd ${WRKSRC}/${CGX_VER}/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CGX_VER}/src/cgx \
	  ${STAGEDIR}${PREFIX}/bin/cgx

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/cgx
	@(cd ${WRKSRC}/${CGX_VER}/doc/cgx && ${RM} *.old *~)
	@(cd ${WRKSRC}/${CGX_VER}/doc/cgx && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${DOCSDIR}/cgx)
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DIST_PDF} \
	  ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	# Some garbage crept in
	@${RM} ${WRKSRC}/${CGX_VER}/examples/OpenFOAM/couette/constant/polyMesh/*~
	@${RM} ${WRKSRC}/${CGX_VER}/examples/OpenFOAM/couette/constant/*~
	@${RM} ${WRKSRC}/${CGX_VER}/examples/OpenFOAM/couette/system/*~
	@${RM} ${WRKSRC}/${CGX_VER}/examples/ifwhiledemo/*.*~
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/${CGX_VER}/examples && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
