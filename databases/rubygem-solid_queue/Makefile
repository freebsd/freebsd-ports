PORTNAME=	solid_queue
PORTVERSION=	1.2.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database-backed Active Job backend
WWW=		https://github.com/rails/solid_queue

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activejob80>=7.1:devel/rubygem-activejob80 \
		rubygem-activerecord80>=7.1:databases/rubygem-activerecord80 \
		rubygem-concurrent-ruby>=1.3.1:devel/rubygem-concurrent-ruby \
		rubygem-fugit>=1.11.0<1.12:devel/rubygem-fugit \
		rubygem-railties80>=7.1:www/rubygem-railties80 \
		rubygem-thor>=1.3.1:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
