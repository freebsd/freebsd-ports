PORTNAME=	openjph
PORTVERSION=	0.9.0
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source implementation of JPEG2000 Part-15

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake compiler:c++11-lang # pathfix

CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	aous72
GH_PROJECT=	OpenJPH
USE_GITHUB=	yes

.include <bsd.port.options.mk>

.if ${ARCH} != amd64
CMAKE_ON+=	OJPH_DISABLE_INTEL_SIMD
.endif

.include <bsd.port.mk>
