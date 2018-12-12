# Created by: Johnny Sorocil <jsorocil@gmail.com>
# $FreeBSD$

PORTNAME=	arachne-pnr
PORTVERSION=	g20181021
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jsorocil@gmail.com
COMMENT=	Place and route tool for FPGAs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	icestorm>=g0:devel/icestorm

USES=		compiler:c++11-lang gmake

USE_GITHUB=	yes
GH_ACCOUNT=	cseed
GH_TAGNAME=	840bdfdeb38809f9f6af4d89dd7b22959b176fdd

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/arachne-pnr

.include <bsd.port.mk>
