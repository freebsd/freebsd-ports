PORTNAME=	vulkan-headers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.223
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Headers for the Vulkan graphics API

LICENSE=	APACHE20

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Headers
STRIP=		# nothing to strip
NO_ARCH=	yes

post-patch:
# XXX Drop after FreeBSD 12.* EOL around 2024-06-30
	@if [ -L /usr/include/sched.h ]; then \
		${REINPLACE_CMD} $$'/^namespace/i\\\n#undef major\\\n#undef minor\\\n\\\n' \
			${WRKSRC}/include/vulkan/vulkan_structs.hpp; \
	fi

.include <bsd.port.mk>
