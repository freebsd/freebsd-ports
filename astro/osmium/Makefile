# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osmium
PORTVERSION=	git20130522
PORTREVISION=	14
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++/Javascript framework for working with OSM files

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libboost_regex.so:devel/boost-libs \
		libsqlite3.so:databases/sqlite3 \
		libexpat.so:textproc/expat2 \
		libgeos.so:graphics/geos \
		libprotobuf.so:devel/protobuf
BUILD_DEPENDS=	sparsehash>=2.0.2:devel/sparsehash
RUN_DEPENDS=	sparsehash>=2.0.2:devel/sparsehash

USE_GITHUB=	yes
GH_ACCOUNT=	joto
GH_TAGNAME=	1a5bb26

CXXFLAGS+=	-I${LOCALBASE}/include \
		-L${LOCALBASE}/lib

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	JAVASCRIPT DOXYGEN DOCS
OPTIONS_DEFAULT=JAVASCRIPT
JAVASCRIPT_DESC=Enable javascript support

JAVASCRIPT_LIB_DEPENDS=	libv8.so:lang/v8 \
			libshp.so:devel/shapelib \
			libicuuc.so:devel/icu

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

do-build-DOXYGEN-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKR_ARGS} doc

do-install:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} '${PORTNAME} ${PORTNAME}.hpp' \
		${STAGEDIR}${PREFIX}/include/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/THANKS \
		${WRKSRC}/NOTES_FOR_DEVELOPERS ${STAGEDIR}${DOCSDIR}/
do-install-DOXYGEN-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${SH} run_tests.sh

.include <bsd.port.mk>
