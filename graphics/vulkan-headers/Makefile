PORTNAME=	vulkan-headers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.322
CATEGORIES=	graphics

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Headers for the Vulkan graphics API
WWW=		https://github.com/KhronosGroup/Vulkan-Headers

LICENSE=	APACHE20

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Headers

# XXX Add clang-scan-deps to WITH_CLANG_EXTRAS in src.conf(5)
.if exists(/usr/bin/clang) && !exists(/usr/bin/clang-scan-deps)
CMAKE_OFF+=	VULKAN_HEADERS_ENABLE_MODULE
.endif

STRIP=		# nothing to strip
NO_ARCH=	yes

post-extract:
# genvk.py requires docgenerator.py from Vulkan-Docs, so drop useless shebang
	@${FIND} ${WRKSRC}/registry -name \*.py -exec ${REINPLACE_CMD} -i '' '/^#!/d' {} +

.include <bsd.port.mk>
