# $FreeBSD$

PORTNAME=	glslang
DISTVERSION=	11.2.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	OpenGL and OpenGL ES shader front end and validator

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE GPLv3+ MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lib python:3.4+,build
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
TEST_TARGET=	test

.include <bsd.port.mk>
