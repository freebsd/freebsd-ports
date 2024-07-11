PORTNAME=	aws-crt
PORTVERSION=	0.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS SDK for Ruby - Common Run Time
WWW=		https://github.com/awslabs/aws-crt-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libaws-crt-ffi.so:devel/aws-crt-ffi
RUN_DEPENDS=	rubygem-ffi>=0:devel/rubygem-ffi

USES=		gem

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/ext/compile.rb
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/aws-crt-ffi/

.include <bsd.port.mk>
