PORTNAME=	activerecord-session_store
PORTVERSION=	2.3.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Dispatch session store backed by an Active Record class
WWW=		https://github.com/rails/activerecord-session_store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack81>=7.1:www/rubygem-actionpack81 \
		rubygem-activerecord81>=7.1:databases/rubygem-activerecord81 \
		rubygem-cgi>=0.3.6:www/rubygem-cgi \
		rubygem-rack>=2.0.8,3<4,3:www/rubygem-rack \
		rubygem-railties81>=7.1:www/rubygem-railties81

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_record_session_store

.include <bsd.port.mk>
