PORTNAME=	cpu_features
DISTVERSION=	0.6.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Cross platform C99 library to get cpu features at runtime

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		aarch64 armv6 armv7 mips mips64 riscv64
NOT_FOR_ARCHS_REASON=	assumes android if on ARM or MIPS; not ported to riscv64

USES=		cmake:testing # 3 tests fail, see https://github.com/google/cpu_features/issues/215
USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON=	BUILD_SHARED_LIBS

CFLAGS+=	-fPIC

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/internal
	${INSTALL_DATA} ${WRKSRC}/include/internal/hwcaps.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/internal/
	${INSTALL_DATA} ${WRKSRC}/include/cpuinfo_*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
