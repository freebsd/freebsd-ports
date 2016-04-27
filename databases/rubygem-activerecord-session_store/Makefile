# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	activerecord-session_store
PORTVERSION=	0.1.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action Dispatch session store backed by an Active Record class

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack4>=4.0.0:www/rubygem-actionpack4 \
		rubygem-activerecord4>=4.0.0:databases/rubygem-activerecord4 \
		rubygem-railties4>=4.0.0:www/rubygem-railties4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
