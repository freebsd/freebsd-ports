PORTNAME=	nvidia-texture-tools
PORTVERSION=	2.1.2
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Texture Tools with support for DirectX 10 texture formats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	i386 amd64 powerpc powerpc64 armv6 aarch64  # see src/nvcore/nvcore.h

USES=		cmake compiler:c++11-lang
CMAKE_ON=	NVTT_SHARED \
		NVCORE_SHARED \
		NVTHREAD_SHARED \
		NVIMAGE_SHARED

USE_GITHUB=	yes
GH_ACCOUNT=	castano
USE_LDCONFIG=	yes

CFLAGS_i386=	-msse -msse2

PORTDOCS=	ChangeLog README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
