# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openjph
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source implementation of JPEG2000 Part-15

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake compiler:c++11-lang pathfix

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	aous72
GH_PROJECT=	OpenJPH
USE_GITHUB=	yes

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DOJPH_DISABLE_INTEL_SIMD:BOOL=ON
.endif

.include <bsd.port.mk>
