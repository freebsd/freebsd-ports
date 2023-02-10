PORTNAME=	dry-core
PORTVERSION=	1.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolset of small support modules used throughout the dry-rb ecosystem
WWW=		https://github.com/dry-rb/dry-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-zeitwerk>=2.6<3:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
