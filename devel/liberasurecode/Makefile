PORTNAME=	liberasurecode
PORTVERSION=	1.6.3
CATEGORIES=	devel

MAINTAINER=	fuz@fuz.su
COMMENT=	Unified Erasure Coding interface for common storage workloads

LICENSE=	BSD2CLAUSE

USES=		gmake pkgconfig autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	openstack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--disable-werror

TEST_TARGET=	test

CFLAGS_amd64=	-DINTEL_SSE2

# documentation file names vary depending on architecture
PORTDOCS=	html

OPTIONS_DEFINE=	DOCS SIMD
DOCS_CONFIGURE_ENABLE=	doxygen
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
SIMD_CONFIGURE_ENABLE=	mmi

.include <bsd.port.mk>
