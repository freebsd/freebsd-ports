PORTNAME=	tarantool
PORTVERSION=	0.5.8
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tarantool KV-storage client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bin_utils>=0.0.3<0.1:devel/rubygem-bin_utils \
		rubygem-iproto>=0.3.17:net/rubygem-iproto \
		rubygem-murmurhash3>=0.1.1:devel/rubygem-murmurhash3 \
		rubygem-sumbur>=0.0.2:devel/rubygem-sumbur

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
