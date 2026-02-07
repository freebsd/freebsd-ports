PORTNAME=	magic_enum
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.7
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Header-only C++17 library provides static reflection for enums
WWW=		https://github.com/Neargye/magic_enum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Neargye

NO_ARCH=	yes

post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake
	${MV} ${STAGEDIR}${PREFIX}/share/cmake/magic_enum ${STAGEDIR}${PREFIX}/lib/cmake/magic_enum
	${RMDIR} ${STAGEDIR}${PREFIX}/share/cmake
	${MV} ${STAGEDIR}${PREFIX}/share/pkgconfig/magic_enum.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/magic_enum.pc
	${RMDIR} ${STAGEDIR}${PREFIX}/share/pkgconfig

.include <bsd.port.mk>
