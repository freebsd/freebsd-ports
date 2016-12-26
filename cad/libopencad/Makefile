# Created by: lbartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	libopencad
PORTVERSION=	0.2.0
CATEGORIES=	cad graphics geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Library which provides a way to read/write CAD (DWG/DXF/DXFB) files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_9=	does not build (lack of c++11 support)

USE_GITHUB=	yes
GH_ACCOUNT=	sandyre

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

.include <bsd.port.mk>
