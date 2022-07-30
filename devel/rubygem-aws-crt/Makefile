PORTNAME=	aws-crt
PORTVERSION=	0.1.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS SDK for Ruby - Common Run Time

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	cmake:devel/cmake
RUN_DEPENDS=	rubygem-ffi>=0:devel/rubygem-ffi

USES=		gem python:env shebangfix
USE_RUBY=	yes

#NO_ARCH=	yes

SHEBANG_FILES=	aws-crt-ffi/crt/s2n/tests/litani/* \
		aws-crt-ffi/crt/s2n/tests/litani/*/* \
		aws-crt-ffi/crt/s2n/tests/litani/*/*/*
SHEBANG_GLOB=	*.py *.sh

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/tmp/
	${REINPLACE_CMD} -e '/${GEM_LIB_DIR}\/tmp\//d' ${TMPPLIST}

.include <bsd.port.mk>
