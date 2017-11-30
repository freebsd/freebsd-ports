# Created by: lbartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	libopencad
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	cad graphics geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Library which provides a way to read/write CAD (DWG/DXF/DXFB) files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=		fails to compile: cadheader.cpp: ambiguous conversion for functional-style cast from 'time_t' to 'CADVariant'
BROKEN_armv7=		fails to compile: cadheader.cpp: ambiguous conversion for functional-style cast from 'time_t' to 'CADVariant'
BROKEN_powerpc64=	fails to compile: r2000.cpp: 'to_string' was not declared in this scope

USE_GITHUB=	yes
GH_ACCOUNT=	sandyre

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

.include <bsd.port.mk>
