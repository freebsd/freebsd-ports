# Created by: Tim Niemueller <tim@niemueller.de>
# $FreeBSD$

PORTNAME=	yaml-cpp
PORTVERSION=	0.3.0
PORTREVISION=	1
DISTVERSIONPREFIX=	release-
CATEGORIES=	devel
PKGNAMESUFFIX=	03

MAINTAINER=	tim@niemueller.de
COMMENT=	YAML parser and emitter in C++ matching the YAML 1.2 spec

LICENSE=	MIT

USES=		compiler:c++11-lang cmake
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON -DYAML_CPP_BUILD_TOOLS=0

USE_GITHUB=	yes
GH_ACCOUNT=	jbeder

post-patch: .SILENT
	${FIND} ${WRKSRC} -name '*.[hc]*' -o -name CMakeLists.txt | \
		${XARGS} ${REINPLACE_CMD} -e 's|yaml-cpp|yaml-cpp${PKGNAMESUFFIX}|g'
	${MV} ${WRKSRC}/include/yaml-cpp ${WRKSRC}/include/yaml-cpp${PKGNAMESUFFIX}
	${MV} ${WRKSRC}/yaml-cpp.pc.cmake ${WRKSRC}/yaml-cpp${PKGNAMESUFFIX}.pc.cmake

.include <bsd.port.mk>
