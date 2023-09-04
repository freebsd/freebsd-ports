PORTNAME=	activerecord-session_store
PORTVERSION=	2.1.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Dispatch session store backed by an Active Record class
WWW=		https://github.com/rails/activerecord-session_store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=6.1:www/rubygem-actionpack61 \
		rubygem-activerecord61>=6.1:databases/rubygem-activerecord61 \
		rubygem-cgi>=0.3.6:www/rubygem-cgi \
		rubygem-multi_json>=1.11.2<2:devel/rubygem-multi_json \
		rubygem-rack>=2.0.8,3<4,3:www/rubygem-rack \
		rubygem-railties61>=6.1:www/rubygem-railties61

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
