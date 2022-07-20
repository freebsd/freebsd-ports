PORTNAME=	libopencad
PORTVERSION=	0.2.0
PORTREVISION=	5
CATEGORIES=	cad graphics geography

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Library which provides a way to read/write CAD (DWG/DXF/DXFB) files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=		fails to compile: cadheader.cpp: ambiguous conversion for functional-style cast from 'time_t' to 'CADVariant'
BROKEN_armv7=		fails to compile: cadheader.cpp: ambiguous conversion for functional-style cast from 'time_t' to 'CADVariant'

USE_GITHUB=	yes
GH_ACCOUNT=	sandyre

USES=		cmake cpe compiler:c++11-lib
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

.include <bsd.port.mk>
