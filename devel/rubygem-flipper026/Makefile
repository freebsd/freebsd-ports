PORTNAME=	flipper
PORTVERSION=	0.26.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	026

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Act of enabling/disabling features in your application
WWW=		https://github.com/jnunemaker/flipper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby<2:devel/rubygem-concurrent-ruby

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.26\.

.include <bsd.port.mk>
