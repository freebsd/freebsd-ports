# $FreeBSD$

PORTNAME=	graphite2
PORTVERSION=	1.3.1
CATEGORIES=	graphics print
MASTER_SITES=	SF/silgraphite/${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Rendering capabilities for complex non-Roman writing systems

USES=		cmake tar:tgz
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/pkgconfig,data/pkgconfig,g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
