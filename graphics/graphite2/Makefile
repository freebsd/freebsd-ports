# $FreeBSD$

PORTNAME=	graphite2
PORTVERSION=	1.3.12
PORTREVISION=	1
CATEGORIES=	graphics print

MAINTAINER=	office@FreeBSD.org
COMMENT=	Rendering capabilities for complex non-Roman writing systems

LICENSE=	GPLv2 LGPL21 MPL20
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	silnrsi
GH_PROJECT=	graphite

post-patch:
	@${REINPLACE_CMD} -e 's|/pkgconfig|data&|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
