PORTNAME=	vkoverhead
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
CATEGORIES=	benchmarks

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	1a37beb59ac8.patch:-p1 # https://github.com/zmike/vkoverhead/pull/18
PATCHFILES+=	62c8ad1a795f.patch:-p1 # https://github.com/zmike/vkoverhead/pull/12

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Evaluate CPU overhead of Vulkan drivers
WWW=		https://github.com/zmike/vkoverhead

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	fails to build due -Werror=int-conversion
BROKEN_i386=	fails to build due -Werror=int-conversion
BROKEN_powerpc=	fails to build due -Werror=int-conversion

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR}
RUN_DEPENDS=	vulkan-loader>0:graphics/vulkan-loader

USES=		compiler:c11 meson python:build
USE_GITHUB=	yes
GH_ACCOUNT=	zmike
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Derive Python version from Meson
	@${REINPLACE_CMD} -e "s,'python3',," ${WRKSRC}/meson.build

.include <bsd.port.mk>
