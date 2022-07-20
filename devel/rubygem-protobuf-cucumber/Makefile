PORTNAME=	protobuf-cucumber
PORTVERSION=	3.10.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Protocol Buffers serialization and RPC implementation for Cucumber

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport60>=3.2:devel/rubygem-activesupport60 \
		rubygem-middleware>=0:devel/rubygem-middleware \
		rubygem-thor>=0:devel/rubygem-thor \
		rubygem-thread_safe>=0:devel/rubygem-thread_safe

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/protoc-gen-ruby \
		bin/rpc_server

.include <bsd.port.mk>
