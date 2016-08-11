# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	flatbuffers
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	yuri@rawbw.com
COMMENT=	Memory efficient serialization library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

.include <bsd.port.mk>
