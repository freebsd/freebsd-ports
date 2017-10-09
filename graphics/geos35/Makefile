# Created by: Leonardo Martins <lmartins@nepe.eee.ufg.br>
# $FreeBSD$

PORTNAME=	geos
PORTVERSION=	3.5.0
PORTREVISION=	4
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/geos/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	35

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GEOS implements all the OpenGIS "Simple Features for SQL" (legacy)

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	legacy version, no longer needed
EXPIRATION_DATE=2017-11-09

CONFIGURE_ARGS=	--program-suffix=35
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		gmake libtool tar:bzip2

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||' ${WRKSRC}/tests/geostest/Makefile.in ${WRKSRC}/tests/thread/Makefile.in

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -exec ${REINPLACE_CMD} -e '/CXXFLAGS = / s| -O2||' '{}' \;

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/geos35
	@${MV} ${STAGEDIR}${PREFIX}/include/geos ${STAGEDIR}${PREFIX}/include/geos35
	@${MV} ${STAGEDIR}${PREFIX}/include/*.h ${STAGEDIR}${PREFIX}/include/geos35
	@${RM} ${STAGEDIR}${PREFIX}/lib/libgeos_c*
	@${MV} ${STAGEDIR}${PREFIX}/lib/libgeos.a ${STAGEDIR}${PREFIX}/lib/libgeos35.a
	@${MV} ${STAGEDIR}${PREFIX}/lib/libgeos.so ${STAGEDIR}${PREFIX}/lib/libgeos35.so
	@${FIND} ${STAGEDIR}${PREFIX}/include -type f -exec ${REINPLACE_CMD} -i '' \
		-e 's|include <geos|&35/geos|' {} \;

.include <bsd.port.mk>
