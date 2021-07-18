PORTNAME=	dmlc-core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-123
DISTVERSIONSUFFIX=	-gb3a4c71
CATEGORIES=	devel # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common library for scalable and portable distributed machine learning

LICENSE=	APACHE20

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

.include <bsd.port.mk>
