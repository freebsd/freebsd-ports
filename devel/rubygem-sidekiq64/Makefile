PORTNAME=	sidekiq
PORTVERSION=	6.4.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	64

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby
WWW=		https://sidekiq.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-connection_pool>=2.2.2:net/rubygem-connection_pool \
		rubygem-rack22>=2.0,3<3,3:www/rubygem-rack22 \
		rubygem-redis>=4.2.0:databases/rubygem-redis

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/sidekiq \
		bin/sidekiqmon

CPE_VENDOR=	contribsys

.include <bsd.port.mk>
