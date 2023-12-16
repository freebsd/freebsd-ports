PORTNAME=	aws-crt
PORTVERSION=	0.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS SDK for Ruby - Common Run Time
WWW=		https://github.com/awslabs/aws-crt-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	cmake:devel/cmake-core
RUN_DEPENDS=	rubygem-ffi>=0:devel/rubygem-ffi

USES=		gem python:env shebangfix

SHEBANG_GLOB=	*.py *.sh

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/tmp/
	${REINPLACE_CMD} -e '/${GEM_LIB_DIR}\/tmp\//d' ${TMPPLIST}

.include <bsd.port.mk>
