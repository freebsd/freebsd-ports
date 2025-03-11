PORTNAME=	clang-uml
PORTVERSION=	0.6.1
CATEGORIES=	graphics lang textproc

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	C++ UML diagram generator based on Clang
WWW=		https://github.com/bkryza/clang-uml

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++17-lang llvm:noexport,lib localbase:ldflags

CMAKE_ARGS+=	-DCLANG_UML_ENABLE_BACKTRACE=OFF \
		-DBUILD_TESTS=OFF

USE_GITHUB=	yes
GH_ACCOUNT=	bkryza

.include <bsd.port.mk>
