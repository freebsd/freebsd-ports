PORTNAME=	ampasACES-container
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	graphics devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ACES Container Reference Implementation

LICENSE=	AMPAS
LICENSE_NAME=	AMPAS
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	ampas
GH_PROJECT=	aces_container
GH_TAGNAME=	7a4e21e

USES=		cmake pathfix pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README.md

post-patch:
	@${REINPLACE_CMD} -e 's|lib/CMake|lib/cmake|' \
		${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
