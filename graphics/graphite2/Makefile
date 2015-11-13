# $FreeBSD$

PORTNAME=	graphite2
PORTVERSION=	1.3.3
CATEGORIES=	graphics print
MASTER_SITES=	http://projects.palaso.org/attachments/download/434/ \
		SF/silgraphite/${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Rendering capabilities for complex non-Roman writing systems

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

USES=		cmake tar:tgz
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/pkgconfig,data/pkgconfig,g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
