PORTNAME=	vkoverhead
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3
CATEGORIES=	benchmarks

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	62c8ad1a795f.patch:-p1 # https://github.com/zmike/vkoverhead/pull/12

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Evaluate CPU overhead of Vulkan drivers
WWW=		https://github.com/zmike/vkoverhead

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR}
RUN_DEPENDS=	vulkan-loader>0:graphics/vulkan-loader

USES=		compiler:c11 meson python:build
USE_GITHUB=	yes
GH_ACCOUNT=	zmike
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
