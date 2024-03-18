PORTNAME=	with_advisory_lock
PORTVERSION=	5.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Advisory locking for ActiveRecord
WWW=		https://github.com/ClosureTree/with_advisory_lock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activerecord61>=6.1.5:databases/rubygem-activerecord61 \
		rubygem-zeitwerk>=2.6<3:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
