# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	calculix
PORTVERSION=	2.13
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.dhondt.de/
DISTFILES=	${DIST_SOURCES}
DIST_SUBDIR=	calculix
EXTRACT_ONLY=	${DIST_SOURCES}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Three-Dimensional Structural Finite Element Program

LICENSE=	GPLv2

RUN_DEPENDS=	ccx:cad/calculix-ccx

BROKEN_FreeBSD_10=	Does not build with clang on FreeBSD 10, causes segfaults when built with gcc

DIST_SOURCES=	cgx_${PORTVERSION}.all${EXTRACT_SUFX}
DIST_HTM=	cgx_${PORTVERSION}.htm${EXTRACT_SUFX}
DIST_PDF=	cgx_${PORTVERSION}.pdf
DIST_EXAMPLES=	cgx_${PORTVERSION}.exa${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/CalculiX
CGX_VER=	cgx_${PORTVERSION}

USES=		gmake tar:bzip2 compiler:c++11-lib
USE_XORG=	ice sm x11 xext xi xmu xt
USE_GL=		gl glu # uses its own glut

BROWSER?=	firefox
PSVIEWER?=	gv

CXXFLAGS+=	-std=c++98

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
DISTFILES+=	${DIST_EXAMPLES}
EXTRACT_ONLY+=	${DIST_EXAMPLES}
.endif

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DIST_HTM} ${DIST_PDF}
EXTRACT_ONLY+=	${DIST_HTM}
DOCSDIR=	${PREFIX}/share/doc/CalculiX
.endif

.if ${ARCH} == "sparc64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic
FFLAGS+=	-fpic
.endif

pre-build:
	@${REINPLACE_CMD} -e 's!c++!${CXX}!g;' \
		${WRKSRC}/libSNL/src/makefile
	@${REINPLACE_CMD} -e 's+%%DOCSDIR%%+${DOCSDIR}+g; \
	s+"firefox"+"${BROWSER}"+ ; \
	s+"gv"+"${PSVIEWER}"+ ;' \
		${WRKSRC}/${CGX_VER}/src/cgx.h

do-build:
	@(cd ${WRKSRC}/libSNL/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} )
	@(cd ${WRKSRC}/${CGX_VER}/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CGX_VER}/src/cgx \
	  ${STAGEDIR}${PREFIX}/bin/cgx
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/cgx
	@(cd ${WRKSRC}/${CGX_VER}/doc/cgx && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${DOCSDIR}/cgx)
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/cgx_${PORTVERSION}.pdf \
	  ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/${CGX_VER}/examples && ${COPYTREE_SHARE} . \
	  ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
