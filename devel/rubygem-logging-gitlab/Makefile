PORTNAME=	logging
PORTVERSION=	2.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Logging library based on Java's log4j #'
WWW=		https://github.com/TwP/logging

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-little-plugger>=1.1<2:devel/rubygem-little-plugger \
		rubygem-multi_json-gitlab>=1.14<2:devel/rubygem-multi_json-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
