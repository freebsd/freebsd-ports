PORTNAME=	tomlplusplus
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	TOML config parser and serializer for C++
WWW=		https://marzer.github.io/tomlplusplus/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake:indirect compiler:c++17-lang meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	marzer
MESON_FALSE=	use_vendored_libs

post-patch:
# Convert codeset from GNU to IANA
	@${REINPLACE_CMD} 's/utf8/UTF-8/' ${WRKSRC}/tests/meson.build

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dbuild_tests=true"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
