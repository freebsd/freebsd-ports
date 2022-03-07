# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	openjph
PORTVERSION=	0.8.2
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source implementation of JPEG2000 Part-15

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

USES=		cmake compiler:c++11-lang # pathfix

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	aous72
GH_PROJECT=	OpenJPH
USE_GITHUB=	yes

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ON+=	OJPH_DISABLE_INTEL_SIMD
.endif

.include <bsd.port.mk>
