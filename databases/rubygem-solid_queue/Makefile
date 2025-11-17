PORTNAME=	solid_queue
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database-backed Active Job backend
WWW=		https://github.com/rails/solid_queue

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activejob81>=7.1:devel/rubygem-activejob81 \
		rubygem-activerecord81>=7.1:databases/rubygem-activerecord81 \
		rubygem-concurrent-ruby>=1.3.1:devel/rubygem-concurrent-ruby \
		rubygem-fugit>=1.11<2:devel/rubygem-fugit \
		rubygem-railties81>=7.1:www/rubygem-railties81 \
		rubygem-thor>=1.3.1:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
