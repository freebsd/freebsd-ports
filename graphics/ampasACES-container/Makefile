# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ampasACES-container
PORTVERSION=	1.0.0
CATEGORIES=	graphics devel

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	ACES Container Reference Implementation

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	ampas
GH_PROJECT=	aces_container
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	d028c19

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

PORTDOCS=	README.md

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' \
		-e 's|lib/CMake|lib/cmake|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
