# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osmium
PORTVERSION=	git20130522
PORTREVISION=	1
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++/Javascript framework for working with OSM files

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal \
		boost_regex:${PORTSDIR}/devel/boost-libs \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		expat:${PORTSDIR}/textproc/expat2 \
		geos:${PORTSDIR}/graphics/geos \
		protobuf:${PORTSDIR}/devel/protobuf
BUILD_DEPENDS=	google-sparsehash>=2.0.2:${PORTSDIR}/devel/google-sparsehash
RUN_DEPENDS=	google-sparsehash>=2.0.2:${PORTSDIR}/devel/google-sparsehash

USE_GITHUB=	yes
GH_ACCOUNT=	joto
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	1a5bb26

CXXFLAGS+=	-I${LOCALBASE}/include \
		-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	JAVASCRIPT DOXYGEN DOCS
OPTIONS_DEFAULT=JAVASCRIPT DOCS
JAVASCRIPT_DESC=Enable javascript support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVASCRIPT}
LIB_DEPENDS+=	v8:${PORTSDIR}/lang/v8 \
		shp:${PORTSDIR}/devel/shapelib \
		icuuc:${PORTSDIR}/devel/icu
.endif

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

do-build:
.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKR_ARGS} doc
.else
	${DO_NADA}
.endif

regression-test:
	cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${SH} run_tests.sh

do-install:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} '${PORTNAME} ${PORTNAME}.hpp' \
		${PREFIX}/include/
.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.if ${PORT_OPTIONS:MDOXYGEN}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR}/
.endif
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/THANKS \
		${WRKSRC}/NOTES_FOR_DEVELOPERS ${DOCSDIR}/
.endif

.include <bsd.port.mk>
