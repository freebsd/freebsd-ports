PORTNAME=	delayed_job
PORTVERSION=	4.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Asynchronously executing longer tasks in the background
WWW=		https://github.com/collectiveidea/delayed_job

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-activesupport81>=3.0<9.0:devel/rubygem-activesupport81 \
		rubygem-benchmark>=0:benchmarks/rubygem-benchmark \
		rubygem-logger>=0:devel/rubygem-logger

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
