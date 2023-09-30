PORTNAME=	calculix
PORTVERSION=	2.21
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
DISTFILES=	${DIST_SOURCES}
DIST_SUBDIR=	calculix
EXTRACT_ONLY=	${DIST_SOURCES}

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Three-Dimensional Structural Finite Element Program
WWW=		http://www.calculix.de/

LICENSE=	GPLv2

RUN_DEPENDS=	ccx:cad/calculix-ccx

USES=		gl gmake tar:bzip2 compiler:c++11-lib xorg
USE_GL=		gl glu # uses its own glut
USE_XORG=	ice sm x11 xext xi xmu xt

CXXFLAGS+=	-std=c++98

DOCSDIR=	${PREFIX}/share/doc/CalculiX

WRKSRC=		${WRKDIR}/CalculiX

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_DISTFILES=	${DIST_HTM} ${DIST_PDF}
DOCS_EXTRACT_ONLY=	${DIST_HTM}
EXAMPLES_DISTFILES=	${DIST_EXAMPLES}
EXAMPLES_EXTRACT_ONLY=	${DIST_EXAMPLES}

BROWSER?=	firefox
CGX_VER=	cgx_${PORTVERSION}
DIST_EXAMPLES=	cgx_${PORTVERSION}.exa${EXTRACT_SUFX}
DIST_HTM=	cgx_${PORTVERSION}.htm${EXTRACT_SUFX}
DIST_PDF=	cgx_${PORTVERSION}.pdf
DIST_SOURCES=	cgx_${PORTVERSION}.all${EXTRACT_SUFX}
PSVIEWER?=	gv

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
USES+=	llvm:max=15
.endif

CFLAGS+=	-fpic
FFLAGS+=	-fpic

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CPPFLAGS+=	-Wno-error=int-conversion
.endif

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
