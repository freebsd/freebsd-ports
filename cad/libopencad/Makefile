PORTNAME=	libopencad
PORTVERSION=	0.2.0
PORTREVISION=	5
CATEGORIES=	cad graphics geography

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Library which provides a way to read/write CAD (DWG/DXF/DXFB) files
WWW=		https://trac.osgeo.org/gdal/wiki/DWG_driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sandyre

USES=		cmake cpe compiler:c++11-lib
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

.include <bsd.port.mk>
