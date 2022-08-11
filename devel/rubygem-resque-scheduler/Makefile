PORTNAME=	resque-scheduler
PORTVERSION=	4.5.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Light weight job scheduling on top of Resque

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mono_logger>=1.0<2:devel/rubygem-mono_logger \
		rubygem-redis>=3.3:databases/rubygem-redis \
		rubygem-resque>=1.27:devel/rubygem-resque \
		rubygem-rufus-scheduler>=3.2<4:devel/rubygem-rufus-scheduler

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/resque-scheduler

.include <bsd.port.mk>
