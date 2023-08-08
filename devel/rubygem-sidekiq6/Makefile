PORTNAME=	sidekiq
PORTVERSION=	6.5.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	6

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby
WWW=		https://sidekiq.org/ \
		https://github.com/sidekiq/sidekiq

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-connection_pool>=2.2.5<3:net/rubygem-connection_pool \
		rubygem-rack22>=2.0,3<3,3:www/rubygem-rack22 \
		rubygem-redis4>=4.5.0<5:databases/rubygem-redis4

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	contribsys

PORTSCOUT=	limit:^6\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/sidekiq ${STAGEDIR}${PREFIX}/bin/sidekiqmon

.include <bsd.port.mk>
