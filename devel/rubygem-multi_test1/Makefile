PORTNAME=	multi_test
PORTVERSION=	1.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Help control rogue test, unit, autorun requirements
WWW=		https://github.com/cucumber/multi_test

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem shebangfix

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.

SHEBANG_FILES=	test-all test-gemfile

.include <bsd.port.mk>
