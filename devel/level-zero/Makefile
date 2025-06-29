PORTNAME=	level-zero
PORTVERSION=	1.22.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	oneAPI Level Zero Specification Headers and Loader
WWW=		https://spec.oneapi.io/versions/latest/elements/l0/source/index.html \
		https://github.com/oneapi-src/level-zero

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++14-lang localbase:ldflags pathfix

CMAKE_OFF=	BUILD_INSTALLER \
		BUILD_L0_LOADER_TESTS \
		BUILD_STATIC \
		USE_ASAN
CMAKE_ON=	SYSTEM_SPDLOG
LDFLAGS+=	-lfmt
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	oneapi-src

post-patch:
	@${ECHO_CMD} ${PORTVERSION:E} > ${WRKSRC}/VERSION_PATCH
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/third_party/spdlog_headers

.include <bsd.port.mk>
