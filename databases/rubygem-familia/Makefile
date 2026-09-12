PORTNAME=	familia
PORTVERSION=	2.12.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Organize and store ruby objects in Redis
WWW=		https://github.com/delano/familia

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.3<2:devel/rubygem-concurrent-ruby \
		rubygem-connection_pool>=2.4<4.0:net/rubygem-connection_pool \
		rubygem-json_schemer>=2.0<3:devel/rubygem-json_schemer \
		rubygem-logger>=1.7<2:devel/rubygem-logger \
		rubygem-oj>=3.16<4:devel/rubygem-oj \
		rubygem-redis>=5.0:databases/rubygem-redis \
		rubygem-uri-valkey>=1.4<2:net/rubygem-uri-valkey

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/irb

.include <bsd.port.mk>
