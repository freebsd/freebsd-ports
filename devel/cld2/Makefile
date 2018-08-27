# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cld
PORTVERSION=	20150505
CATEGORIES=	devel
MASTER_SITES=	LOCAL/demon
PKGNAMESUFFIX=	2

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Compact language detector library

LICENSE=	APACHE20

USES=		compiler
USE_LDCONFIG=	yes

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

post-patch:
	${REINPLACE_CMD} -e "s#g++#${CXX}#" ${WRKSRC}/internal/compile_libs.sh

do-build:
	cd ${WRKSRC}/internal && ${SETENV} ${MAKE_ENV} ./compile_libs.sh

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/cld/public ${STAGEDIR}${PREFIX}/include/cld/internal
	${INSTALL_DATA} ${WRKSRC}/public/encodings.h ${WRKSRC}/public/compact_lang_det.h ${STAGEDIR}${PREFIX}/include/cld/public/
	${INSTALL_DATA} ${WRKSRC}/internal/lang_script.h ${WRKSRC}/internal/integral_types.h ${WRKSRC}/internal/generated_language.h ${WRKSRC}/internal/generated_ulscript.h ${STAGEDIR}${PREFIX}/include/cld/internal/
	${INSTALL_LIB} ${WRKSRC}/internal/libcld2.so ${WRKSRC}/internal/libcld2_full.so ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
