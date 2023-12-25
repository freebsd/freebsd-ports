PORTNAME=	resque-scheduler
PORTVERSION=	4.10.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Light weight job scheduling on top of Resque
WWW=		https://github.com/resque/resque-scheduler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mono_logger>=1.0<2:devel/rubygem-mono_logger \
		rubygem-redis>=3.3:databases/rubygem-redis \
		rubygem-resque>=1.27:devel/rubygem-resque \
		rubygem-rufus-scheduler>=3.2<4:devel/rubygem-rufus-scheduler

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/resque-scheduler

.include <bsd.port.mk>
