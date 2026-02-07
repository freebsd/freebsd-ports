PORTNAME=	dry-logic
PORTVERSION=	1.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Predicate logic with rule composition
WWW=		https://github.com/dry-rb/dry-logic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-dry-core-gitlab>=1.1<2:devel/rubygem-dry-core-gitlab \
		rubygem-zeitwerk>=2.6<3:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
