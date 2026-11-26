PORTNAME=	resque-scheduler
PORTVERSION=	5.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Light weight job scheduling on top of Resque
WWW=		https://github.com/resque/resque-scheduler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0.1<1:converters/rubygem-base64 \
		rubygem-logger>=0:devel/rubygem-logger \
		rubygem-mono_logger>=1.0<2:devel/rubygem-mono_logger \
		rubygem-redis>=4.0:databases/rubygem-redis \
		rubygem-resque>=2.7:devel/rubygem-resque \
		rubygem-rufus-scheduler>=3.9<4:devel/rubygem-rufus-scheduler

USES=		cpe gem

CPE_VENDOR=	resque-scheduler_project

NO_ARCH=	yes

PLIST_FILES=	bin/resque-scheduler

.include <bsd.port.mk>
