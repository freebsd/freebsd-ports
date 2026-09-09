PORTNAME=	tlottie
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	graphics

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Rust library for drawing Lottie animations
WWW=		https://github.com/dkaraush/tlottie

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
CARGO_FEATURES=	c-api

USE_GITHUB=	yes
GH_ACCOUNT=	dkaraush
GH_TAGNAME=	4b940c7

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/tlottie.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKDIR}/target/release/libtlottie.a ${STAGEDIR}${PREFIX}/lib
# Get ready to install shared library too when needed
#	${INSTALL_LIB} ${WRKDIR}/target/release/libtlottie.so ${STAGEDIR}${PREFIX}/lib
#	${LN} -sf libtlottie.so ${STAGEDIR}${PREFIX}/lib/libtlottie.so.${DISTVERSION:R}
#	${LN} -sf libtlottie.so ${STAGEDIR}${PREFIX}/lib/libtlottie.so.${DISTVERSION:R:R}

.include <bsd.port.mk>
