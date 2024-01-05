PORTNAME=	mashmap
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.3
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast approximate aligner for long DNA sequences
WWW=		https://github.com/marbl/MashMap

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	compilation fails: fatal error: unknown type name '__uint128_t'
BROKEN_powerpc=	compilation fails: fatal error: unknown type name '__uint128_t'

LIB_DEPENDS=	libgsl.so:math/gsl \
		libhts.so:biology/htslib

USES=		cmake compiler:c++17-lang localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	marbl
GH_PROJECT=	MashMap

CMAKE_ON=	USE_HTSLIB
CMAKE_OFF=	OPTIMIZE_FOR_NATIVE

OPTIONS_DEFINE=		NATIVE

NATIVE_CMAKE_BOOL=	OPTIMIZE_FOR_NATIVE

PLIST_FILES=	bin/mashmap \
		bin/mashmap-align

.include <bsd.port.mk>
