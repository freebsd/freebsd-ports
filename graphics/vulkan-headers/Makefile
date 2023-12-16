PORTNAME=	vulkan-headers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.273
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Headers for the Vulkan graphics API
WWW=		https://github.com/KhronosGroup/Vulkan-Headers

LICENSE=	APACHE20

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Headers
STRIP=		# nothing to strip
NO_ARCH=	yes

post-extract:
# genvk.py requires docgenerator.py from Vulkan-Docs, so drop useless shebang
	@${FIND} ${WRKSRC}/registry -name \*.py -exec ${REINPLACE_CMD} -i '' '/^#!/d' {} +

post-patch:
# XXX Drop after FreeBSD 12.4 EOL around 2023-12-31
	@if [ -L /usr/include/sched.h ]; then \
		${REINPLACE_CMD} $$'/^namespace/i\\\n#undef major\\\n#undef minor\\\n\\\n' \
			${WRKSRC}/include/vulkan/vulkan_structs.hpp; \
	fi

.include <bsd.port.mk>
