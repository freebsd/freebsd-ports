PORTNAME=	cpu_features
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	devel

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Cross platform C99 library to get cpu features at runtime
WWW=		https://github.com/google/cpu_features

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		mips mips64 riscv64
NOT_FOR_ARCHS_REASON=	assumes android if on MIPS; not ported to riscv64

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

CFLAGS+=	-fPIC

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/internal
	${INSTALL_DATA} ${WRKSRC}/include/internal/hwcaps.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/internal/
	${INSTALL_DATA} ${WRKSRC}/include/cpuinfo_*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
