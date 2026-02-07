PORTNAME=	activerecord-session_store
PORTVERSION=	2.2.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Dispatch session store backed by an Active Record class
WWW=		https://github.com/rails/activerecord-session_store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack80>=7.0:www/rubygem-actionpack80 \
		rubygem-activerecord80>=7.0:databases/rubygem-activerecord80 \
		rubygem-cgi>=0.3.6:www/rubygem-cgi \
		rubygem-rack>=2.0.8,3<4,3:www/rubygem-rack \
		rubygem-railties80>=7.0:www/rubygem-railties80

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
